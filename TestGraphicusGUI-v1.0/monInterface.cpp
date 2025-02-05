/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	monCanevas = new Canevas();
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	monCanevas->reinitialiser();
	effacer();
	cout << endl << endl;
	monCanevas->afficher(cout);
	/*ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	
	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());*/
}


bool MonInterface::ouvrirFichier(const char* nomFichier)
{
	return true;
}

bool MonInterface::sauvegarderFichier(const char* nomFichier)
{
	return true;
}

void MonInterface::modePileChange(bool mode)
{

}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	monCanevas->translater(deltaX, deltaY);	

	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	Cercle* cercle = new Cercle(rayon, x, y);
	monCanevas->ajouterForme(cercle);

	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);
			//cout << "index courrant: " << monCanevas->getCouche(i)->getIndexCourrant() << endl;
			break;
		}
	}

	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::ajouterRectangle(int x, int y, int long_x, int long_y)
{
	Rectangle* rectangle = new Rectangle(long_x, long_y, x, y);
	monCanevas->ajouterForme(rectangle);

	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille()-1);
			//cout << "index courrant: " << monCanevas->getCouche(i)->getIndexCourrant() << endl;
			break;
		}
	}

	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	Carre* carre = new Carre(cote, x, y);
	monCanevas->ajouterForme(carre);

	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);
			//cout << "index courrant: " << monCanevas->getCouche(i)->getIndexCourrant() << endl;
			break;
		}
	}

	cout << endl << endl;
	monCanevas->afficher(oss);
	dessiner(oss.str().c_str());

}


void MonInterface::coucheAjouter()
{

	monCanevas->ajouterCouche();
	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::coucheRetirer()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->retirerCouche(i);
			break;
		}
	}
	monCanevas->activerCouche(0);
	cout << endl << endl;
	monCanevas->afficher(cout);
}


void MonInterface::couchePremiere()
{
	monCanevas->activerCouche(0);
	cout << endl << endl;
	monCanevas->afficher(cout);

}

void MonInterface::couchePrecedente()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{	
			if (i != 0)
				monCanevas->activerCouche(i - 1);
			
			break;
		}
	}
	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::coucheSuivante()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			if (i < monCanevas->getTaille()-1)
				monCanevas->activerCouche(i + 1);

			break;
		}
	}
	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::coucheDerniere()
{
	monCanevas->activerCouche(monCanevas->getTaille() - 1);

	cout << endl << endl;
	monCanevas->afficher(cout);
}

//retire la forme courrante de la couche active
void MonInterface::retirerForme()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			//cout << "index courrant: " << monCanevas->getCouche(i)->getIndexCourrant() << endl;
			monCanevas->getCouche(i)->retirerForme(monCanevas->getCouche(i)->getIndexCourrant());      
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);

			cout << "index courrant: " << monCanevas->getCouche(i)->getIndexCourrant() << endl;
			break;
		}
	}

	cout << endl << endl;
	monCanevas->afficher(cout);
}

void MonInterface::formePremiere()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->setIndexCourrant(0);

			break;
		}
	}
}

void MonInterface::formePrecedente()
{

	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			if (monCanevas->getCouche(i)->getIndexCourrant() > 0)
				monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getIndexCourrant() -1);

			break;
		}
	}
}

void MonInterface::formeSuivante()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			if (monCanevas->getCouche(i)->getIndexCourrant() < monCanevas->getCouche(i)->getTaille() -1)
				monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getIndexCourrant() + 1);

			break;
		}
	}
}

void MonInterface::formeDerniere()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->formes->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);

			break;
		}
	}
}


