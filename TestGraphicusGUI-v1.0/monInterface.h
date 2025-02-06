/********
* Fichier: monInterface.h
* Auteurs: Simon Provencher et Jean-Sébastien Proulx
* Date: 7 fevrier 2025
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"
#include "canevas.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"
#include <fstream>
#include <sstream>

class MonInterface : public GraphicusGUI
{
public:

	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();

	bool ouvrirFichier(const char*) override;
	bool sauvegarderFichier(const char*) override;
	void coucheTranslater(int deltaX, int deltaY) override;
	void ajouterCercle(int x, int y, int rayon) override;
	void ajouterRectangle(int x, int y, int long_x, int long_y) override;
	void ajouterCarre(int x, int y, int cote) override;
	void modePileChange(bool mode) override;
	
	
	void coucheAjouter() override;
	void coucheRetirer() override;
	// Menu Formes
	void retirerForme() override;
	// Menu navigation
	void couchePremiere() override;
	void couchePrecedente() override;
	void coucheSuivante() override;
	void coucheDerniere() override;
	void formePremiere() override;
	void formePrecedente() override;
	void formeSuivante() override;
	void formeDerniere() override;

	void afficherInterface();
	void setInformation();

private:
	Canevas* monCanevas;
	ostringstream oss;
	string contenuOss = "";
	Informations info;

};

#endif // MONINTERFACE_H