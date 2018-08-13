#include <QtDebug>
#include <string.h>
#include <math.h>
#include "CNeuroneVitesse.h"

CNeuroneVitesse::CNeuroneVitesse(int nbGene) : CNeurone(nbGene) {
}

void CNeuroneVitesse::from(const CNeuroneVitesse& n1, const CNeuroneVitesse& n2, int seuil) {
    CNeurone::from(n1, n2, seuil);

    if(rand() % 2 > 0.5) {
        this->coefVitesse = n1.coefVitesse;
    }else {
        this->coefVitesse = n2.coefVitesse;
    }
}

void CNeuroneVitesse::mute(int idx) {
    CNeurone::mute(idx);

    if(rand() % 2 > 0.5) {
        initCoefVitesse();
    }
}

void CNeuroneVitesse::initCoefVitesse(void) {
    coefVitesse = ((double)(rand() % 20 + 1)) * -1;
}

QString CNeuroneVitesse::serialize(void) {
    QString ret = "{ "+serializeSimples()+", \"coefVitesse\": "+QString::number(coefVitesse)+", "+serializeGenes()+ " }";

    return ret;
}

double CNeuroneVitesse::getCoefVitesse(void) {
    return coefVitesse;
}

void CNeuroneVitesse::setCoefVitesse(double coefVitesse) {
    this->coefVitesse = coefVitesse;
}
