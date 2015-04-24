#include "JeuCarte.h"
#include <algorithm>  
#include <ctime>        
#include <cstdlib>   
#include <iostream>


JeuCarte::JeuCarte()
{
   //création des cartes de 2 a 10
   for (int i = 2; i <=10; i++)
   {
      Paquet_.emplace_back(vector < int > {i});
      Paquet_.emplace_back(vector < int > {i});
      Paquet_.emplace_back(vector < int > {i});
      Paquet_.emplace_back(vector < int > {i});
   }

   //création des 3 faces valet dame roi
   for (int i = 0; i < 3; i++)
   {
      Paquet_.emplace_back(vector < int > {10});
      Paquet_.emplace_back(vector < int > {10});
      Paquet_.emplace_back(vector < int > {10});
      Paquet_.emplace_back(vector < int > {10});
   }

   //création des 4 as
   Paquet_.emplace_back(vector < int > {11,1});
   Paquet_.emplace_back(vector < int > {11,1});
   Paquet_.emplace_back(vector < int > {11,1});
   Paquet_.emplace_back(vector < int > {11,1});

   //mélange les cartes
   Melanger();
}

void JeuCarte::Melanger()
{  
  random_shuffle(Paquet_.begin(), Paquet_.end());
}

JeuCarte::~JeuCarte()
{
}

void JeuCarte::Reinitialiser()
{
   for (size_t i = 0; i < Paquet_.size(); i++)
      Paquet_.at(i).reinitialize();
}

Carte JeuCarte::PigerCarte()
{
   srand(time(NULL));
   Melanger();

   int valeur;
   while (Paquet_.at(valeur = (rand() % 52)).piger())
	   
      return Paquet_.at(valeur);
}

int JeuCarte::nbCartesSorte(int valeur)
{
   int i = 0;
   for (size_t i = 0; i < Paquet_.size(); i++)
   {
      if (Paquet_.at(i).piger())
         i++;
   }
   return i;
}

int JeuCarte::NbCartePasPiger()
{
   int i = 0;
   for (size_t i = 0; i < Paquet_.size(); i++)
   {
      if (!Paquet_.at(i).piger())
         i++;
   }
   return i;
}
