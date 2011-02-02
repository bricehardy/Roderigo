/*********************************************************
 *  main.h
 *  Roderigo
 *
 *  Created by Brice Hardy on 02/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 ********************************************************/

/*********************************************************
*
*	Affiche le Menu
*
*	Retourne le choix du mode de jeu
*
*********************************************************/
int choixMenu() {
	int choixMode;
	choixMode = -1;
	
	while (choixMode < 1 || choixMode > 5) {
		printf("----- Choisissez le mode de jeu -----\n\n");
		printf("1. Humain contre humain\n");
		printf("2. Humain contre ordinateur\n");
		printf("3. Ordinateur contre humain\n");
		printf("4. Ordinateur contre ordinateur\n");
		printf("5. Quitter\n\n");
		printf("Faites votre choix et appuyez sur \"Entrée\"");
		scanf("%i", &choixMode);
	}
	return choixMode;
}