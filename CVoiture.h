#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CCapteur.h"

#define NB_CAPTEUR              8
#define NB_GENE                 (NB_CAPTEUR * 2 + 2)

class CVoiture {
public:
    CVoiture(void);
    void init(void);
    int getScore(void);
    void mute(int idxGene);
    void from(CVoiture *i1, CVoiture *i2, int seuil);
    void draw(QPainter *painter);
    void setInputs(double *inputs);
    void move(void);
    void setPosition(QPoint position);
protected:
    CCapteur * getGene(int idx);
private:
    CCapteur poids[NB_GENE];
    QPoint position;
    int score;
    double inputs[NB_CAPTEUR];
    
    double getVitesse(void);
    double getAngle(void);
    double transfert(int idxFirstGene);
};

#endif // CVOITURE_H
