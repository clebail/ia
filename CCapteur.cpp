#include <stdlib.h>
#include "CCapteur.h"

void CCapteur::init(void) {
    value = ((double)((rand() % 50) - 25)) / 50.0;
}

double CCapteur::getValue(void) {
    return value;
}

void CCapteur::from(CCapteur *other) {
    value = other->value;
}
