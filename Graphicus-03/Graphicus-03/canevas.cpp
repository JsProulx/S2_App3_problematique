/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
//constructeur
Canevas::Canevas()
{
  canevas = new Vecteur<Couche>();
}
//Destructeur
Canevas::~Canevas()
{
  delete canevas;
}

bool Canevas::ajouterCouche()
{
   Couche* nouvelleCouche = new Couche();  
   canevas->ajout(nouvelleCouche);
   return true;
}

bool Canevas::retirerCouche(int index)
{
   canevas->retirer(index);
   return true;
}


bool Canevas::reinitialiser()
{
   canevas->viderVecteur();
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   canevas->get(index)-> reinitialiser();
   
   return true;
}

bool Canevas::activerCouche(int index)
{
   if(index>canevas->getTaille()-1 || index<0)
   {
     cout<<"index couche canevas errone"<<endl;
     return false;
   }
   
   for(int i=0;i<canevas->getTaille();i++)
   {
     if(index == i)
	canevas->get(i)->changerEtat(ACTIVE);
     else
       if(canevas->get(i)->getEtat() == ACTIVE)
         canevas->get(i)->changerEtat(INACTIVE);
   }
   
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   if(index>canevas->getTaille()-1 || index<0)   // get taille -1 car index commence a 0 mais getTaille commence a 1. pour pas qu'une demande pour l'indexe 1 qd le tableau contient 1 fase core dump
   {
     cout<<"index couche canevas errone"<<endl;
     return false;
   }
   
   canevas->get(index)->changerEtat(INACTIVE);
   return true;
}


bool Canevas::ajouterForme(Forme* p_forme)
{
   if (p_forme==nullptr)
      return false;
    
   for(int i=0;i<canevas->getTaille();i++)
   {
     if(canevas->get(i)->getEtat() == ACTIVE)
     {
       canevas->get(i)->ajoutForme(p_forme);
       return true;
     }
   }
   
   return false;
}

bool Canevas::retirerForme(int index)
{
   
   
   for(int i=0;i<canevas->getTaille();i++)
   {
     if(canevas->get(i)->getEtat() == ACTIVE)
     {
        if(index>canevas->get(i)->getTaille()-1 || index<0)
        {
          cout<<"index forme ACTIVE errone"<<endl;
          return false;
        }
       canevas->get(i)->retirerForme(index);            
       return true;                                   //peut retourner true meme si l'index specifie est null et n'a donc rien enleve.  ex index 8 retourne true meme s'il n'y a pas d'index 8
     }
   }
   return false;
}

double Canevas::aire()
{
   double aireCanevas = 0;
   
   for(int i=0;i<canevas->getTaille();i++)
     aireCanevas += canevas->get(i)->aireTotale();     //fait le total des aires des couches du canevas
   
   return aireCanevas;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for(int i=0;i<canevas->getTaille();i++)
   { 
     if(canevas->get(i)->getEtat() == ACTIVE)
     {
       canevas->get(i)->translater(deltaX,deltaY);     //translate la couche active
       return true;
     }
    
   }
   return false;
}

void Canevas::afficher(ostream & os)
{
   canevas->afficher(os);
}









