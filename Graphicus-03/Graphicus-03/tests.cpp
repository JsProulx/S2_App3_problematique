/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Simon Provencher (pros3056) et Jean-Sebastien Proulx (proj7222)
 * Date : 1/13/2025
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"


void Tests::tests_unitaires_formes()
{ 
   // Tests sur les formes geometriques
   //testRectangle();
   //testCarre();
   //testCercle();
}

void Tests::tests_unitaires_couche()
{
   //  --- Tests sur la classe Couche --- // 
   
   testAjoutForme();
   testRetraitForme();
   testGetForme();
   testAireTotale();
   testTranslater();
   testReinit();
   testChangerEtat();
   
}

void Tests::tests_unitaires_vecteur()
{
   //  --- Tests sur la classe Vecteur --- //
   
   //testDoubleCapacite();
   //testAjoutCouche();
   //testVideVecteur();
   //testGetCouche();
   //retirerCouche();
   //testAjoutInt();

}

void Tests::tests_unitaires_canevas()
{
   // --- Tests sur la classe Canevas --- //
      
   //testAjoutCoucheCanevas();
   //testAjoutFromeCanevas();
   //testActiverCouche();
   //testRetirerForme();
   //testAireCannevas();
   //testTranslaterCannevas();
}
void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   //tests_application_cas_01();
   //tests_application_cas_02();
   tests_unitaires();
   //testValidation();
   
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}


//-----------------------------------------//
//------- Section pour les formes  -------//
//---------------------------------------//

void Tests::testRectangle()
{
   cout<<endl<<" ## --------------- SECTION FORME --------------- ## "<<endl<<endl;
   cout<<endl<<" ##  TEST RECTANGLE ## "<<endl<<endl;
   Coordonnee pos;
   pos.x=9;
   pos.y=3;
   
   cout<<"--> Creation d'un rectangle 2x4 au point (6,8)"<<endl;
   Forme* rect1 = new Rectangle(2,4,6,8);
   rect1->afficher(cout);
  
   //on ne peut pas changer la dimension d'un ptr forme
   /*cout<<"--> Changement de dimension du rectangle pour 77x22"<<endl;
   rect1 ->setDimension(77,22);
   rect1->afficher(cout);*/
   
   cout<<"--> Translation du rectangle de (-9,12)"<<endl;
   rect1->translater(-9,-12);		
   rect1->afficher(cout);
   
   cout<<"--> Set l'ancrage a (9,3)"<<endl;
   rect1->setAncrage(pos);
   rect1->afficher(cout);
   
   
   delete rect1;
}

void Tests::testCarre()
{
   cout<<endl<<" ##  TEST CARRE ## "<<endl<<endl;
   Coordonnee pos;
   pos.x=9;
   pos.y=3;
   
   cout<<"--> Creation d'un carre de cote 4"<<endl;
   Forme* carre1 = new Carre(4);
   carre1->afficher(cout);
   

   cout<<"--> Translation du carre de (8,7)"<<endl;
   carre1->translater(8,7);
   carre1->afficher(cout);
   
   cout<<"--> Set l'ancrage a (9,3)"<<endl;
   carre1->setAncrage(pos);
   carre1->afficher(cout);
   
   delete carre1;
}

void Tests::testCercle()
{
   cout<<endl<<" ##  TEST CERCLE ## "<<endl<<endl;
   Coordonnee pos;
   pos.x=9;
   pos.y=3;
   
   cout<<"--> Creation d'un cercle de rayon 2 encrer a l'origine"<<endl;
   Forme *cercle1 = new Cercle(2);
   cercle1->afficher(cout);
   
   cout<<"--> Translation du cercle de (99,99)"<<endl;
   cercle1->translater(99,99);
   cercle1->afficher(cout);
   
   cout<<"--> Set l'ancrage a (9,3)"<<endl;
   cercle1->setAncrage(pos);
   cercle1->afficher(cout);
   
   delete cercle1;
}

//-----------------------------------------//
//------- Section pour les couches  -------//
//-----------------------------------------//

