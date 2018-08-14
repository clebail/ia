#include <math.h>
#include "CBaseVoiture.h"

CBaseVoiture::CBaseVoiture(void) {
    ns[NV] = new CNeuroneVitesse(NB_CAPTEUR+2);
    ns[NAP] = new CNeurone(NB_CAPTEUR+1);
    ns[NAM] = new CNeurone(NB_CAPTEUR+1);
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
    nbAP = nbAM = 0;

    calculPosRoue();
}

void CBaseVoiture::setAlive(bool alive) {
    this->alive = alive;
    alpha = alive ? 255 : ALPHA;
}

bool CBaseVoiture::isAlive(void) {
    return alive;
}

double CBaseVoiture::getCoefVitesse(void) {
    return static_cast<CNeuroneVitesse *>(ns[NV])->getCoefVitesse();
}

int CBaseVoiture::getNbChangementDirection(void) {
    return nbAP + nbAM;
}

double CBaseVoiture::getVitesse(void) {
    double a = ns[NV]->eval(PENTE_NEURONE);
    double v = currentVitesse;

    if(a >= ns[NV]->getSeuil()) {
        v+=STEP_V_P;
    }else {
        v-=STEP_V_M;
    }

    if(v < 0) v = 0;
    if(v > V_MAX) v = V_MAX;

    return v;
}

double CBaseVoiture::getAngle(void) {
    double vitesse = currentVitesse;
    double a1 = ns[NAP]->eval(PENTE_NEURONE);
    double a2 = ns[NAM]->eval(PENTE_NEURONE);
    double eXp = exp((vitesse - V_MAX/2.0) * (1.0 / V_MAX * 10.0));
    double coef = (-eXp / (eXp + 1) + 1) * PERTE_ANGLE_MAX + 1 - PERTE_ANGLE_MAX;
    double angle;

    if(a1 >= ns[NAP]->getSeuil() && a2 < ns[NAM]->getSeuil()) {
        nbAP++;
        angle = currentAngle + coef * A_MAX;
    } else if(a2 >= ns[NAM]->getSeuil() && a1 < ns[NAP]->getSeuil()) {
        nbAM++;
        angle = currentAngle - coef * A_MAX;
    } else {
        angle = currentAngle;
    }

    return angle;
}
