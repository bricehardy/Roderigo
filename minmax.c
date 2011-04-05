#include "minmax.h"

/* Compte les possibilites du joueur adverse a une position donnee */
int comptPossibilites(Othellier *dame, Coup *coup, int couleur, int position) {
	int i, compt;
	
	coup->position = position;
	coup->couleur = couleur;
	
	joue_coup(dame, coup);
	retablirDamier(dame);
	
	coup->couleur = !coup->couleur;			
	affichePossibilite(dame, coup);
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE)
			compt++;
	}
	annule_coup(dame, coup);
	return compt;
}


/* Retourne la mobilite (le nombre de possibilites) du joueur */
int mobiliteCouleur(Othellier *dame, Coup *coup, int couleur) {
	int i, compt = 0;
	
	coup->couleur = couleur;
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE)
			compt++;
	}
	
	return compt;
}


/* Retourne la mobilite */
int differenceDeMobilite(Othellier *dame, Coup *coup, int couleur, int position) {
	int mobilite, possibilite, possibleAdverse;
	
	coup->couleur = couleur;
	coup->position = position;
	possibilite = mobiliteCouleur(dame, coup, coup->couleur);
	possibleAdverse = comptPossibilites(dame, coup, coup->couleur, coup->position);
	
	mobilite = possibilite - possibleAdverse;
	return mobilite;
}


/* Retourne le nombre de pions du damier */
int pionsDefinitifs(Othellier *dame) {
	int i, compt;
	
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == NOIR || dame->damier[i] == BLANC)
			compt++;
	}
	return compt;
}


/* Retourne le nombre de pions du joueur ayant le trait */
int nbrePionsCouleur(Othellier *dame, Coup *coup, int couleur) {
	int i, compt = 0;
	
	coup->couleur = couleur;
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == coup->couleur)
			compt++;
	}
	return compt;
}


/* Compte le nombre de coins qu'a un joueur */
int coins(Othellier *dame, Coup *coup, int couleur) {
	int compt = 0;
	
	coup->couleur = couleur;
	if(dame->damier[11] == coup->couleur)
		compt++;
	if(dame->damier[18] == coup->couleur)
		compt++;
	if(dame->damier[81] == coup->couleur)
		compt++;
	if(dame->damier[88] == coup->couleur)
		compt++;
	return compt;
}


/* Fait la difference entre le nombre de coins du joueur et de son adversaire */
int differenceCoins(Othellier *dame, Coup *coup, int couleur) {
	int coinsCouleur, coinsAdverse, difference;
	
	coup->couleur = couleur;
	coinsCouleur = coins(dame, coup, coup->couleur);
	coinsAdverse = coins(dame, coup, !coup->couleur);
	
	difference = coinsCouleur - coinsAdverse;
	return difference;
}


/* Recherche du coup qui donne le plus de pions
 int max(Othellier *dame, Coup *coup){
 int best, bCoup = 0, i, bPosition;
 
 for(i = 10; i < (MAX_CASE - 10); i++){
 if(dame->damier[i] == POSSIBLE){
 coup->position = i;
 joue_coup(dame, coup);
 best = dame->score[coup->couleur];
 if(bCoup < best){
 bCoup = best;
 bPosition = i;
 }
 annule_coup(dame, coup);
 }
 }
 return bPosition;
 }*/


/* Recherche du coup qui donne le moins de possibilite au joueur adverse
 int moinDeCoup(Othellier *dame, Coup *coup){
 int i, j, maxCase, minCase = 64, bPosition;
 
 for(i = 10; i < (MAX_CASE - 10); i++){
 if(dame->damier[i] == POSSIBLE){
 coup->position = i;
 joue_coup(dame, coup);
 retablirDamier(dame);
 
 coup->couleur = !coup->couleur;
 
 affichePossibilite(dame, coup);
 maxCase = 0;
 for(j = 10; j < (MAX_CASE - 10); j++){
 if(dame->damier[i] == POSSIBLE)
 maxCase++;
 }
 if(minCase > maxCase){
 
 bPosition = i;
 minCase = maxCase;
 }
 annule_coup(dame, coup);
 }
 }
 return bPosition;
 }
 */