//fonction pour remplir une couche pour accelerer 
Couche* Tests::remplirCouche(Couche* couche1)
{
  //mettre la couche en etat active
  couche1->changerEtat(ACTIVE);
  bool r;
  Forme* carre1 = new Carre(4, 3, 1);
  r = couche1 -> ajoutForme(carre1);
  Forme* cercle1 = new Cercle(1,2,3);
  r = couche1 -> ajoutForme(cercle1);
  Forme* rectangle1 = new Rectangle(2,3,7,8);
  r = couche1 -> ajoutForme(rectangle1);
  Forme* cercle2 = new Cercle(1,2,3);
  r = couche1 -> ajoutForme(cercle2);
  Forme* rectangle2 = new Rectangle(2,3,7,8);
  r = couche1 -> ajoutForme(rectangle2);
  //Forme* rectangle3 = new Rectangle(2,3,7,8); //essai mettre une forme de trop
  //r = couche1 -> ajoutForme(rectangle3);
  
  
  //couche1->afficher(cout);
  //cout<<endl<<endl;
  
  return couche1;
}

void Tests::testAjoutForme()
{
   cout<<endl<<" ## --------------- SECTION COUCHE --------------- ## "<<endl<<endl;
   cout<<endl<<" ##  TEST AJOUT FORME ## "<<endl<<endl;
   
   //cree une couche
   cout<<"--> Creation d'une couche vide"<<endl;
   Couche* couche1 = new Couche();
   couche1->afficher(cout);
   
   //cree des formes
   Forme* carre1 = new Carre(1, 5, 6);
   Forme* cercle1 = new Cercle();

   //met les formes dans la nouvelle couche
   cout<<"--> Insersion de formes dans la couche"<<endl;
   couche1->changerEtat(ACTIVE);
   couche1 -> ajoutForme(carre1);
   couche1 -> ajoutForme(cercle1);

   couche1->afficher(cout);

   delete couche1;

}
void Tests::testRetraitForme()
{
   cout<<endl<<" ##  TEST RETRAIT FORME ## "<<endl<<endl;
   bool r;
   //cree une couche
   cout<<"--> Creation d'une couche Rempli"<<endl;
   Couche* couche1 = new Couche();   
   couche1 = remplirCouche(couche1);
   couche1->afficher(cout);

   cout<<"--> Retrait de la forme a l'index 2"<<endl;
   Forme* formeRetire = couche1->retirerForme(2);
   
   cout<<"--> Couche avec forme retire"<<endl;
   couche1->afficher(cout);

  
   if(formeRetire != nullptr)
   {
     cout<<"--> Forme retire"<<endl;
     formeRetire->afficher(cout);
   }
    
   delete couche1;
}


void Tests::testGetForme()
{
   cout<<endl<<" ##  TEST GET FORME ## "<<endl<<endl;
   bool r;
   //cree une couche
   Couche* couche1 = new Couche();
   
   couche1 = remplirCouche(couche1);
   
   cout<<"--> Get de la forme a l'index 0"<<endl;
   Forme* formeVoulue = couche1->getForme(0);

   if(formeVoulue != nullptr)
     formeVoulue->afficher(cout);
    
   delete couche1;
}

void Tests::testAireTotale()
{
  cout<<endl<<" ##  TEST AIRE TOTALE ## "<<endl<<endl;
  bool r;
  //cree une couche
  cout<<"--> Creation d'une couche Rempli"<<endl;
  Couche* couche1 = new Couche();   
  couche1 = remplirCouche(couche1);
  couche1->afficher(cout);

  cout<<"--> Calcul de l'aire"<<endl;
  double aireTotale = couche1->aireTotale();
  
  cout<<"-->aire totale est : "<<aireTotale<<endl;
  
  delete couche1;
}

void Tests::testTranslater()
{
  cout<<endl<<" ##  TEST TRANSLATER ## "<<endl<<endl;
  //cree une couche
  Couche* couche1 = new Couche();
  couche1 = remplirCouche(couche1);
  
  cout<<"--> Translation de la couche de 6 en x et 9 en y"<<endl;
  couche1->translater(6,9);
  couche1->afficher(cout);
  
  delete couche1;
}

