#ifndef CMARKER_H
#define CMARKER_H

#include <QPointF>

class CMarker {
public:
    typedef bool (CMarker::*pDepasse)(const QPointF& p) const;

    CMarker(const QPointF& p, pDepasse depasse, pDepasse depasseInv);
    bool isDepasse(const QPointF& p) const;
    bool isDepasseInv(const QPointF& p) const;
    bool depasseHaut(const QPointF& p) const;
    bool depasseDroite(const QPointF& p) const;
    bool depasseBas(const QPointF& p) const;
    bool depasseGauche(const QPointF& p) const;
	const QPointF& getPosition(void) const;
private:
    QPointF p;
    pDepasse depasse;
    pDepasse depasseInv;
};

#endif // CMARKER_H
