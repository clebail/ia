#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CCapteur.h"
#include "CCircuit.h"
#include "CNeurone.h"

#define NB_CAPTEUR              8
#define WIDTH                   19
#define HEIGHT                  11
#define HYPO                    10
#define ANGLE                   ((double)0.507)
#define NB_ROUE                 4

class CVoiture {
public:
    CVoiture(void);
    void init(void);
    int getScore(void);
    void draw(QPainter *painter);
    void setInputs(double *inputs);
    void move(void);
	double realMove(double vitesse, double angle);
    void setStartInfo(QPoint position, double angle);
    const QPoint& getPosition(void);
    double getCurrentAngle(void);
    QPoint * getPosRoue(void);
    void setAlive(bool alive);
    bool isAlive(void);
    void from(CVoiture *v1, CVoiture *v2, int seuilVitesse, int seuilAngle);
protected:
    CCapteur * getGene(int idx);
private:
    QPoint position;
    QPoint posRoue[NB_ROUE];
    int score;
    double currentAngle;
    bool alive;
    CNeurone nVitesse;
    CNeurone nAngle;
    
    double getVitesse(void);
    double getAngle(void);
    void calculPosRoue(void);
    double calculDistance(QPoint p, QPoint oppose, double angle, QPainter *painter, QColor color);
    double normAngle(double angle);
};

#endif // CVOITURE_H
