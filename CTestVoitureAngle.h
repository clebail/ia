#ifndef CTESTVOITUREANGLE_H
#define CTESTVOITUREANGLE_H

#include "CVehicule.h"

class CTestVoitureAngle : public CVehicule {
public:
    CTestVoitureAngle(QPoint position, double angle);
protected:
    double getVitesse(void);
    double getAngle(void);
};

#endif // CTESTVOITUREANGLE_H
