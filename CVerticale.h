#ifndef CVERTICALE_H
#define CVERTICALE_H

#include "CDroite.h"

class CVerticale : public CDroite {
public:
    CVerticale(double x);
    QPointF croise(const CDroite& other) const;
    double eval(double x) const;
    QLine getLine(const QSize& size) const;
    QString toString(void) const;
private:
    double x;
};

#endif // CVERTICALE_H
