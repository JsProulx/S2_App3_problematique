/********
 * Fichier: rectangle.cpp
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: implementation des methodes des classes decrites dans
 *    rectangle.h. Ce fichier fait partie de la distribution de Graphicus.
********/


#include "rectangle.h"
//Constructeur
Rectangle::Rectangle(int largeurVoulue, int hauteurVoulue, int ancrageX, int ancrageY)
{
  
  setDimension(largeurVoulue,hauteurVoulue);
  ancrage.x = ancrageX;
  ancrage.y = ancrageY;
}
//Destructeur
Rectangle::~Rectangle()
{
}
//Methode pour changer les dimensions d'un rectangle
//prend la largeur et la hauteur en parametre
void Rectangle::setDimension(int largeurVoulue, int hauteurVoulue)
{
  if(largeurVoulue > 0 && hauteurVoulue > 0)
  { 
    largeur = largeurVoulue;
    hauteur = hauteurVoulue;
  }
  else
  {
    while(largeurVoulue <= 0 || hauteurVoulue <= 0)
    {
      cout<<"Dimension de rectangle est invalide"<<endl;
      cout<<"Quel est la largeur voulue: ";
      cin>>largeurVoulue;
      cout<<"Quel est la hauteur voulue: ";
      cin>>hauteurVoulue;
    }
    largeur = largeurVoulue;
    hauteur = hauteurVoulue;
  }
}

double Rectangle::aire() 
{
    return largeur * hauteur;
}

void Rectangle::afficher(ostream& os) 
{
    os << "R "<<ancrage.x<<" "<<ancrage.y<<" "<<largeur<<" "<<hauteur<<endl;
}



