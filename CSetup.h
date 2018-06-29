#ifndef CSETUP_H
#define CSETUP_H


class CSetup {
public:
    CSetup();

    inline void setNbCircuit(int nbCircuit) { this->nbCircuit = nbCircuit; }
    inline int getNbCircuit(void) { return nbCircuit; }
    inline void setCreateImages(bool createImages) { this->createImages = createImages; }
   inline  bool getCreateImages(void) { return createImages; }
private:
    int nbCircuit;
    bool createImages;
};

#endif // CSETUP_H
