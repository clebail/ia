#ifndef CTESTVOITUREPILOTE_H
#define CTESTVOITUREPILOTE_H

#include "CVehicule.h"
#include "CCircuit.h"

class CTestVoiturePilote : public CVehicule {
public:
    CTestVoiturePilote(CCircuit *circuit, QPoint position, double angle, bool showCapteurs);
    void incAngle(double inc);
    void incVitesse(double inc);
    void draw(QPainter *painter, double dx, double dy);
protected:
    double getVitesse(void);
    double getAngle(void);
private:
    double angle;
    double vitesse;
    CCircuit *circuit;
    bool showCapteurs;
};

#endif // CTESTVOITUREPILOTE_H
