/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date : 1/13/2025
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "forme.h"
#include "vecteur.h"

const int MAX_FORMES = 5;

enum EtatCouche { INITIALISEE, ACTIVE, INACTIVE };

class Couche
{

public:

    //Vecteur<Forme>* formes;

    Couche();
    bool ajoutForme(Forme*);
    void afficher(ostream& os);
    Forme* retirerForme(int index);
    Forme* getForme(int index);
    double aireTotale();
    bool translater(int deltaX = 0, int deltaY = 0);
    bool reinitialiser();
    bool changerEtat(EtatCouche nouvelEtat);
    int getTaille();
    EtatCouche getEtat();
    virtual ~Couche();
	int getIndexCourrant();
	bool setIndexCourrant(int index);

private:
    int taille;
    EtatCouche etat;
    Vecteur<Forme>* formes;

};

#endif
