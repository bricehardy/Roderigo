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

	for (i = 0; i < 10; i++)
	{
		othellier->plateau[i] = BORD;
	}
	
	for (i = 10; i < 100; i++) {
		if (i % 10 == 0 || i % 10 == 9 || i >= 90)
		{
			othellier->plateau[i] = BORD;
		}
		else
		{
			othellier->plateau[i] = VIDE;
		}
	}
	
	
	othellier->plateau[44] = NOIR;
	othellier->plateau[45] = BLANC;
	othellier->plateau[55] = NOIR;
	othellier->plateau[54] = BLANC;
	
	othellier->score[NOIR] = 2;
	othellier->score[BLANC] = 2;
	othellier->materiel = 60;
}

void afficheOthellier(Othellier* othellier)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		switch (othellier->plateau[i])
		{
			case NOIR:
				printf("| X |");
				break;
			case BLANC:
				printf("| O |");
				break;
			case JOUABLE:
				printf("| . |");
				break;
			default:
				if (i >= 1 && i < 9)
				{
					printf("| %c |", 'A' + i - 1);
				}
				else if (i >= 91 && i < 99)
				{
					printf("| %c |", 'A' + i - 91);
				}
				else if (i % 10 == 9 && i != 9 && i != 99)
				{
					printf("| %d |", (i - 9) / 10);
				}
				else if (i % 10 == 0 && i != 0 && i != 90)
				{
					printf("| %d |", i / 10);
				}
				else
				{
					printf("|   |");
				}
				break;
		}
		if (i % 10 == 9)
		{
			printf("\n");
		}
	}
	printf("\n\nPions :\nNOIR  : %d\nBLANC : %d\n\n", othellier->score[NOIR], othellier->score[BLANC]);
}
