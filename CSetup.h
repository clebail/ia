#ifndef CSETUP_H
#define CSETUP_H


class CSetup {
public:
    CSetup();

    inline void setNbCircuit(int nbCircuit) { this->nbCircuit = nbCircuit; }
    inline int getNbCircuit(void) { return nbCircuit; }
    inline void setCreateImages(bool createImages) { this->createImages = createImages; }
    inline  bool getCreateImages(void) { return createImages; }
    inline void setNbVainqueur(int nbVainqueur) { this->nbVainqueur = nbVainqueur; }
    inline int getNbVainqueur(void) { return nbVainqueur; }
    inline void setCoefVitesse(double coefVitesse) { this->coefVitesse = coefVitesse; }
    inline double getCoefVitesse(void) { return coefVitesse; }
private:
    int nbCircuit;
    bool createImages;
    int nbVainqueur;
    double coefVitesse;
};

#endif // CSETUP_H
