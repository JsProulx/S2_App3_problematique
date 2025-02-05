/********
 * Fichier: vecteur.cpp
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: implementation des methodes des classes decrites dans
 *    vecteur.h. Ce fichier fait partie de la distribution de Graphicus.
********/

/*#include "vecteur.h"

//constructeur
Vecteur::Vecteur()
{
  //capacite = 1;
  capacite = 2;		//pour la validation, remettre a 1 apres
  taille = 0;
  vecteur = new Couche*[capacite];
  vecteur[0] = nullptr;
}

//destructeur
Vecteur::~Vecteur()
{
  for(int i=0;i<capacite;i++)
    delete vecteur[i];
    
  delete[] vecteur;
}

//vide le vecteur et conserve sa capacite
void Vecteur::viderVecteur()
{
   for (int i=0; i<capacite; i++)
   {
      delete vecteur[i];
      vecteur[i]=nullptr;
   }
   taille=0;
}
int Vecteur::getCapacite()
{
   return capacite;
}

int Vecteur::getTaille()
{
   return taille;
}

bool Vecteur:: estVide()
{
   int c = getTaille();
   if (c>0)
      return false;
   return true;
}

void Vecteur::doubleCapacite()
{
  capacite = 2*capacite;
  Couche** buffer = new Couche*[capacite];	//cree un tableau de pointeur de couche tampon
  
  for(int i=0;i<capacite/2;i++) 		//on copie nos valeur dans le tampon
    buffer[i] = vecteur[i];
  
  for(int i=capacite/2;i<capacite;i++)   //met des pointeurs null dans le reste du tableau tampon
    buffer[i] = nullptr;
    
  delete[] vecteur;		//libere l'ancien tableau de pointeur
  vecteur = buffer;		
}

bool Vecteur::ajoutCouche(Couche* nouvelleCouche)
{
  if(taille==capacite)
    doubleCapacite();
    
  vecteur[taille] = nouvelleCouche;
  taille++;
  
  return true;
}

//Methodes specifique a l'app1

//retire un element du tableau
//return un pointeur vers l'element retirer
Couche* Vecteur::retirerCouche(int index)
{
   if(index >= capacite || index<0)
   {
     cout<<"index invalide"<<endl;
     return nullptr; 
   }
  Couche* couche_a_enlever = vecteur[index];
  
  for (int i = index; i<capacite-1; i++)	//pour decaller les elements qui suivent celui qui a ete retirer
   {
      Couche* buffer = vecteur[i+1];        //buffer
      vecteur[i+1] = nullptr;
      vecteur[i] = buffer;
   }
   if (taille>0)
     taille--;
     	
   return couche_a_enlever;
}

//return un pointeur vers l'element en index
Couche* Vecteur::getCouche(int index)
{
  if(index >= capacite || index<0)
   {
     cout<<"index invalide"<<endl;
     return nullptr; 
   }
   
   return vecteur[index];
}

void Vecteur::afficher(ostream& os)
{
  if(taille==0)
    cout<<"----- aucune couche -----"<<endl;
    
  for (int i=0; i<taille; i++)
  {
    cout<<"----- Couche "<< i <<" -----"<<endl;
    vecteur[i]->afficher(os);
  }
  
}*/











