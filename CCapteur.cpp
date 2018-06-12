#include <stdlib.h>
#include "CCapteur.h"

void CCapteur::init(void) {
    value = (double)((rand() % 200) - 100);
}

double CCapteur::getValue(void) {
    return value;
}

void CCapteur::from(CCapteur *other) {
    value = other->value;
}
