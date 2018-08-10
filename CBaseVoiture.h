#ifndef CBASEVOITURE_H
#define CBASEVOITURE_H

#include "CVehicule.h"
#include "CNeurone.h"

#define NB_CAPTEUR              8
#define NB_NEURONE				3

class CBaseVoiture : public CVehicule {
public:
    CBaseVoiture(void);
    ~CBaseVoiture(void);
    void setInputs(double *inputs);
    virtual void setStartInfo(QPoint position, double angle);
    void setAlive(bool alive);
    bool isAlive(void);
protected:
    CNeurone *ns[NB_NEURONE];
    bool alive;

    double getVitesse(void);
    double getAngle(void);
};

#endif // CBASEVOITURE_H
