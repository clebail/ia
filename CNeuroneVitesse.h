#ifndef CNEURONEVITESSE_H
#define CNEURONEVITESSE_H

#include "CNeurone.h"

class CNeuroneVitesse : public CNeurone {
public:
    CNeuroneVitesse(int nbGene);
    virtual void from(const CNeuroneVitesse &n1, const CNeuroneVitesse &n2, int seuil);
    virtual void mute(int idx);
    void initCoefVitesse(void);
    virtual QString serialize(void);
    double getCoefVitesse(void);
    void setCoefVitesse(double coefVitesse);
private:
    double coefVitesse;
};

#endif // CNEURONEVITESSE_H
