#ifndef CVOITURE_H
#define CVOITURE_H

#include <QPainter>
#include "CBaseVoiture.h"
#include "CCapteur.h"
#include "CCircuit.h"
#include "CDroite.h"

class CVoiture : public CBaseVoiture {
public:
    CVoiture(void);
    void setStartInfo(QPoint position, double angle, const QList<CDroite *>& markers, int idx);
    void init(void);
    int getScore(void);
    void from(CVoiture *v1, CVoiture *v2);
    bool move(int timeElapsed, bool& gagne);
    void setVictoire(int numCircuit, bool victoire);
    void setChampion(bool champion);
    bool isVainqueur(int numCircuit);
	QString serialize(void);
    double getVMax(void);
protected:
    CCapteur * getGene(int idx);

    double getVitesse(void);
    QBrush getBrush(void);
private:
    int score, oldScore;
    int currentMarkerIdx;
    QList<CDroite *> markers;
    bool victoires[NB_CIRCUIT];
    bool champion;
    int idx;
    double vMax;
    bool asColor;
    QColor color;

    double initSeuil(void);
};

#endif // CVOITURE_H
