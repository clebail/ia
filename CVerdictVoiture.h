#ifndef CVERDICTVOITURE_H
#define CVERDICTVOITURE_H

#include <QList>
#include <json.h>
#include "CBaseVoiture.h"

class CVerdictVoiture : public CBaseVoiture {
public:
    CVerdictVoiture();
    static CVerdictVoiture * fronJSon(json_object *jObj);
private slots:
    void onWCircuitDrawVoitures(QPainter *painter, double dx, double dy);
};

#endif // CVERDICTVOITURE_H
