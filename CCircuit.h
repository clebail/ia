#ifndef CCIRCUIT_H
#define CCIRCUIT_H

#include <QPoint>
#include <QString>
#include <QImage>
#include <QList>
#include "CDroite.h"

class CCircuit {
public:
    CCircuit(void);
    CCircuit(QPoint depart, double angle, QString imgResource, QPoint posTime = QPoint());
    const QPoint& getDepart(void);
    const QImage& getImage(void);
    double getAngle(void);
    void setMarkers(const QList<CDroite *>& markers);
    const QList<CDroite *>& getMarkers(void);
    void normCoordonnees(QPoint& p);
	void normCoordonnees(int& x, int& y);
	const QPoint& getPosTime(void);
    void setNbGagne(int nbGagne);
    int getNbGagne(void);
private:
    QPoint depart, posTime;
    double angle;
    QImage image;
    QList<CDroite *> markers;
    int nbGagne;
};

#endif // CCIRCUIT_H
