#ifndef CDISTANCEHELPER_H
#define CDISTANCEHELPER_H

#include <QPointF>
#include "CCircuit.h"

class CDistanceHelper {
public:
    static double calculDistance(CCircuit *circuit, QPointF p, QPointF oppose, QPointF& result, double angle);
    static bool isDehors(CCircuit *circuit, const QPointF& p);
private:
    static double normAngle(double angle);
};

#endif // CDISTANCEHELPER_H
