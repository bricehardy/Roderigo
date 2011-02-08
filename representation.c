/*
 *  representation.c
 *  Roderigo
 *
 *  Created by Brice Hardy on 02/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "representation.h"

void initOthellier(Othellier* othellier)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		othellier->plateau[i] = VIDE;
	}

	for (i = 11; i <= 18; i++)
	{
		othellier->plateau[i] = BORD;
	}

	for (i = 21; i <= 81; i = i + 10)
	{
		othellier->plateau[i] = BORD;
	}
	
	for (i = 28; i <= 88; i = i + 10)
	{
		othellier->plateau[i] = BORD;
	}
	
	for (i = 89; i < 88; i++)
	{
		othellier->plateau[i] = BORD;
	}
	
	othellier->plateau[44] = NOIR;
	othellier->plateau[45] = BLANC;
	othellier->plateau[55] = NOIR;
	othellier->plateau[54] = BLANC;
	
	othellier->joueur = NOIR;
	othellier->materiel = 64;
}

void afficheOthellier(Othellier* othellier)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		switch (othellier->plateau[i])
		{
			case NOIR:
				printf("| x |");
				break;
			case BLANC:
				printf("| o |");
				break;
			case JOUABLE:
				printf("| . |");
				break;
			default:
				printf("|   |");
				break;
		}
		if (i % 10 == 9)
		{
			printf("\n");
		}
	}
}