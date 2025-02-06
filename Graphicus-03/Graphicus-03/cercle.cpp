/********
 * Fichier: cercle.cpp
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: implementation des methodes des classes decrites dans
 *    cercle.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"

  Cercle::Cercle(int rayon_voulu, int ancrageX, int ancrageY)
  {
      setDimension(rayon_voulu);
      ancrage.x = ancrageX;
      ancrage.y = ancrageY;
     
  }
  
  void Cercle::setDimension(int rayon_voulu)
  {
    if(rayon_voulu > 0)
    { 
      rayon = rayon_voulu;
    }
    else
    {
      while(rayon_voulu <= 0)
      {
        cout<<"Dimension du cercle est invalide"<<endl;
        cout<<"Quel est le rayon voulue: ";
        cin>>rayon_voulu;
      }
      rayon = rayon_voulu;			
    }
  }
  double Cercle::aire()
  {
    double pi = 3.1416;
    
    return (pi*rayon*rayon);
  }
  void Cercle::afficher(ostream & os)
  {
    os << "C "<<ancrage.x<<" "<< ancrage.y <<" "<<rayon<<endl;
  }
  
  Cercle::~Cercle()
  {
  }
