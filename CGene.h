#ifndef CGENE_H
#define CGENE_H

class CGene {
public:
	virtual ~CGene(void) {}
    virtual void from(CGene *other) = 0;
};

#endif //CGENE_H
