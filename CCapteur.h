#ifndef CCAPTEUR_H
#define CCAPTEUR_H

#include "CGene.h"

class CCapteur : public CGene {
public:
    void init(void);
    double getValue(void);
    void from(CGene *other);
private:
    double value;
};

#endif // CCAPTEUR_H
