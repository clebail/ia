#include "CMarker.h"

CMarker::CMarker(const QPoint& p, pDepasse depasse) {
    this->p = p;
    this->depasse = depasse;
}

bool CMarker::isDepasse(const QPoint& p) const {
   return (this->*depasse)(p);
}

bool CMarker::depasseHaut(const QPoint& p) const {
    return p.y() < this->p.y();
}

bool CMarker::depasseDroite(const QPoint& p) const {
    return p.x() > this->p.x();
}

bool CMarker::depasseBas(const QPoint& p) const {
    return p.y() > this->p.y();
}

bool CMarker::depasseGauche(const QPoint& p) const {
    return p.x() < this->p.x();
}

const QPoint& CMarker::getPosition(void) const {
	return p;
}