void Tests::testReinit()
{
  cout<<endl<<" ##  TEST REINITIALISER ## "<<endl<<endl;
  //cree une couche
  Couche* couche1 = new Couche();
  couche1 = remplirCouche(couche1);
  
  cout<<"--> Reinitialisation de la couche"<<endl;
  couche1->reinitialiser();
  couche1->afficher(cout);
  
  delete couche1;
}

void Tests::testChangerEtat()
{
  cout<<endl<<" ##  TEST CHANGEMENT D'ETAT ## "<<endl<<endl;
  //cree une couche
  Couche* couche1 = new Couche();
  couche1 = remplirCouche(couche1);
  
  cout<<"--> Changement de l'etat pour INACTIVE"<<endl;
  couche1->changerEtat(INACTIVE);
  couche1->afficher(cout);
  
  cout<<"--> Tentative d'ajout d'un cercle dans la couche"<<endl;
  Forme* cercle1 = new Cercle();
  couche1->ajoutForme(cercle1);
  //couche1->afficher(cout);
  
  delete couche1;
  delete cercle1;
}

//-----------------------------------------//
//------- Section pour les vecteurs -------//
//-----------------------------------------//

void Tests::testDoubleCapacite()
{
   cout<<endl<<" ## ---------- SECTION VECTEUR ---------- ## "<<endl<<endl;
   cout<<endl<<" ##  TEST DOUBLE CAPACITE ## "<<endl<<endl;
   Vecteur<Couche>* vect1 = new Vecteur<Couche>();
   cout<<"--> vecteur cree de capacite "<<vect1 -> getCapacite() << " et taille "<< vect1 -> getTaille()<<endl;
   vect1 -> doubleCapacite();
   cout<<"--> doublons la capacite 1x. Nouvelle capacite:"<<vect1 -> getCapacite()<<endl;
   vect1 -> doubleCapacite();
   vect1 -> doubleCapacite();
   cout<<"--> doublons la capacite 2 autres fois. Nouvelle capacite:"<<vect1 -> getCapacite()<<endl;
   
   delete vect1;
}

Vecteur<Couche>* Tests::remplirVecteur(Vecteur<Couche>* vect)
{
   
   Couche* couche1= new Couche();
   couche1->changerEtat(ACTIVE);
   couche1=remplirCouche(couche1);
   
   Couche* couche2= new Couche();
   //couche2->changerEtat(ACTIVE);
   //couche2=remplirCouche(couche2);
   
   Couche* couche3= new Couche();
   couche3->changerEtat(ACTIVE);
   couche3=remplirCouche(couche3);
   couche3->changerEtat(INACTIVE);
   
   Couche* couche4= new Couche();
   Couche* couche5= new Couche();
   
   //on ajoute les couche au vecteur
   /*vect->ajout(couche1);
   vect->ajout(couche2);
   vect->ajout(couche3);
   vect->ajout(couche4);
   vect->ajout(couche5);*/
   *vect += couche1;
   *vect += couche2;
   *vect += couche3;
   *vect += couche4;
   *vect += couche5;
   
   return vect;
}

void Tests::testAjoutInt()
{
    cout << endl << " ##  TEST AJOUT ENTIER ## " << endl << endl;
    Vecteur<int>* vect1 = new Vecteur<int>();	//cree un vecteur

	int* ptr = new int(1);
	int* ptr2 = new int(2);
	int* ptr3 = new int(3);
    cout << "On rempli le vecteur de Int" << endl;
	
    *vect1 += ptr;
	*vect1 += ptr2;
	*vect1 += ptr3;
    cout << vect1->getTaille();

	//on affiche
	for (int i = 0; i < vect1->getTaille(); i++)
	{
		cout << "Element " << i << " : " << *vect1->get(i) << endl;
	}

	//on retire un element
	cout << "On retire l'element 1" << endl;
    *vect1 - 1;

    //on affiche
	for (int i = 0; i < vect1->getTaille(); i++)
	{
		cout << "Element " << i << " : " << *vect1->get(i) << endl;
	}
    delete vect1;


	
}

