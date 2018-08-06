#include "CDroite.h"
#include "CVerticale.h"
#include "COblique.h"

CDroite * CDroite::create(const QPointF& p1, const QPointF& p2) {
	if(p1.x() != p2.x()) {
		double a = (double)(p2.y() - p1.y()) / (double)(p2.x() - p1.x());
		double b = p2.y() - (a * p2.x());

		return new COblique(a, b);
	}
	
	return new CVerticale(p1.x());
}
