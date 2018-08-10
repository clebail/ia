#include <math.h>
#include "CBaseVoiture.h"

#define NV				0
#define NAP				1
#define NAM				2

CBaseVoiture::CBaseVoiture(void) {
    int i;

    for(i=0;i<NB_NEURONE;i++) {
        ns[i] = new CNeurone(NB_CAPTEUR+(i == 0 ? 2 : 1));
    }
}

CBaseVoiture::~CBaseVoiture(void) {
    int i;

    for(i=0;i<NB_NEURONE;i++) {
        delete ns[i];
    }
}

void CBaseVoiture::setInputs(double *inputs) {
    int i;

    for(i=0;i<NB_NEURONE;i++) {
        ns[i]->setInputs(inputs);
    }
}

void CBaseVoiture::setStartInfo(QPoint position, double angle) {
    this->position = position;
    currentAngle = angle;
    alpha = 255;

    calculPosRoue();
}

void CBaseVoiture::setAlive(bool alive) {
    this->alive = alive;
    alpha = alive ? 255 : ALPHA;
}

bool CBaseVoiture::isAlive(void) {
    return alive;
}

double CBaseVoiture::getVitesse(void) {
    double a = ns[NV]->eval(0.01);
    double v = currentVitesse;

    if(a >= 0.5) {
        v+=STEP_V_P;
    }else {
        v-=STEP_V_M;
    }

    if(v < 0) v = 0;
    if(v > V_MAX) v = V_MAX;

    return v;
}

double CBaseVoiture::getAngle(void) {
    double vitesse = currentVitesse - 1;
    double a1 = ns[NAP]->eval(0.01);
    double a2 = ns[NAM]->eval(0.01);
    double eXp = exp((vitesse - V_MAX/2.0) * (1.0 / V_MAX * 10.0));
    double coef = (-eXp / (eXp + 1) + 1) * PERTE_ANGLE_MAX + 1 - PERTE_ANGLE_MAX;
    double angle = currentAngle + coef * A_MAX * (a1 >= 0.5 && a2 < 0.5 ? 1 : a2 >= 0.5 && a1 < 0.5 ? -1 : 0);

    return angle;
}
