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
    CCircuit(QPoint depart, double angle, QString imgResource);
    const QPoint& getDepart(void);
    const QImage& getImage(void);
    double getAngle(void);
    void setMarkers(const QList<CMarker>& markers);
    static int normCoordonnees(int i);
private:
    QPoint depart;
    double angle;
    QImage image;
    QList<CMarker> markers;
};

#endif // CCIRCUIT_H
