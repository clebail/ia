#ifndef CDROITE_H
#define CDROITE_H

#include <QPoint>

class CDroite {
public:
    virtual ~CDroite(void) {}
    virtual QPoint croise(const CDroite& other) const = 0;
    virtual double eval(double x) const = 0;
};

#endif // CDROITE_H
