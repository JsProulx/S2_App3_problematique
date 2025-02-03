/********
 * Fichier: vecteur.h
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: Declaration de la classe vecteur. Gere la creation de vecteur
 *    ainsi que l'allocation dynamique de memoir des elements qu'on veut manipuler
 *    dans le vecteur.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/   


#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "couche.h"


class Vecteur
{
  public:
  
    Vecteur();
    virtual ~Vecteur();
    int getCapacite();
    int getTaille();
    void doubleCapacite();
    void viderVecteur();
    bool estVide();
    bool ajoutCouche(Couche*);
    Couche* retirerCouche(int);
    Couche* getCouche(int);
    void afficher(ostream& os);
    
  private:
  int taille;
  int capacite;
  Couche** vecteur;
  
};

#endif
