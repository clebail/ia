#include "CCircuit.h"

CCircuit::CCircuit(void) {
    nbGagne = 0;
}

CCircuit::CCircuit(QPoint depart, double angle, QString imgResource, QPoint posTime) {
    this->depart = depart;
    this->angle = angle;
	this->posTime = posTime;

    nbGagne = 0;
    
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

void CCircuit::normCoordonnees(QPoint& p) {
    normCoordonnees(p.rx(), p.ry());
}

void CCircuit::normCoordonnees(int& x, int& y) {
	if(x < 0) {
		x = 0;
	}
	
	if(x >= image.width()) {
		x = image.width() - 1;
	}
	
	if(y < 0) {
		y = 0;
	}
	
	if(y >= image.height()) {
		y = image.height() - 1;
	}
}

const QPoint& CCircuit::getPosTime(void) {
	return posTime;
}

void CCircuit::setNbGagne(int nbGagne) {
    this->nbGagne = nbGagne;
}

int CCircuit::getNbGagne(void) {
    return nbGagne;
}

