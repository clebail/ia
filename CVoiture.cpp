#include <QtDebug>
#include <iostream>
#include <math.h>
#include "commun.h"
#include "CVoiture.h"

CVoiture::CVoiture(void) : CVehicule() {
    score = 0;
    currentAngle = 0;
    currentVitesse = 0;

    nVitesse = new CNeurone(NB_CAPTEUR+1);
    nAngle = new CNeurone(NB_CAPTEUR+1);
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
    score = 0;
    currentMarkerIdx = 0;

    calculPosRoue();
}

void CVoiture::setAlive(bool alive) {
    this->alive = alive;
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
}

bool CVoiture::move(int timeElapsed) {
    CVehicule::move(timeElapsed);

    if(markers.at(currentMarkerIdx).isDepasse(position)) {
        score = (++currentMarkerIdx) * 100 / markers.size();

        if(score == 100) {
            score += (MAX_TIME - timeElapsed) / 1000;
            alive = false;

            return false;
        }
    }else if(currentMarkerIdx > 0) {
        if(markers.at(currentMarkerIdx - 1).isDepasseInv(position)) {
            alive = false;

            return false;
        }
    }else if(currentMarkerIdx == 0) {
        if(markers.at(markers.size() - 1).isDepasseInv(position)) {
            score = 0;
            alive = false;

            return false;
        }
    }

    return true;
}

double CVoiture::getVitesse(void) {
    return nVitesse->eval(100) * 20;
}

double CVoiture::getAngle(void) {
    double angle = nAngle->eval(100) * 3 * PI2 - 3 * PI / 4;

    return angle;
}

double CVoiture::normAngle(double angle) {
    while(angle < 0) {
        angle += PI;
    }
    while(angle > 2 * PI) {
        angle -= PI;
    }

    return angle;
}
