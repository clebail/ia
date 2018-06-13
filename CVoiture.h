#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CCapteur.h"

#define NB_CAPTEUR              8
#define NB_GENE                 (NB_CAPTEUR * 2 + 2)
#define WIDTH                   19
#define HEIGHT                  11
#define HYPO                    10
#define ANGLE                   ((double)0.507)
#define PI                      ((double)3.14159265)
#define PI2                     (PI/2)
#define NB_ROUE                 4

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
    const QPoint& getPosition(void);
    double getCurrentAngle(void);
    QPoint * getPosRoue(void);
protected:
    CCapteur * getGene(int idx);
private:
    CCapteur poids[NB_GENE];
    QPoint position;
    QPoint posRoue[NB_ROUE];
    int score;
    double inputs[NB_CAPTEUR];
    double currentAngle;
    
    double getVitesse(void);
    double getAngle(void);
    double transfert(int idxFirstGene);
    void calculPosRoue(void);
    double calculDistance(QPoint p, QPoint oppose, double angle, QPainter *painter, QColor color);
};

#endif // CVOITURE_H
