/*
 *  gestion.c
 *  Roderigo
 *
 *  Created by Brice Hardy on 09/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "gestion.h"

int choixMenu()
{
	int choixMode;
	choixMode = -1;
	
	while (choixMode < 1 || choixMode > 5) {
		printf("----- Choisissez le mode de jeu -----\n\n");
		printf("1. Humain contre humain\n");
		printf("2. Humain contre ordinateur\n");
		printf("3. Ordinateur contre humain\n");
		printf("4. Ordinateur contre ordinateur\n");
		printf("5. Quitter\n\n");
		printf("Faites votre choix et appuyez sur \"Entrée\"\n");
		scanf("%i", &choixMode);
		printf("\n");
	}
	return choixMode;
}



int estJouable(Othellier* othellier, Coup coup)
{
	int directions[8] = {NORD + OUEST, NORD, NORD + EST, OUEST, EST, SUD + OUEST, SUD, SUD + EST};
	int i;
	for (i = 0; i < 8; i++)
	{
		if ((othellier->plateau[coup.position + directions[i]] != coup.joueur) && othellier->plateau[i] != BORD)
		{
			coup.position = coup.position + directions[i];
			estJouable(othellier, coup);
		}
		else
		{
			if (othellier->plateau[coup.position] == VIDE)
				return othellier->plateau[coup.position] = JOUABLE;
			break;
		}
		
	}
}
