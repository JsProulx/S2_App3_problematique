/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Description: Declaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut etre adapte a vos besoins de tests. Ce fichier
 *    fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "canevas.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"
#include "couche.h"


class Tests
{
public:
   // Methodes pour les tests unitaires des classes
   void tests_unitaires_formes();
   void tests_unitaires_couche();
   void tests_unitaires_vecteur();
   void tests_unitaires_canevas();
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02();
   void tests_application(); // Appel de tous les tests applicatifs

   void testRectangle();
   void testCarre();
   void testCercle();

   //pour les couches
   void testAjoutForme();
   void testRetraitForme();
   void testGetForme();
   void testAireTotale();
   void testTranslater();
   void testReinit();
   void testChangerEtat();
   Couche* remplirCouche(Couche* coucheARemplir);

   //pour le vecteur
   void testDoubleCapacite();
   void testVideVecteur();
   void testAjoutCouche();
   Vecteur<Couche>* remplirVecteur(Vecteur<Couche>*);
   void testGetCouche();
   void retirerCouche();
   
   //pour le canevas
   void testAjoutCoucheCanevas();
   void testAjoutFromeCanevas();
   void testActiverCouche();
   void testRetirerForme();
   void testAireCannevas();
   void testTranslaterCannevas();
   
   //validation
   void testValidation();
};

#endif
