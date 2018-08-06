#ifndef CVERTICALE_H
#define CVERTICALE_H

#include "CDroite.h"

class CVerticale : public CDroite {
public:
    CVerticale(double x);
    QPoint croise(const CDroite& other) const;
    double eval(double x) const;
private:
    double x;
};

#endif // CVERTICALE_H
