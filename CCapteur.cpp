#include <stdlib.h>
#include "CCapteur.h"

void CCapteur::init(void) {
    value = (double)((rand() % 200) - 100);
}

double CCapteur::getValue(void) {
    return value;
}

void CCapteur::from(CGene *other) {
    CCapteur *oc = static_cast<CCapteur *>(other);

    value = oc->value;
}
