#ifndef CMARKER_H
#define CMARKER_H

#include <QPoint>

class CMarker {
public:
    typedef bool (CMarker::*pDepasse)(const QPoint& p) const;

    CMarker(const QPoint& p, pDepasse depasse, pDepasse depasseInv);
    bool isDepasse(const QPoint& p) const;
    bool isDepasseInv(const QPoint& p) const;
    bool depasseHaut(const QPoint& p) const;
    bool depasseDroite(const QPoint& p) const;
    bool depasseBas(const QPoint& p) const;
    bool depasseGauche(const QPoint& p) const;
	const QPoint& getPosition(void) const;
private:
    QPoint p;
    pDepasse depasse;
    pDepasse depasseInv;
};

#endif // CMARKER_H
