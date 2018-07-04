#ifndef CVEHICULE_H
#define CVEHICULE_H

#include <QPainter>
#include "commun.h"

#define WIDTH                   19
#define HEIGHT                  11
#define NB_ROUE                 4
#define HYPO                    10
#define ANGLE                   ((double)0.507)

class CVehicule {
public:
    virtual ~CVehicule(void);
    void draw(QPainter *painter);
    virtual bool move(int timeElapsed);
    const QPoint& getPosition(void);
    double getCurrentAngle(void);
    double getCurrentVitesse(void);
    QPoint * getPosRoue(void);
protected:
    QPoint position;
    QPoint posRoue[NB_ROUE];
    double currentAngle;
    double currentVitesse;

    virtual double getVitesse(void) = 0;
    virtual double getAngle(void) = 0;
    void calculPosRoue(void);
};

#endif // CVEHICULE_H
