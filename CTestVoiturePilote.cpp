#include "CTestVoiturePilote.h"

CTestVoiturePilote::CTestVoiturePilote(QPoint position, double angle) {
    this->currentAngle = angle;
    this->position = position;

    this->angle = 0.0;
    this->vitesse = 0.0;

    calculPosRoue();
}

void CTestVoiturePilote::incAngle(double inc) {
    angle = inc;
}

void CTestVoiturePilote::incVitesse(double inc) {
    vitesse += inc;
}

double CTestVoiturePilote::getVitesse(void) {
    return vitesse;
}

double CTestVoiturePilote::getAngle(void) {
    double toReturn = angle;

    angle = 0.0;

    return toReturn;
}
