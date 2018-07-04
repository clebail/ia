#include "CTestVoitureAngle.h"

CTestVoitureAngle::CTestVoitureAngle(QPoint position, double angle) {
    this->currentAngle = angle;
    this->position = position;

    calculPosRoue();
}

double CTestVoitureAngle::getVitesse(void) {
    return 2.0;
}

double CTestVoitureAngle::getAngle(void) {
    return 0.0;
}
