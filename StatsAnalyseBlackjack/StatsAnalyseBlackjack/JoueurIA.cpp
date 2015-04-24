#include "JoueurIA.h"


JoueurIA::JoueurIA(int risque, JeuCarte  &lejeu) :Risque_(risque), Lejeu_(&lejeu)
{
}
JoueurIA::~JoueurIA()
{
}
int JoueurIA::getCompte()
{
   int compte = 0;
   for each (Carte carte in CartePiger_)
   {
      if (carte.getValue() + compte > 21)
         compte += carte.getValue(1);
      else
         compte += carte.getValue();
   }
   return compte;
}
void JoueurIA::SetCompte(int valeur)
{
   Compte_ = valeur;
}

bool JoueurIA::Jouer()
{
   
   int minValue;//valeur minimale pour que le compte depasse 21
   float probability;
   if ((getCompte() + 11) <= 21) // Peu importe la carte piger on ne depasse pas 21 donc on pige Sans se pauser de question
      return true;
   else
   {
      minValue = 22 - getCompte();
      if (minValue != 11) //Si les valeur minimale pour depasser est 11 il ne reste que la possibiliter de piger un as
      while (minValue != 13)
      {
         if (minValue <= 10)
            probability += Lejeu_ ->nbCartesSorte(minValue);
         else
            probability += Lejeu_->nbCartesSorte(10);

         minValue++;
      }
      else //les probabiliter son simplement les 4 as
         probability = Lejeu_->nbCartesSorte(11);
      // met les probabiliter en pourcentage avant de verifier si il est  > ou < ou = au pourcentage pour piger
      if ((100 - ((probability / Lejeu_->NbCartePasPiger()) * 100)) >= Risque_)
         return true;

      return false;
   }
}

void JoueurIA::AjouterCarte(Carte carte)
{
	//if (carte.getValue() <= 11 && carte.getValue() >= 1)
  // CartePiger_.emplace_back(carte);  
}

bool JoueurIA::Depasser()
{
   return getCompte() > 21 ? true : false;  
}
void JoueurIA::Piger()
{
	AjouterCarte(Lejeu_->PigerCarte());
	Lejeu_->Melanger();
}
