#include <stdio.h>
#include "main.h"

int main (int argc, const char * argv[]) {
	int menu;
	bool continuerProgramme = True;
	
	while (continuerProgramme)
	{
		menu = choixMenu();
		
		switch (menu)
		{
			case 1:
				printf("Vous avez choisi de jouer contre un autre humain.\n");
				Othellier othellier;
				initOthellier(&othellier);
				afficheOthellier(&othellier);
				
				break;
			case 2:
				printf("Vous avez choisi de jouer contre un ordinateur.\n");
				break;
			case 3:
				printf("Vous avez choisi de jouer contre un ordinateur.\n");
				break;
			case 4:
				printf("Vous avez choisi d'assister à un match entre deux ordinateurs.\n");
				break;
			case 5:
				printf("Petit joueur...\n");
				printf("À la prochaine !!");
				continuerProgramme = False;
				break;
		}
	}
	return 0;
}
