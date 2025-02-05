/********
 * Fichier: vecteur.h
 * Auteurs: Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date: 13 Janvier 2025
 * Modifie par : 
 * Date : 
 * Description: Declaration de la classe vecteur. Gere la creation de vecteur
 *    ainsi que l'allocation dynamique de memoir des elements qu'on veut manipuler
 *    dans le vecteur.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/   


#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>

using namespace std;
//#include "couche.h"

template <typename T>
class Vecteur
{
  public:
  
     Vecteur();
    virtual ~Vecteur();
    int getCapacite();
    int getTaille();
    void doubleCapacite();
    void viderVecteur();
    bool estVide();

    bool ajout(T*);
    T* retirer(int);
    T* get(int);
    void afficher(std::ostream& os);
    int getIndexCourrant();

    bool operator += (T* Ajout)
    {
		return ajout(Ajout);
    }
	T* operator - (int index)
	{
		return retirer(index);
	}
    T* operator [] (int index)
    {
		return get(index);
    }
    void operator << (std::ostream& os)
    {
		afficher(os);
    }
    void operator >> (std::istream& is)
    {
        // a faire plus tard caliss

    }
    Vecteur& operator++()
    {
        if (indexCourrant < taille - 1)
        {
            indexCourrant++;
        }
        return *this;
    }
    Vecteur& operator--()
    {
        if (indexCourrant > 0)
        {
            indexCourrant--;
        }
        return *this;
    }
    
  private:
  int taille;
  int capacite;
  T** vecteur;
  int indexCourrant;
};


template <typename T>
Vecteur<T>::Vecteur()
{
    capacite = 1;
    taille = 0;
    vecteur = new T* [capacite];
    vecteur[0] = nullptr;
	indexCourrant = 0;
}

//destructeur
template <typename T>
Vecteur<T>::~Vecteur()
{
	/*for (int i = 0;i < taille;i++)
        delete vecteur[i];

    delete[] vecteur;*/
}

//vide le vecteur et conserve sa capacite
template <typename T>
void Vecteur<T>::viderVecteur()
{
    for (int i = 0; i < capacite; i++)
    {
        delete vecteur[i];
        vecteur[i] = nullptr;
    }
    taille = 0;
}

template <typename T>
int Vecteur<T>::getCapacite()
{
    return capacite;
}

template <typename T>
int Vecteur<T>::getTaille()
{
    return taille;
}

template <typename T>
bool Vecteur<T>::estVide()
{
    int c = getTaille();
    if (c > 0)
        return false;
    return true;
}

template <typename T>
void Vecteur<T>::doubleCapacite()
{
    capacite = 2 * capacite;
    T** buffer = new T * [capacite];	//cree un tableau de pointeur de couche tampon

    for (int i = 0;i < capacite / 2;i++) 		//on copie nos valeur dans le tampon
        buffer[i] = vecteur[i];

    for (int i = capacite / 2;i < capacite;i++)   //met des pointeurs null dans le reste du tableau tampon
        buffer[i] = nullptr;

    delete[] vecteur;		//libere l'ancien tableau de pointeur
    vecteur = buffer;
}

template <typename T>
bool Vecteur<T>::ajout(T* nouvelleCouche)
{
    if (taille == capacite)
        doubleCapacite();

    vecteur[taille] = nouvelleCouche;
    taille++;

    return true;
}

//Methodes specifique a l'app1

//retire un element du tableau
//return un pointeur vers l'element retirer
template <typename T>
T* Vecteur<T>::retirer(int index)
{
    if (index >= taille || index < 0)
    {
        std::cout << "index invalide" << endl;
        return nullptr;
    }
    T* element_a_enlever = vecteur[index];

    for (int i = index; i < capacite - 1; i++)	//pour decaller les elements qui suivent celui qui a ete retirer
    {
        T* buffer = vecteur[i + 1];        //buffer
        vecteur[i + 1] = nullptr;
        vecteur[i] = buffer;
    }
    if (taille > 0)
        taille--;

    return element_a_enlever;
}

//return un pointeur vers l'element en index
template <typename T>
T* Vecteur<T>::get(int index)
{
    if (index >= capacite || index < 0)
    {
        cout << "index invalide" << endl;
        return nullptr;
    }

    return vecteur[index];
}

template <typename T>
void Vecteur<T>::afficher(ostream& os)
{
    if (taille == 0)
        cout << "----- aucune couche -----" << endl;

    for (int i = 0; i < taille; i++)
    {
        //cout << "----- Couche " << i << " -----" << endl;
        vecteur[i]->afficher(os);
    }

}

template <typename T>
int Vecteur<T>::getIndexCourrant()
{
	return indexCourrant;
}

#endif