void Tests::testAjoutCouche()
{
   cout<<endl<<" ##  TEST AJOUT COUCHE ## "<<endl<<endl;
   Vecteur<Couche>* vect1 = new Vecteur<Couche>();	//cree un vecteur

   //on cree des couches et on les rempli de formes
   cout<<"--> Creation d'un Vecteur rempli de couche differentes"<<endl;
   vect1 = remplirVecteur(vect1);
   vect1 -> afficher(cout);
     
   delete vect1;
}

void Tests::testVideVecteur()
{
   cout<<endl<<" ##  TEST VIDER VECTEUR ## "<<endl<<endl;
   Vecteur<Couche>* vect1 = new Vecteur<Couche>();
   cout<<"--> Creation d'un Vecteur rempli "<<endl;
   vect1 = remplirVecteur(vect1);
   vect1 -> afficher(cout);
   
   cout<<"--> Vider le Vecteur "<<endl;
   vect1->viderVecteur();
   vect1->afficher(cout);
   cout<<"--> Est-ce que le Vecteur est vide? (1=oui) : ";
   bool r = vect1->estVide();
   cout<<r<<endl;
  
   delete vect1;
}

void Tests::testGetCouche()
{
   cout<<endl<<" ##  TEST GET COUCHE ## "<<endl<<endl;
   Vecteur<Couche>* vect1 = new Vecteur<Couche>();
   cout<<"--> Creation d'un Vecteur rempli "<<endl;
   vect1 = remplirVecteur(vect1);
   vect1 -> afficher(cout);

   //on va prendre la couche 2 et 3
   cout<<"--> Get de la couche index 2 et 3 "<<endl;
   Couche* couche2 = vect1->get(2);
   Couche* couche3 = vect1->get(3);

   cout<<endl;

   cout<<"Couche 2:"<<endl;
   couche2->afficher(cout);

   cout<<endl;

   cout<<"Couche 3:"<<endl;
   couche3->afficher(cout);

   //on essai de get a un index invalide
   cout<<"--> Get d'une couche a un index invalide "<<endl;
   Couche* couche_test = vect1->get(8);
   if (couche_test!=nullptr)
    couche_test->afficher(cout);
   else
    cout<<"couche ptrnull"<<endl;

   delete vect1;
}

void Tests::retirerCouche()
{
cout<<endl<<" ##  TEST RETIRER COUCHE ## "<<endl<<endl;
  Vecteur<Couche>* vect1 = new Vecteur<Couche>();
  vect1 = remplirVecteur(vect1);
  
  cout<<"--> Retrait de la couche 2 "<<endl;
  vect1->retirer(2);
  vect1->afficher(cout);
  
  cout<<"--> Retrait de couches a des index invalides "<<endl;
  vect1->retirer(-1);
  vect1->retirer(69);
  
  cout<<"--> Retrait de la 1ere couche 2x "<<endl;
  vect1->retirer(0);
  vect1->retirer(0);
  vect1->afficher(cout);
  
  delete vect1;
}


//-----------------------------------------//
//------- Section pour les cavenas---------//
//-----------------------------------------//


void Tests::testAjoutCoucheCanevas()
{
  cout<<endl<<" ## --------------- SECTION CANEVAS --------------- ## "<<endl<<endl;
  cout<<endl<<" ##  TEST AJOUT COUCHE ## "<<endl<<endl;
  Canevas canevas1;
  
  cout<<"--> Creation d'un canevas et ajout de 5 couches"<<endl;
  for(int i=0;i<5;i++)
    canevas1.ajouterCouche();
    
  canevas1.afficher(cout);
  
  cout<<endl<<"--> Retrait de la 1ere couche"<<endl;
  canevas1.retirerCouche(0);   //  test retirer couche ici aussi
  canevas1.afficher(cout);
}

