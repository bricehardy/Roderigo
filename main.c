#include <stdio.h>
#include "main.h"

int main (int argc, const char * argv[]) {
	int menu;
	
	menu = choixMenu();
	
	switch (menu) {
		case 1:
			printf("Vous avez choisi de jouer contre un autre humain.");
			break;
		case 2:
			printf("Vous avez choisi de jouer contre un ordinateur.");
			break;
		case 3:
			printf("Vous avez choisi de jouer contre un ordinateur.");
			break;
		case 4:
			printf("Vous avez choisi d'assister à un match entre deux ordinateurs.");
			break;
		case 5:
			printf("Petit joueur...\n");
			printf("À la prochaine !!");
			return 0;
			break;
	}
	return 0;
}
