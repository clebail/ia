#include <string.h>
#include <math.h>
#include "CNeurone.h"

CNeurone::CNeurone(int nbGene) {
    this->nbGene = nbGene;
    genes = new CCapteur[nbGene];
    inputs = new double[nbGene-1];
}

CNeurone::~CNeurone(void) {
    delete[] genes;
    delete[] inputs;
}

void CNeurone::setInputs(double *inputs) {
    memcpy(this->inputs, inputs, (nbGene-1)*sizeof(double));
}

double CNeurone::eval(double a) {
    double sigma = genes[0].getValue();
    int i;

    for(i=1;i<nbGene;i++) {
        sigma += inputs[i-1] * genes[i].getValue();
    }

    return 1 / (1 + exp(-sigma / a));
}

int CNeurone::getNbGene(void) {
    return nbGene;
}

void CNeurone::from(const CNeurone& n1, const CNeurone& n2, int seuil) {
    int i;
    CNeurone *src = (CNeurone *)&n1;

    for(i=0;i<nbGene;i++) {
        if(i == seuil) {
            src = (CNeurone *)&n2;
        }

        genes[i].from(&src->genes[i]);
    }
}

void CNeurone::mute(int idx) {
    if(idx >= 0 && idx < nbGene) {
        genes[idx].init();
    }
}

void CNeurone::init(void) {
    int i;

    for(i=0;i<nbGene;i++) {
        genes[i].init();
    }
}
