/********
 * Fichier: carre.cpp
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: implementation des methodes des classes decrites dans
 *    carre.h. Ce fichier fait partie de la distribution de Graphicus.
********/
#include "carre.h"

//constructeur
Carre::Carre(int largeurVoulue, int ancrageX, int ancrageY)
{
  setDimension(largeurVoulue);
  ancrage.x = ancrageX;
  ancrage.y = ancrageY;
}
//destructeur
Carre::~Carre()
{}
//change la dimension du cote du carre
void Carre::setDimension(int largeurVoulue)
{
  if(largeurVoulue > 0)
  { 
    largeur = largeurVoulue;
  }
  else
  {
    while(largeurVoulue <= 0)
    {
      cout<<"Dimension de carre est invalide"<<endl;
      cout<<"Quel est la longueur de cote voulue: ";
      cin>>largeurVoulue;
    }
    largeur = largeurVoulue;
  }
}

double Carre::aire() 
{
    return largeur * largeur;
}

void Carre::afficher(ostream& os) 
{
    os << "K "<<ancrage.x<<" "<< ancrage.y <<" "<<largeur<<endl;
}
