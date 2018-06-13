#ifndef CGENETIC_H
#define CGENETIC_H

#include <QObject>
#include <QPainter>
#include "CCircuit.h"
#include "CVoiture.h"

#define TAILLE_POPULATION					1
#define NOMBRE_GENERATION					1

class CGenetic : public QObject {
    Q_OBJECT
private:
	CVoiture *population[TAILLE_POPULATION];
    CCircuit circuit;
	
	void initPopulation(void);
	void triPopulation(void);
    void croisePopuplation(void);
	void croiseIndividus(int i1, int i2, int ir, int seuil);
    double calculDistance(QPoint p, double angle, int sens);
public:
	CVoiture * process(void);
    void setCircuit(CCircuit circuit);
    void calculScores(void);
    void drawPopulation(QPainter *painter);
signals:
    void readyToCalculScore(bool changeCircuit);
};

#endif //CGENETIC_H
