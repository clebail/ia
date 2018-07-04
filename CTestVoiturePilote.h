#ifndef CTESTVOITUREPILOTE_H
#define CTESTVOITUREPILOTE_H

#include "CVehicule.h"

class CTestVoiturePilote : public CVehicule {
public:
    CTestVoiturePilote(QPoint position, double angle);
    void incAngle(double inc);
    void incVitesse(double inc);
protected:
    double getVitesse(void);
    double getAngle(void);
private:
    double angle;
    double vitesse;
};

#endif // CTESTVOITUREPILOTE_H
