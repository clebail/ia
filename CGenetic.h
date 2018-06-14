#ifndef CGENETIC_H
#define CGENETIC_H

#include <QThread>
#include <QPainter>
#include "CCircuit.h"
#include "CVoiture.h"
#include "CWCircuit.h"

#define TAILLE_POPULATION					100
#define NOMBRE_GENERATION					100
#define NB_CIRCUIT                          4

class CGenetic : public QThread {
    Q_OBJECT
private:
	CVoiture *population[TAILLE_POPULATION];
    CCircuit circuits[NB_CIRCUIT];
    CWCircuit *wCircuit;
    int currentCircuit;
    int nbAlive;
    bool populationInited;
	
	void initPopulation(void);
	void triPopulation(void);
    void croisePopuplation(void);
	void croiseIndividus(int i1, int i2, int ir, int seuil);
    double calculDistance(QPoint p, QPoint oppose, double angle);
    void setCircuit(int numCircuit);
public:
    CGenetic(CWCircuit *wCircuit);
    ~CGenetic(void);
    void run(void);
    void calculScores(void);
    void drawPopulation(QPainter *painter);
signals:
    void calculOk(CVoiture *);
    void circuitChange(CCircuit *circuit);
    void repaintRequested(void);
private slots:
    void onWCircuitDrawVoitures(QPainter *painter);
};

#endif //CGENETIC_H
