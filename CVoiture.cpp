#include <QtDebug>
#include <iostream>
#include <math.h>
#include <string.h>
#include "commun.h"
#include "CVoiture.h"

#define MAX_SCORE       300
#define V_MAX			20.0
#define A_MAX			(PI / 8.0)

CVoiture::CVoiture(void) : CVehicule() {
    score = oldScore = 0;
    currentAngle = 0;
    currentVitesse = 0;

    nVitesse = new CNeurone(NB_CAPTEUR+2);
    nAngle = new CNeurone(NB_CAPTEUR+2);
    champion = false;

    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

CVoiture::~CVoiture(void) {
    delete nVitesse;
    delete nAngle;
}

void CVoiture::init(void) {
    nVitesse->init();
    nAngle->init();
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::setInputs(double *inputs) {
    nVitesse->setInputs(inputs);
    nAngle->setInputs(inputs);
}

void CVoiture::setStartInfo(QPoint position, double angle, const QList<CMarker>& markers) {
    this->position = position;
    this->markers = markers;
    currentAngle = angle;
    oldScore = score;
    score = 0;
    currentMarkerIdx = 0;
    alpha = 255;

    calculPosRoue();
}

void CVoiture::setAlive(bool alive) {
    this->alive = alive;
    alpha = alive ? 255 : ALPHA;
}

bool CVoiture::isAlive(void) {
    return alive;
}

void CVoiture::from(CVoiture *v1, CVoiture *v2, int seuilVitesse, int seuilAngle) {
    nVitesse->from(*v1->nVitesse, *v2->nVitesse, seuilVitesse);
    nAngle->from(*v1->nAngle, *v2->nAngle, seuilAngle);

    if(rand() % 10 < 8) {
        nVitesse->mute(rand() % nVitesse->getNbGene());
    }

    if(rand() % 10 < 8) {
        nAngle->mute(rand() % nAngle->getNbGene());
    }
    
    score = 0;
    alpha = 255;
    champion = false;
    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

bool CVoiture::move(int timeElapsed, bool &gagne) {
    gagne = false;
    int offset = champion ? 2000 : oldScore / 5;
	
	if(alive && CVehicule::move(timeElapsed, gagne)) {
        if(markers.at(currentMarkerIdx).isDepasse(position)) {
            score = (++currentMarkerIdx) * 100 / markers.size();

            if(score == 100) {
                score += (MAX_TIME - timeElapsed) / 100;
                alive = false;
                gagne = true;
                alpha = ALPHA;
                score += offset;

                return false;
            }
        }else if(currentMarkerIdx > 0) {
            if(markers.at(currentMarkerIdx - 1).isDepasseInv(position)) {
                //score = 0;
                alive = false;
                alpha = ALPHA;

                return false;
            }
        }else if(currentMarkerIdx == 0) {
            if(markers.at(markers.size() - 1).isDepasseInv(position)) {
                score = 0;
                alive = false;
                alpha = ALPHA;

                return false;
            }
        }

        return true;
    }

    alive = false;
	alpha = ALPHA;
    
    return false;
}

void CVoiture::setVictoire(int numCircuit, bool victoire) {
    victoires[numCircuit] = victoire;
}

void CVoiture::setChampion(void) {
    champion = true;
}

bool CVoiture::isVainqueur(int numCircuit) {
    return victoires[numCircuit];
}

double CVoiture::getVitesse(void) {
	double a = nVitesse->eval(0.005);
	double v = currentVitesse;
	
	if(a >= 0.66 && v < V_MAX) {
		v++;
	} else if(a <= 0.33 && v > 0) {
		v--;
	}
	
	return v;
}

double CVoiture::getAngle(void) {
	double vitesse = currentVitesse - 1;
	double a = nAngle->eval(0.005);
	double eXp = exp((vitesse - V_MAX/2.0) * (1.0 / V_MAX * 10.0));
	double coef = (-eXp / (eXp + 1) + 1) * 0.2 + 0.8;
	double angle = coef * A_MAX * (a >= 0.66 ? 1 : a <= 0.33 ? -1 : 0);
	
	//qDebug() << "v: " << vitesse << " coef: " << coef;

    return angle;
}

QBrush CVoiture::getBrush(void) {
    if(champion) {
        return QBrush(QColor(255, 255, 255, alpha));
    }

    int r = qMax(0, qMin(255, oldScore * 50 / MAX_SCORE));
    int v = qMax(0, qMin(255, oldScore * 100 / MAX_SCORE));
    int b = qMin(255, qMax(0, 255 - MAX_SCORE + oldScore));

    return QBrush(QColor(r, v, b, alpha));
}

