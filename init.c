/*
 *  init.c
 *  ProjetInfo
 *
 *  Created by Brice Hardy on 16/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "init.h"

/* Fonction qui initialise le damier en debut de partie */
void initialiserOthellier(Othellier *dame){
	int i;
	
	for (i = 0; i < MAX_CASE; i++){
		if ((i % 10 == 0) || (i < 10) || (i % 10 == 9) || (i > 89))
			dame->damier[i] = BORD;
		else
			dame->damier[i] = VIDE;
	}
	
	dame->damier[44] = BLANC; 
	dame->damier[45] = NOIR;
	dame->damier[54] = NOIR;
	dame->damier[55] = BLANC;
	
	dame->score[NOIR] = 2;
	dame->score[BLANC] = 2;
	
	return;
}