void Tests::testActiverCouche()
{
  cout<<endl<<" ##  TEST AJOUT COUCHE ## "<<endl<<endl;
  Canevas canevas1;
  cout<<"--> Creation d'un canevas et ajout de 2 couches"<<endl;
  for(int i=0;i<2;i++)
    canevas1.ajouterCouche();
   
  cout<<"--> Activation de la 2ieme couche"<<endl;
  canevas1.activerCouche(1);
  canevas1.afficher(cout);
 
}

void Tests::testAjoutFromeCanevas()
{
  cout<<endl<<" ## TEST AJOUT FORME ## "<<endl<<endl;
  
  Canevas canevas1;
  Forme* rect1 = new Rectangle(2,4,1,1);
  Forme* cercle1 = new Cercle(3);
  Forme* carre1 = new Carre();
  
  cout<<"--> Creation d'un canevas et ajout de 5 couches"<<endl;
  for(int i=0;i<5;i++)         //fait 5 couches vides
    canevas1.ajouterCouche();
  
  cout<<"-->Activation de la couche 2 et ajout d'un rectangle: "<< endl;
  canevas1.activerCouche(2);  //active la couche index 2 donc la 3e couche;
  canevas1.ajouterForme(rect1);  //ajoute forme sur couche active (2)
  
  canevas1.afficher(cout);
  
  cout<<"-->Activation de la couche 0 et ajout de 2 formes: "<< endl;
  canevas1.activerCouche(0);  //active la couche 0
  canevas1.ajouterForme(cercle1);  //ajoute 2 formes sur la couche 0
  canevas1.ajouterForme(carre1);
  
  canevas1.afficher(cout);
  
}

void Tests::testRetirerForme()
{
  cout<<endl<<" ## TEST RETRAIT FORME ## "<<endl<<endl;
  Canevas canevas1;
  Forme* rect1 = new Rectangle(2,4,1,1);
  Forme* cercle1 = new Cercle(3);
  Forme* carre1 = new Carre();
   
  for(int i=0;i<5;i++)         //fait 5 couches vides
    canevas1.ajouterCouche();
    
  canevas1.activerCouche(2);  //active la couche index 2 donc la 3e couche;
  canevas1.ajouterForme(rect1);  //ajoute forme sur couche active (2)
  
  canevas1.activerCouche(0);  //active la couche 0
  canevas1.ajouterForme(cercle1);  //ajoute 2 formes sur la couche 0
  canevas1.ajouterForme(carre1);
  
  cout<<"-->couche cree avec formes suivantes:"<<endl;
  canevas1.afficher(cout);
  
  cout<<"-->retrait de la forme a l'index 1"<<endl;
  canevas1.retirerForme(1);
  canevas1.afficher(cout);
 
  /*cout<<"test de retrait de la forme a l'index -8, 1 0"<<endl;
  canevas1.retirerForme(-8);
  canevas1.retirerForme(1);
  canevas1.retirerForme(0);
  
  canevas1.afficher(cout);*/
}
void Tests::testAireCannevas()
{
   cout<<endl<<" ##  TEST AIRE CANNEVAS ## "<<endl<<endl;
   
  Canevas canevas1;
  Forme* rect1 = new Rectangle(2,4,1,1);
  Forme* cercle1 = new Cercle(3);
  Forme* carre1 = new Carre();
   
  for(int i=0;i<5;i++)         //fait 5 couches vides
    canevas1.ajouterCouche();
    
  canevas1.activerCouche(2);  //active la couche index 2 donc la 3e couche;
  canevas1.ajouterForme(rect1);  //ajoute forme sur couche active (2)
  
  canevas1.activerCouche(0);  //active la couche 0
  canevas1.ajouterForme(cercle1);  //ajoute 2 formes sur la couche 0
  canevas1.ajouterForme(carre1);
  
  cout<<"-->couche cree avec formes suivantes:"<<endl;
  canevas1.afficher(cout);
   
   bool aire = canevas1.aire();        //test pour aire
   cout<<"L'AIRE EST DE: "<<aire<<endl;
}

