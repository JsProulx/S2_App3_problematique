/********
 * Fichier: cercle.h
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: Declaration de la classe cercle. Gere la creation
 *    de forme de type cercle qui decoule de la classe Forme
 *    Ce fichier fait partie de la distribution de Graphicus.
********/  
#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"

class Cercle : public Forme
{
  public: 
  Cercle(int rayon_voulu=1, int ancrageX=0, int ancrageY=0);					
  void setDimension(int rayon_voulu);
  double aire();
  void afficher(ostream & s);
  ~Cercle();
  
  private:
  int rayon;
};

#endif
