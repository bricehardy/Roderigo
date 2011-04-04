/*
 *  minmax.c
 *  Roderigo
 */

#include "minmax.h"

/* Recherche du coup qui donne le plus de pions */
int meilleurCoup(Othellier *dame, Coup *coup) {
	int bCoup = 0, best, i, bPosition;
	
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE){
			coup->position = i;
			jouerCoup(dame, coup);
			best = dame->score[coup->couleur];
			if(bCoup < best){
				bCoup = best;
				bPosition = i;
			}
			annulerCoup(dame, coup);
		}
	}
	return bPosition;
}

/* Recherche du coup qui donne le moins de possibilités au joueur adverse */
int pireCoup(Othellier *dame, Coup *coup) {
	int i, j, maxCase, minCase = 0, bPosition;
	
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE){
			coup->position = i;
			jouerCoup(dame, coup);
			retablirDamier(dame);
			
			coup->couleur = !coup->couleur;
			
			calculerPossibilites(dame, coup);
			maxCase = 0;
			for(j = 10; j < (MAX_CASE - 10); j++){
				if(dame->damier[i] == POSSIBLE)
					maxCase++;
			}
			if(minCase < maxCase){
				bPosition = i;
				minCase = maxCase;
			}
			annulerCoup(dame, coup);
		}
	}
	return bPosition;
}
