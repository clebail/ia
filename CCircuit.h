#ifndef CCIRCUIT_H
#define CCIRCUIT_H

#include <QPoint>
#include <QString>
#include <QImage>
#include <QList>
#include "CMarker.h"

class CCircuit {
public:
    CCircuit(void);
    CCircuit(QPoint depart, double angle, QString imgResource, QPoint posTime = QPoint());
    const QPoint& getDepart(void);
    const QImage& getImage(void);
    double getAngle(void);
    void setMarkers(const QList<CMarker>& markers);
    const QList<CMarker>& getMarkers(void);
	void normCoordonnees(int& x, int& y);
	const QPoint& getPosTime(void);
private:
    QPoint depart, posTime;
    double angle;
    QImage image;
    QList<CMarker> markers;
};

#endif // CCIRCUIT_H
