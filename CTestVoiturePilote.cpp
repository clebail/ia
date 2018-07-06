#include "CTestVoiturePilote.h"
#include "CDistanceHelper.h"

CTestVoiturePilote::CTestVoiturePilote(CCircuit *circuit, QPoint position, double angle) {
    this->currentAngle = angle;
    this->position = position;

    this->angle = 0.0;
    this->vitesse = 0.0;

    this->circuit = circuit;

    calculPosRoue();
}

void CTestVoiturePilote::incAngle(double inc) {
    angle = inc;
}

void CTestVoiturePilote::incVitesse(double inc) {
    vitesse += inc;
}

void CTestVoiturePilote::draw(QPainter *painter) {
    QPointF result;

    CVehicule::draw(painter);

    painter->setPen(QPen(Qt::yellow));

    CDistanceHelper::calculDistance(circuit, posRoue[0], posRoue[2], result, currentAngle);
    painter->drawLine(posRoue[0], result);
    CDistanceHelper::calculDistance(circuit, posRoue[0], posRoue[1], result, currentAngle + PI2);
    painter->drawLine(posRoue[0], result);
    CDistanceHelper::calculDistance(circuit, posRoue[0], posRoue[3], result, currentAngle + PI / 4);
    painter->drawLine(posRoue[0], result);
    CDistanceHelper::calculDistance(circuit, posRoue[1], posRoue[3], result, currentAngle);
    painter->drawLine(posRoue[1], result);
    CDistanceHelper::calculDistance(circuit, posRoue[1], posRoue[0], result, currentAngle + 3 * PI2);
    painter->drawLine(posRoue[1], result);
    CDistanceHelper::calculDistance(circuit, posRoue[1], posRoue[2], result, currentAngle + 7 * PI / 4);
    painter->drawLine(posRoue[1], result);

    painter->setPen(QPen(Qt::red));

    CDistanceHelper::calculDistance(circuit, posRoue[2], posRoue[3], result, currentAngle + PI2);
    painter->drawLine(posRoue[2], result);
    CDistanceHelper::calculDistance(circuit, posRoue[3], posRoue[2], result, currentAngle + 3 * PI2);
    painter->drawLine(posRoue[3], result);
}

double CTestVoiturePilote::getVitesse(void) {
    return vitesse;
}

double CTestVoiturePilote::getAngle(void) {
    double toReturn = angle;

    angle = 0.0;

    return toReturn;
}
