#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CVehicule.h"
#include "CCapteur.h"
#include "CCircuit.h"
#include "CNeurone.h"
#include "CMarker.h"

#define NB_CAPTEUR              8

class CVoiture : public CVehicule {
public:
    CVoiture(void);
    ~CVoiture(void);
    void init(void);
    int getScore(void);
    void setInputs(double *inputs);
    void setStartInfo(QPoint position, double angle, const QList<CMarker> &markers);
    void setAlive(bool alive);
    bool isAlive(void);
    void from(CVoiture *v1, CVoiture *v2, int seuilVitesse, int seuilAngle);
    bool move(int timeElapsed, bool& gagne);
protected:
    CCapteur * getGene(int idx);

    double getVitesse(void);
    double getAngle(void);
    QBrush getBrush(void);
private:
    int score, oldScore;
    bool alive;
    CNeurone *nVitesse;
    CNeurone *nAngle;
    int currentMarkerIdx;
    QList<CMarker> markers;
    
    double normAngle(double angle);
};

#endif // CVOITURE_H
