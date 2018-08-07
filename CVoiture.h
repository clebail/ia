#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CVehicule.h"
#include "CCapteur.h"
#include "CCircuit.h"
#include "CNeurone.h"
#include "CDroite.h"

#define NB_CAPTEUR              8
#define NB_NEURONE				3

class CVoiture : public CVehicule {
public:
    CVoiture(void);
    ~CVoiture(void);
    void init(void);
    int getScore(void);
    void setInputs(double *inputs);
    void setStartInfo(QPoint position, double angle, const QList<CDroite *> &markers, int idx);
    void setAlive(bool alive);
    bool isAlive(void);
    void from(CVoiture *v1, CVoiture *v2);
    bool move(int timeElapsed, bool& gagne);
    void setVictoire(int numCircuit, bool victoire);
    void setChampion(bool champion);
    bool isVainqueur(int numCircuit);
	QString serialize(void);
protected:
    CCapteur * getGene(int idx);

    double getVitesse(void);
    double getAngle(void);
    QBrush getBrush(void);
private:
    int score, oldScore;
    bool alive;
    CNeurone *ns[NB_NEURONE];
    int currentMarkerIdx;
    QList<CDroite *> markers;
    bool victoires[NB_CIRCUIT];
    bool champion;
    int idx;
};

#endif // CVOITURE_H
