#include "CCircuit.h"

CCircuit::CCircuit(void) {}

CCircuit::CCircuit(QPoint depart, double angle, QString imgResource) {
    this->depart = depart;
    this->angle = angle;
    
    image = QImage(imgResource);
}

const QPoint& CCircuit::getDepart(void) {
    return depart;
}

const QImage& CCircuit::getImage(void) {
    return image;
}

double CCircuit::getAngle(void) {
    return angle;
}

void CCircuit::setMarkers(const QList<CMarker>& markers) {
    this->markers = markers;
}

const QList<CMarker>& CCircuit::getMarkers(void) {
    return markers;
}

