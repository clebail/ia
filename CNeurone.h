#ifndef CNEURONE_H
#define CNEURONE_H

#include "CCapteur.h"

class CNeurone {
public:
    CNeurone(int nbGene);
    ~CNeurone(void);
    void setInputs(double *inputs);
    double eval(double a);
    int getNbGene(void);
    void from(const CNeurone& n1, const CNeurone& n2, int seuil);
    void mute(int idx);
    void init(void);
private:
    int nbGene;
    CCapteur *genes;
    double *inputs;
};

#endif // CNEURONE_H
