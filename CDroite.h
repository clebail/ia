#ifndef CDROITE_H
#define CDROITE_H

#include <QPointF>
#include <QLine>
#include <QSize>
#include <QString>

class CDroite {
public:
    virtual ~CDroite(void) {}
    virtual QPointF croise(const CDroite& other) const = 0;
    virtual double eval(double x) const = 0;
	static CDroite * create(const QPointF& p1, const QPointF& p2);
    virtual QLine getLine(const QSize& size) const = 0;
    virtual QString toString(void) const = 0;
};

#endif // CDROITE_H
