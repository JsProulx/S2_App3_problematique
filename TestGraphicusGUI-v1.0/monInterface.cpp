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
	monCanevas->afficher(cout);
	
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
	//l'ordre des couches est inverse si mode est vrai et est desinverser si mode est faux
	if (mode)
	{
		Canevas* canevasInverser = new Canevas();
		for (int i = monCanevas->getTaille() - 1; i >= 0; i--)
		{
			canevasInverser->ajouterCouche(); 
			canevasInverser->activerCouche(canevasInverser->getTaille() - 1); 

			for (int j = 0; j < monCanevas->getCouche(i)->getTaille(); j++)
			{
				canevasInverser->ajouterForme(monCanevas->getCouche(i)->getForme(j));
			}
		}

		delete monCanevas;
		monCanevas = canevasInverser;
		
	}
	else
	{
		Canevas* canevasNormal = new Canevas();
		for (int i = monCanevas->getTaille() - 1; i >= 0; i--)
		{
			canevasNormal->ajouterCouche();
			canevasNormal->activerCouche(canevasNormal->getTaille() - 1);

			for (int j = 0; j < monCanevas->getCouche(i)->getTaille(); j++)
			{
				canevasNormal->ajouterForme(monCanevas->getCouche(i)->getForme(j));
			}
		}
		delete monCanevas;
		monCanevas = canevasNormal;
	}
	afficherInterface();
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	monCanevas->translater(deltaX, deltaY);

	afficherInterface();
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

	afficherInterface();
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

	afficherInterface();
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

	afficherInterface();
}


void MonInterface::coucheAjouter()
{

	monCanevas->ajouterCouche();
	
	afficherInterface();
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
	
	afficherInterface();
}


void MonInterface::couchePremiere()
{
	monCanevas->activerCouche(0);
	
	afficherInterface();

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
	afficherInterface();
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
	afficherInterface();
}

void MonInterface::coucheDerniere()
{
	monCanevas->activerCouche(monCanevas->getTaille() - 1);

	afficherInterface();
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

	afficherInterface();
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
	afficherInterface();
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
	afficherInterface();
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
	afficherInterface();
}

void MonInterface::formeDerniere()
{
	for (int i = 0; i < monCanevas->getTaille(); i++)
	{
		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);

			break;
		}
	}
	afficherInterface();
}

void MonInterface::afficherInterface()
{
	setInformation();
	cout << endl << endl;
	monCanevas->afficher(oss);
	dessiner(oss.str().c_str());
	cout << oss.str();
	oss.str("");
}

void MonInterface::setInformation()
{
	info.nbCouches = monCanevas->getTaille();

	for (int i = 0; i < 20; i++)
		info.etatCouche[i] = ' ';

	info.nbFormesCanevas = 0;
	info.aireCanevas = 0;
	info.coucheActive = -1;
	info.nbFormesCouche = 0;
	info.formeActive = -1;
	
	for (int i = 0;i < monCanevas->getTaille();i++)
	{
		info.nbFormesCanevas += monCanevas->getCouche(i)->getTaille();
		info.aireCanevas += monCanevas->getCouche(i)->aireTotale();
		
		if(monCanevas->getCouche(i)->getEtat() == INITIALISEE)
			info.etatCouche[i] = 'i';
		else if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
			info.etatCouche[i] = 'a';
		else if (monCanevas->getCouche(i)->getEtat() == INACTIVE)
			info.etatCouche[i] = 'x';



		if (monCanevas->getCouche(i)->getEtat() == ACTIVE)
		{
			info.coucheActive = i;
			info.nbFormesCouche = monCanevas->getCouche(i)->getTaille();
			info.aireCouche = monCanevas->getCouche(i)->aireTotale();
			info.formeActive = monCanevas->getCouche(i)->getIndexCourrant();

			if (monCanevas->getCouche(i)->getTaille() == 0)
			{
				info.coordX = 0;
				info.coordY = 0;
				info.aireForme = 0;
			}
			else
			{
				info.coordX = monCanevas->getCouche(i)->getForme(monCanevas->getCouche(i)->getIndexCourrant())->getAncrage().x;
				info.coordY = monCanevas->getCouche(i)->getForme(monCanevas->getCouche(i)->getIndexCourrant())->getAncrage().y;
				info.aireForme = monCanevas->getCouche(i)->getForme(monCanevas->getCouche(i)->getIndexCourrant())->aire();
			}
		}
	}

	setInformations(info);
}















































































































































































































































































































































//nerd