#include "CMarker.h"

CMarker::CMarker(const QPointF& p, pDepasse depasse, pDepasse depasseInv) {
    this->p = p;
    this->depasse = depasse;
    this->depasseInv = depasseInv;
}

bool CMarker::isDepasse(const QPointF& p) const {
   return (this->*depasse)(p);
}

bool CMarker::isDepasseInv(const QPointF& p) const {
    return (this->*depasseInv)(p);
}

bool CMarker::depasseHaut(const QPointF& p) const {
    return p.y() < this->p.y();
}

bool CMarker::depasseDroite(const QPointF& p) const {
    return p.x() > this->p.x();
}

bool CMarker::depasseBas(const QPointF& p) const {
    return p.y() > this->p.y();
}

bool CMarker::depasseGauche(const QPointF& p) const {
    return p.x() < this->p.x();
}

const QPointF& CMarker::getPosition(void) const {
	return p;
}
