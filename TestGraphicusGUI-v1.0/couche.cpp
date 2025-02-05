/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

//constructeur
Couche::Couche()
{
    formes = new Vecteur<Forme>;
    taille = 0;
    etat = INITIALISEE;
 }
//destructeur
Couche::~Couche()
{
  /*for (int i = 0; i < MAX_FORMES; i++)
     {
        delete formes[i];
        formes[i] = nullptr;
     }*/
	delete formes;
}

bool Couche::ajoutForme(Forme* forme)
{
  if (etat != ACTIVE)
  { 
     cout<<"impossible de modifier, Couche n'est pas active"<<endl;
     return false; 
  }  

  *formes += forme;
  //*formes++;

  taille++;
  return true;
}
 

void Couche::afficher(ostream& os)        
{
   os<<"L ";
   
    switch (etat) 
    {
      case INITIALISEE: 
        os << "i"<<endl; 
        break;
      case ACTIVE: 
        os << "a"<<endl; 
        break;
      case INACTIVE: 
        os << "x"<<endl; 
        break;
    }

   if (taille==0)
     cout<<"vide"<<endl;
   else
   {
	   for (int i = 0; i < formes->getTaille(); i++)
        formes->get(i)->afficher(os);
   }
   
}

//retire une forme sur la couche active si l'indexe est bon
Forme* Couche::retirerForme(int index)
{
   if (etat != ACTIVE) 
   {
      cout<<"impossible de modifier Couche n'est pas active"<<endl;
      return nullptr; 
   } 
   if(index >= formes->getTaille())
   {
     cout<<"index trop eleve"<<endl;
     return nullptr; 
   }

   if (taille>0)
     taille--;

   //*formes--;
     	
   return *formes-index;
}

//Methode qui retourne une forme existante a un index
//Prend en parametre l'index dans la couche (de 0 a 4)
Forme* Couche::getForme(int index)
{
  if(index> formes->getTaille() || index<0)	//mauvais index
     return nullptr;
     
  //Forme* formeVoulue = formes[index];
  return formes->get(index);
}

//Methode qui calcule l'aire totale d'une couche
//Retourne l'aire
double Couche::aireTotale()
{
  double aireTotale=0;
  
  for(int i=0;i<formes->getTaille(); i++)
  {
	  aireTotale += formes->get(i)->aire();         //mmmphhfff
  }
  return aireTotale;
}

//Methode qui translate toutes les formes d'une couche
//Retourne True si reussite, false si echec
bool Couche::translater(int deltaX, int deltaY)
{
   if (etat != ACTIVE)
   { 
      cout<<"impossible de modifier, Couche n'est pas active"<<endl;
      return false; 
   }  
   
  for(int i=0;i<formes->getTaille(); i++)
  {
    /*if(formes[i] != nullptr)
      formes[i]->translater(deltaX,deltaY);*/
	 formes->get(i)->translater(deltaX, deltaY);
  }
  return true;
}

//Methode qui retire toutes le formes d'une couche
//Retourne True si reussite
bool Couche::reinitialiser()
{
   /*for (int i = 0; i < MAX_FORMES; i++)
   {
     delete formes[i];
     formes[i] = nullptr;
   }*/
    formes->viderVecteur();
    taille = 0;
    etat = INITIALISEE;
   
    return true;
}

bool Couche::changerEtat(EtatCouche nouvelEtat) 
{
    if (nouvelEtat == etat) 
        return false; 
    
    etat = nouvelEtat;
    return true;
}

EtatCouche Couche::getEtat()
{
  return etat;
}

int Couche::getTaille()
{
  return taille;
}

int Couche::getIndexCourrant()
{
	return formes->getIndexCourrant();
}

bool Couche::setIndexCourrant(int index)
{
    
	return formes->setIndexCourrant(index);
}

 
