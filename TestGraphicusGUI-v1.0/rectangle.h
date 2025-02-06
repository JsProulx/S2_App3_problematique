/********
 * Fichier: rectangle.h
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: Declaration de la classe rectangle. Gere la creation
 *    de forme de type rectangle qui decoule de la classe Forme
 *    Ce fichier fait partie de la distribution de Graphicus.
********/   

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "forme.h"

class Rectangle : public Forme
{
  public: 
  Rectangle(int largeurVoulue=1, int hauteurVoulue=1, int ancrageX=0, int ancrageY=0);
  virtual void setDimension(int largeurVoulue, int hauteurVoulue);
  virtual double aire();
  virtual void afficher(ostream & s);
  virtual ~Rectangle();
  
  private:
  int largeur;
  int hauteur;
  
};

#endif
