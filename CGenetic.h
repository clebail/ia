#ifndef CGENETIC_H
#define CGENETIC_H

#include <QThread>
#include <QPainter>
#include "CCircuit.h"
#include "CVoiture.h"
#include "CWCircuit.h"
#include "CSetup.h"
#include "commun.h"

#define NOMBRE_GENERATION					200000

class CGenetic : public QThread {
    Q_OBJECT
private:
	CVoiture *population[TAILLE_POPULATION];
    CCircuit circuits[NB_CIRCUIT];
    CWCircuit *wCircuit;
    int currentCircuit;
    int nbAlive;
    bool populationInited;
    CSetup setup;
    QList<CVoiture *> vainqueurs;
	
    void initPopulation(int from = 0, int to = TAILLE_POPULATION - 1);
	void triPopulation(void);
    void croisePopuplation(void);
    void croiseIndividus(int i1, int i2, int ir, int seuilVitesse, int seuilAngle);
    void setCircuit(int numCircuit);
    bool calculVainqueurs(void);
public:
    CGenetic(CWCircuit *wCircuit, const CSetup& setup);
    ~CGenetic(void);
    void run(void);
    void calculScores(void);
    void drawPopulation(QPainter *painter);
	const QList<CVoiture *>& getVainqueurs(void);
signals:
    void calculOk(void);
    void circuitChange(CCircuit *circuit);
    void repaintRequested(void);
private slots:
    void onWCircuitDrawVoitures(QPainter *painter);
};

#endif //CGENETIC_H
