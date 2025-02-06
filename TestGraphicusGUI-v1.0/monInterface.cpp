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
	string line;
	//on reset le cannevas courant
	reinitialiserCanevas();
	//on ouvre le fichier
	ifstream fichier(nomFichier);
	if (!fichier.is_open())
	{
		cerr << "Erreur: impossible d'ouvrir le fichier " << nomFichier << endl;
		return false;
	}
	//on prend le contenu du fichier et on le met dans le oss
	while (getline(fichier, line))
	{
		istringstream iss(line);		//met la ligne dans un flux
		char type;
		iss >> type;				//prend le premier caractère de la ligne
		switch (type) {
			case 'L':
				monCanevas->ajouterCouche();
				break;
			case 'R':
			{
				monCanevas->activerCouche(monCanevas->getTaille() - 1);
				int x, y, largeur, hauteur;
				//Lire chaque élément séparé par des espaces
				iss >> x >> y >> largeur >> hauteur;
				Forme* rectangle = new Rectangle(largeur,hauteur,x,y);
				monCanevas->ajouterForme(rectangle);
				break;
			}
			case 'K':
			{
				monCanevas->activerCouche(monCanevas->getTaille() - 1);
				int x, y, cote;
				iss >> x >> y >> cote;
				Forme* carre = new Carre(cote, x, y);
				monCanevas->ajouterForme(carre);
				break;
			}
			case 'C':
			{
				monCanevas->activerCouche(monCanevas->getTaille() - 1);
				int x, y, rayon;
				iss >> x >> y >> rayon;
				Forme* cercle = new Cercle(rayon, x, y);
				monCanevas->ajouterForme(cercle);
				break;
			}
			default :
				break;

		}
		oss << line << endl;		//pour afficher a l'ecran
	}
	//on repasse dans le toutes les lignes pour activer/desactiver les couches
	while (getline(fichier, line))
	{
		istringstream iss(line);
		char type;
		iss >> type;
		switch (type) {
		case 'L':
		{
			char etat;
			iss >> etat;
			if (etat == 'a')
			{
				monCanevas->activerCouche(monCanevas->getTaille() - 1);
			}
			break;
		}
		default:
			break;
		}
	}
	dessiner(oss.str().c_str());
	oss.str("");
	//on ferme le fichier
	fichier.close();

	return true;
}

bool MonInterface::sauvegarderFichier(const char* nomFichier)
{
	ofstream fichier(nomFichier);
	if (!fichier.is_open())
	{
		cerr << "Erreur: impossible d'ouvrir le fichier " << nomFichier << endl;
		return false;
	}
	//affiche oss
	cout << "contenu du oss"<<endl<<contenuOss;
	//on met le contenu du oss dans le fichier
	fichier << contenuOss;
	fichier.close();

	return true;
}

void MonInterface::modePileChange(bool mode)
{
	//l'ordre des couches est inverse si mode est vrai et est desinverser si mode est faux
	if (mode)
	{
		cout << "Mode pile active" << endl;
		Canevas* canevasInverse = new Canevas();
		for (int i = monCanevas->getTaille() - 1;i >= 0; i--)
		{
			canevasInverse->ajouterCouche();
			for (int j = monCanevas->getCouche(i)->getTaille() - 1;j >= 0;j--)
			{
				canevasInverse->activerCouche(canevasInverse->getTaille() - 1);
				canevasInverse->ajouterForme(monCanevas->getCouche(i)->retirerForme(j));
			}
		}
		//canevasInverse->afficher(cout);

		delete monCanevas;
		monCanevas = canevasInverse;
	}
	else
	{
		cout << "Mode pile desactive" << endl;
		Canevas* canevasNormal = new Canevas();
		for (int i = monCanevas->getTaille() - 1; i >= 0; i--)
		{
			canevasNormal->ajouterCouche();
			for (int j = monCanevas->getCouche(i)->getTaille() - 1; j >= 0; j--)
			{
				canevasNormal->activerCouche(canevasNormal->getTaille() - 1);
				canevasNormal->ajouterForme(monCanevas->getCouche(i)->retirerForme(j));

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

	cout << endl << endl;
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

	cout << endl << endl;
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

	cout << endl << endl;
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

	cout << endl << endl;
	afficherInterface();

}


void MonInterface::coucheAjouter()
{
	monCanevas->ajouterCouche();
	monCanevas->getCouche(monCanevas->getTaille() - 1)->afficher(cout);
	cout << endl << endl;
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
	cout << endl << endl;
	afficherInterface();
}


void MonInterface::couchePremiere()
{
	monCanevas->activerCouche(0);
	cout << endl << endl;
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
	cout << endl << endl;
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
	cout << endl << endl;
	afficherInterface();
}

void MonInterface::coucheDerniere()
{
	monCanevas->activerCouche(monCanevas->getTaille() - 1);

	cout << endl << endl;
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

	cout << endl << endl;
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
			monCanevas->getCouche(i)->setIndexCourrant(monCanevas->getCouche(i)->getTaille() - 1);

			break;
		}
	}
}
void MonInterface::afficherInterface()
{
	setInformation();
	cout << endl << endl;
	monCanevas->afficher(oss);
	dessiner(oss.str().c_str());
	cout << oss.str();
	contenuOss = oss.str();
	oss.str("");
}
void MonInterface::setInformation()
{
	info.nbCouches = monCanevas->getTaille();

	for (int i = 0;i < monCanevas->getTaille();i++)
	{
		info.nbFormesCanevas += monCanevas->getCouche(i)->getTaille();
		info.aireCanevas += monCanevas->getCouche(i)->aireTotale();
		if (monCanevas->getCouche(i)->getEtat() == INITIALISEE)
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
			info.coucheActive = monCanevas->getCouche(i)->getIndexCourrant();

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