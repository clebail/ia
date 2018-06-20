#include "CCircuit.h"

CCircuit::CCircuit(void) {
}

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

int CCircuit::normCoordonnees(int i) {
    if(i >= 500) {
        i = 500;
    }

    if(i < 0) {
        i = 0;
    }

    return i;
}

