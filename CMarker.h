#ifndef CMARKER_H
#define CMARKER_H

#include <QPoint>

class CMarker {
public:
    typedef bool (CMarker::*pDepasse)(const QPoint& p);

    CMarker(const QPoint& p, pDepasse depasse);
    bool isDepasse(const QPoint& p);
    bool depasseHaut(const QPoint& p);
    bool depasseDroite(const QPoint& p);
    bool depasseBas(const QPoint& p);
    bool depasseGauche(const QPoint& p);
private:
    QPoint p;
    pDepasse depasse;
};

#endif // CMARKER_H
