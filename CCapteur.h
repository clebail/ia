#ifndef CCAPTEUR_H
#define CCAPTEUR_H

class CCapteur {
public:
    void init(void);
    double getValue(void);
    void from(CCapteur *other);
private:
    double value;
};

#endif // CCAPTEUR_H
