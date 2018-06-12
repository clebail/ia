#include <math.h>
#include "CVoiture.h"

CVoiture::CVoiture(void) {
    score = 0;
}

void CVoiture::init(void) {
    int i;

    for(i=0;i<NB_GENE;i++) {
        poids[i].init();
    }
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::mute(int idxGene) {
     poids[idxGene].init();
}

void CVoiture::from(CVoiture *i1, CVoiture *i2, int seuil) {
    int i;
    CVoiture *src = i1;

    for(i=0;i<NB_GENE;i++) {
        if(i == seuil) {
            src = i2;
        }

        poids[i].from(src->getGene(i));
    }
}

void CVoiture::draw(QPainter *painter) {
    QRect rect;
    
    rect.setWidth(10);
    rect.setHeight(6);
    rect.setX(position.x() - 5);
    rect.setY(position.y() - 3);
    
    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawRect(rect);
}

void CVoiture::setInputs(double *inputs) {
    memcpy(this->inputs, inputs, NB_CAPTEUR * sizeof(double));
}

void CVoiture::move(void) {
    double vitesse = getVitesse();
    double angle = getAngle();
}

void CVoiture::setPosition(QPoint position) {
    this->position = position;
}

CCapteur * CVoiture::getGene(int idx) {
    return &poids[idx];
}

double CVoiture::getVitesse(void) {
    return transfert(0);
}

double CVoiture::getAngle(void) {
    return transfert(NB_CAPTEUR + 1);
}

double CVoiture::transfert(int idxFirstGene) {
    double sigma = poids[idxFirstGene++].getValue();
    int i;
    
    for(i=0;i<NB_CAPTEUR;i++,idxFirstGene++) {
        sigma += inputs[i] * poids[idxFirstGene].getValue();
    }
    
    return 1 / (1 + exp(-sigma));
}
