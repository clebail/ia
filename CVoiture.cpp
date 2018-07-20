#include <QtDebug>
#include <iostream>
#include <math.h>
#include <string.h>
#include "commun.h"
#include "CVoiture.h"

#define MAX_SCORE       800

CVoiture::CVoiture(void) : CVehicule() {
    score = oldScore = 0;
    currentAngle = 0;
    currentVitesse = 0;

    nVitessePlus = new CNeurone(NB_CAPTEUR+2);
	nVitesseMoins = new CNeurone(NB_CAPTEUR+2);
    nAnglePlus = new CNeurone(NB_CAPTEUR+2);
	nAngleMoins = new CNeurone(NB_CAPTEUR+2);
    champion = false;

    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

CVoiture::~CVoiture(void) {
    delete nVitessePlus;
	delete nVitesseMoins;
    delete nAnglePlus;
	delete nAngleMoins;
}

void CVoiture::init(void) {
    nVitessePlus->init();
	nVitesseMoins->init();
    nAnglePlus->init();
	nAngleMoins->init();
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::setInputs(double *inputs) {
    nVitessePlus->setInputs(inputs);
	nVitesseMoins->setInputs(inputs);
    nAnglePlus->setInputs(inputs);
	nAngleMoins->setInputs(inputs);
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
    nVitessePlus->from(*v1->nVitessePlus, *v2->nVitessePlus, seuilVitesse);
	nVitesseMoins->from(*v1->nVitesseMoins, *v2->nVitesseMoins, seuilVitesse);
    nAnglePlus->from(*v1->nAnglePlus, *v2->nAnglePlus, seuilAngle);
	nAngleMoins->from(*v1->nAngleMoins, *v2->nAngleMoins, seuilAngle);

    if(rand() % 10 < 8) {
        nVitessePlus->mute(rand() % nVitessePlus->getNbGene());
    }
    
    if(rand() % 10 < 8) {
        nVitesseMoins->mute(rand() % nVitesseMoins->getNbGene());
    }

    if(rand() % 10 < 8) {
        nAnglePlus->mute(rand() % nAnglePlus->getNbGene());
    }
    
    if(rand() % 10 < 8) {
        nAngleMoins->mute(rand() % nAngleMoins->getNbGene());
    }
    
    score = 0;
    alpha = 255;
    champion = false;
    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

bool CVoiture::move(int timeElapsed, bool &gagne) {
    gagne = false;
    int offset = champion ? 2000 : oldScore / 5;

    CVehicule::move(timeElapsed, gagne);

    if(alive) {
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
                score = 0;
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
	double vitesse = currentVitesse;
	
	vitesse += nVitessePlus->eval(100) > 0.5 ? 1 : 0;
	vitesse -= nVitesseMoins->eval(100) > 0.5 ? 1 : 0;
	
	if(vitesse > 100) vitesse = 100;
	if(vitesse < 0) vitesse = 0;
	
    return vitesse;
}

double CVoiture::getAngle(void) {
	double vitesse = getVitesse();
	double eXp = exp(0.12 * (vitesse - 50)); 
	double step = eXp / (eXp + 1) * PI / 4;
	double angle = currentAngle;
	
	angle += (nAnglePlus->eval(100) > 0.5 ? 1 : 0) * step;
	angle -= (nAngleMoins->eval(100) > 0.5 ? 1 : 0) * step;

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

