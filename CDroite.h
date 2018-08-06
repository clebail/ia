#ifndef CDROITE_H
#define CDROITE_H

#include <QPointF>

class CDroite {
public:
    virtual ~CDroite(void) {}
    virtual QPointF croise(const CDroite& other) const = 0;
    virtual double eval(double x) const = 0;
	static CDroite * create(const QPointF& p1, const QPointF& p2);
};

#endif // CDROITE_H
