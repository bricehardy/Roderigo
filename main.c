#include "structure.h"

int main(){
	Othellier dame;
	Joueur joueur1, joueur2;
	Coup coup;
	int nombre, fonction;
	bool continuerPartie = True;
	
	afficheMenu();
	scanf("%d", &nombre);
	fonction = choix(nombre);
	
	if (!fonction)
		printf("Choix incorrect");
	else{
		switch(fonction){
			case 1:
				afficheRegles();
				break;
			case 2:
				while (continuerPartie) {
					regroupe(&dame, &coup, &joueur1, &joueur2);
					printf("Continuer à jouer ? (1 OUI, 0 NON\n");
					scanf("%d", &continuerPartie);
					printf("\n");
				}
				
				break;
			case 3:
				printf("Option indisponible pour l'instant");
				break;
			case 4:
				printf("Option indisponible pour l'instant");
				break;
			case 5:
				printf("Petit joueur!!!");
				break;
		}
	}
	
	printf("\n");
	return 0;
}
