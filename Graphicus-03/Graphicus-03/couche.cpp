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
  for (int i = 0; i < MAX_FORMES; i++) 	//pour creer une couche vide avec 5 ptrnull
   {
     formes[i] = nullptr;
   }
   taille = 0;
   etat = INITIALISEE;
 }
//destructeur
Couche::~Couche()
{
  for (int i = 0; i < MAX_FORMES; i++)
     {
        delete formes[i];
        formes[i] = nullptr;
     }
}

bool Couche::ajoutForme(Forme* forme)
{
  if (etat != ACTIVE)
  { 
     cout<<"impossible de modifier, Couche n'est pas active"<<endl;
     return false; 
  }  
  if(taille >= MAX_FORMES)
  {
    cout<<"impossible, couche remplie"<<endl;
    return false; 
  }
  formes[taille] = forme;
  taille++;
  return true;
}
 

void Couche::afficher(ostream& os)        
{
   cout<<"Etat: ";
   
    switch (etat) 
    {
      case INITIALISEE: 
        os << "Initialisée"<<endl; 
        break;
      case ACTIVE: 
        os << "Active"<<endl; 
        break;
      case INACTIVE: 
        os << "Inactive"<<endl; 
        break;
    }

   if (taille==0)
     cout<<"vide"<<endl;
  
   for (int i=0; i<taille; i++)
      formes[i]->afficher(os);
   
}

//retire une forme sur la couche active si l'indexe est bon
Forme* Couche::retirerForme(int index)
{
   if (etat != ACTIVE) 
   {
      cout<<"impossible de modifier Couche n'est pas active"<<endl;
      return nullptr; 
   } 
   if(index >= MAX_FORMES)
   {
     cout<<"index trop eleve"<<endl;
     return nullptr; 
   }
   
   Forme* forme_a_enlever = formes[index];    //pour ne pas perdre le pointeur a retouner
   
   if (forme_a_enlever == nullptr) 
   {
     cout<<"l'indexe indique ne contient pas de forme"<<endl;
     return nullptr;
   }       
   
   //on decale les autres 
   for (int i = index; i<MAX_FORMES-1; i++) 
   {
      Forme* buffer = formes[i+1];        //buffer
      formes[i+1] = nullptr;
      formes[i] = buffer;
   }
   if (taille>0)
     taille--;
     	
   return forme_a_enlever;
}

//Methode qui retourne une forme existante a un index
//Prend en parametre l'index dans la couche (de 0 a 4)
Forme* Couche::getForme(int index)
{
  if(index>MAX_FORMES || index<0)	//mauvais index
     return nullptr;
     
  Forme* formeVoulue = formes[index];
  
  return formeVoulue;
}

//Methode qui calcule l'aire totale d'une couche
//Retourne l'aire
double Couche::aireTotale()
{
  double aireTotale=0;
  
  for(int i=0;i<MAX_FORMES; i++)
  {
    if(formes[i] != nullptr)
      aireTotale += formes[i]->aire();
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
   
  for(int i=0;i<MAX_FORMES; i++)
  {
    if(formes[i] != nullptr)
      formes[i]->translater(deltaX,deltaY);
  }
  return true;
}

//Methode qui retire toutes le formes d'une couche
//Retourne True si reussite
bool Couche::reinitialiser()
{
   for (int i = 0; i < MAX_FORMES; i++) 
   {
     delete formes[i];
     formes[i] = nullptr;
   }
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



 