void Tests::testTranslaterCannevas()
{
  cout<<endl<<" ## TEST TRANSLATION ## "<<endl<<endl;
 
  Canevas canevas1;
  Forme* rect1 = new Rectangle(2,4,1,1);
  Forme* cercle1 = new Cercle(3);
  Forme* carre1 = new Carre();
   
  for(int i=0;i<5;i++)         //fait 5 couches vides
    canevas1.ajouterCouche();
    
  canevas1.activerCouche(2);  //active la couche index 2 donc la 3e couche;
  canevas1.ajouterForme(rect1);  //ajoute forme sur couche active (2)
  
  canevas1.activerCouche(0);  //active la couche 0
  canevas1.ajouterForme(cercle1);  //ajoute 2 formes sur la couche 0
  canevas1.ajouterForme(carre1);
  
  cout<<"-->couche cree avec formes suivantes:"<<endl;
  canevas1.afficher(cout);
  
  canevas1.translater(4,4);           //test pour translater
  
  cout<<"-->TRANSLATION DE 4,4 SUR LA COUCHE ACTIVE"<<endl;
  canevas1.afficher(cout);
}

//-----------------------------------------//
//------- Section pour la validation ------//
//-----------------------------------------//


void Tests::testValidation()
{
  Canevas canevas;
  
  cout<<"Etapes 1 et 2: "<<endl<<endl;  //----------------------------------------
  
  canevas.afficher(cout);
  
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
  cout<<endl<<"Etapes 3 a 5: "<<endl<<endl;  //----------------------------------------

  for(int j=0;j<5;j++)
    canevas.ajouterCouche();
    
  canevas.afficher(cout);
  
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
  cout<<endl<<"Etapes 6 a 9: "<<endl<<endl;  //----------------------------------------
  
  canevas.activerCouche(2);
  
  Forme* cercle1 = new Cercle(5,0,1);
  canevas.ajouterForme(cercle1);
  Forme* carre1 = new Carre(6,1,2);
  canevas.ajouterForme(carre1);
  Forme* rectangle1 = new Rectangle(4,9,2,3);
  canevas.ajouterForme(rectangle1);
  
  canevas.activerCouche(1);
  
  Forme* rectangle2 = new Rectangle(12,3);
  canevas.ajouterForme(rectangle2);
  
  canevas.afficher(cout);
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
  cout<<endl<<"Etapes 10 a 13: "<<endl<<endl;  //----------------------------------------
  
  canevas.activerCouche(0);
  
  Forme* rectangle3 = new Rectangle();
  canevas.ajouterForme(rectangle3);
  Forme* carre2 = new Carre();
  canevas.ajouterForme(carre2);
  Forme* cercle2 = new Cercle();
  canevas.ajouterForme(cercle2);
  
  canevas.activerCouche(2);
  canevas.translater(2,1);
  
  canevas.afficher(cout);
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;

  
  cout<<endl<<"Etapes 14 a 20: "<<endl<<endl;  //----------------------------------------
  
  canevas.activerCouche(0);
  canevas.retirerForme(1);  //retire la 2e forme donc l'index 1
  canevas.reinitialiserCouche(1);
  
  canevas.activerCouche(2);
  canevas.retirerCouche(2);
  
  canevas.activerCouche(4);
  
  canevas.afficher(cout);
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
  
  cout<<endl<<"Etapes 21 a 23: "<<endl<<endl;  //----------------------------------------
  
  canevas.reinitialiser();
  
  canevas.afficher(cout);
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
  cout<<endl<<"Etapes 24 a 27: "<<endl<<endl;  //----------------------------------------
  
  canevas.activerCouche(3);
  
  //canevas.ajouterCouche();
  //canevas.activerCouche(0);
  
  Forme* carre3 = new Carre(10,10,10);
  canevas.ajouterForme(carre3);
  canevas.ajouterForme(nullptr);
  
  canevas.activerCouche(6);
  
  canevas.afficher(cout);
  cout<<"l'aire du canevas est de "<<canevas.aire()<<endl;
  
}





