#ifndef COBLIQUE_H
#define COBLIQUE_H

#include "CDroite.h"

class COblique : public CDroite {
public:
    COblique(double a, double b);
    QPointF croise(const CDroite& other) const;
    double eval(double x) const;
    QLine getLine(const QSize& size) const;
    QString toString(void) const;
private:
    double a;
    double b;
};

#endif // COBLIQUE_H
