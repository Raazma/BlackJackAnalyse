#include "Global.h"
#include "JoueurIA.h"
#include <iostream>
using namespace std;


int main()
{
	JeuCarte lejeu;
	JoueurIA un(40 , lejeu);
	JoueurIA deux(AI_COURAGEUX, lejeu);


	while (un.Jouer())
		un.Piger();

	while (deux.Jouer())
		deux.Piger();

	cout << "compte un: " << un.getCompte()<<endl;
	cout << "compte deux: " << deux.getCompte()<<endl;

	//	delete lejeu;
   return 0;
}