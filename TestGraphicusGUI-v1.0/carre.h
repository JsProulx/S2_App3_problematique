/********
 * Fichier: carre.h
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: Declaration de la classe carre. La classe carre gere la creation
 *    de forme de type carre qui decoule de la classe Rectangle
 *    Ce fichier fait partie de la distribution de Graphicus.
********/  

#ifndef CARRE_H
#define CARRE_H
#include "rectangle.h"

class Carre : public Rectangle
{
  public: 

  Carre(int largeurVoulue=1, int ancrageX=0, int ancrageY=0);
  void setDimension(int largeurVoulue);
  double aire();
  void afficher(ostream & s);
  ~Carre();
  
  private:
  int largeur;
  
};

#endif
