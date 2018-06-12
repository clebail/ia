#ifndef CVOITURE_H
#define CVOITURE_H

#include "CIndividu.h"
#include "CCapteur.h"

#define NB_GENE                 7

class CVoiture : public CIndividu {
public:
    void init(void);
    int getScore(void);
    void mute(int idxGene);
    void from(CIndividu *i1, CIndividu *i2, int seuil);
    void draw(QPainter *painter);
protected:
    CGene * getGene(int idx);
private:
    CCapteur capteurs[NB_GENE];
    QPoint position;
    double angle;
};

#endif // CVOITURE_H
