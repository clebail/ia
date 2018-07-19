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

    nVitesse = new CNeurone(NB_CAPTEUR+1);
    nAngle = new CNeurone(NB_CAPTEUR+1);
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
    nAngle->from(*v1->nAngle, *v2->nVitesse, seuilAngle);

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
    return nVitesse->eval(100) * 20;
}

double CVoiture::getAngle(void) {
    double angle = nAngle->eval(100) * 3 * PI2 - 3 * PI / 4;

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

