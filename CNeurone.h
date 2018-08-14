#ifndef CNEURONE_H
#define CNEURONE_H

#include <json.h>
#include "CCapteur.h"

class CNeurone {
public:
    CNeurone(int nbGene);
    virtual ~CNeurone(void);
    void setInputs(double *inputs);
    double eval(double a);
    int getNbGene(void);
    virtual void from(const CNeurone& n1, const CNeurone& n2, int seuil);
    virtual void mute(int idx);
    void initGenes(void);
    void initSeuil(void);
    virtual QString serialize(void);
    void setJSonGenes(json_object *jObj);
    double getSeuil(void);
    void setSeuil(double seuil);
protected:
    QString serializeSimples(void);
    QString serializeGenes(void);
private:
    int nbGene;
    CCapteur *genes;
    double *inputs;
    double seuil;
    double coefVitesse;
};

#endif // CNEURONE_H
