#pragma once
#include "JeuCarte.h"


class JoueurIA
{
public:
   JoueurIA(int risque, JeuCarte & lejeu );
   int getCompte();
   void SetCompte(int valeur);
   bool Jouer();
   bool Depasser();
   void AjouterCarte(Carte carte);
   void Piger();
   ~JoueurIA();

private:
   int Risque_;
   int Compte_;
   JeuCarte * Lejeu_;
   vector<Carte> CartePiger_;
};

