#ifndef CGENETIC_H
#define CGENETIC_H

#include <QObject>
#include <QPainter>
#include "CCircuit.h"
#include "CVoiture.h"

#define TAILLE_POPULATION					10
#define NOMBRE_GENERATION					100

class CGenetic : public QObject {
    Q_OBJECT
private:
	CVoiture *population[TAILLE_POPULATION];
    CCircuit circuit;
	
	void initPopulation(void);
	void triPopulation(void);
    void croisePopuplation(void);
	void croiseIndividus(int i1, int i2, int ir, int seuil);
public:
	CVoiture * process(void);
    void drawIndividu(int idx, QPainter *painter);
    void setCircuit(CCircuit circuit);
    void calculScores(void);
signals:
    void readyToCalculScore(void);
};

#endif //CGENETIC_H
