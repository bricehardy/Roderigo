/*
 *  gestion.c
 *  Roderigo
 */

#include "gestion.h"

bool bloque(Othellier *dame, Coup *coup) {
    int i, coups_possibles = 0;

	retablirDamier(dame);
    calculPossibilite(dame, coup);

    for(i = 10; i < (MAX_CASE - 10); i++){
        if (dame->damier[i] == POSSIBLE)
            coups_possibles = coups_possibles + 1;
    }

	/* Si le joueur qui a le trait ne peux pas jouer,
	 on change de joueur
	 */
    if (coups_possibles == 0)
        coup->couleur = !coup->couleur;

	retablirDamier(dame);
	calculPossibilite(dame, coup);

	for(i = 10; i < (MAX_CASE - 10); i++){
		if (dame->damier[i] == POSSIBLE)
			coups_possibles = coups_possibles + 1;
	}

	/* Si cet autre joueur n'a pas de coups possibles lui non plus,
	 la partie est finie
	 */
	if (coups_possibles == 0)
		return True;
    else
        return False;
}

/* Fonction qui simule les coup possible et les enregistre dans le damier */
void calculPossibilite(Othellier *dame, Coup *coup) {
	int position = coup->position;
	int i;

	/* on commence par la premiere case */
	for(i = 10; i < MAX_CASE; i++){
		/* si le coup est légal on affiche dans la case
		 le symbole et on retourne vrai
		 */
		coup->position = i;
		if(legal(dame, coup)){
			dame->damier[coup->position] = POSSIBLE;
		}
	}
	coup->position = position;
}

/* Fonction qui annule un coup legal */
void annulerCoup(Othellier *dame, Coup *coup) {
	int i, j, ok;
	int tab[DIRECTIONS] = {E, O, N, S, NO, NE, SO, SE};

	if(dame->score[BLANC] + dame->score[NOIR] > 4){
		dame->damier[coup->position] = VIDE;
		for(i = 0; i < DIRECTIONS; i++){
			if(coup->retournement[i] > 0){
				ok = coup->position + tab[i];
				for(j = 0; j < coup->retournement[i]; j++){
					dame->damier[ok] = coup->couleur;
					ok += tab[i];
				}
			}
		}
		compterPions(dame);
		retablirDamier(dame);
		coup->couleur = !coup->couleur;
		calculerPossibilites(dame, coup);
	}
}

/* Fonction qui remet un coup annule */
void retablirCoup(Othellier *dame, Coup *coup) {
	dame->damier[coup->position] = coup->couleur;
	retournerPions(dame, coup);
	compterPions(dame);
	retablirDamier(dame);
	coup->couleur = !coup->couleur;
	calculerPossibilites(dame, coup);
}

/* Fonction qui joue le coup qui est légal */
void jouerCoup(Othellier *dame, Coup *coup) {
	dame->damier[coup->position] = coup->couleur;
	retournerPions(dame, coup);
}

int peutJouer(Othellier *dame, Coup *coup, int coul) {
	int i;

	retablirDamier(dame);
	coup->couleur = coul;
	calculerPossibilites(dame, coup);
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE)
			return 1;
	}
	return 0;
}

/* Fonction qui permet de réinitialiser les cases du damier
 pour ne garder que celles occupées par des pions
 */
void retablirDamier(Othellier *dame) {
	int i;
	for (i = 0; i < MAX_CASE; i++) {
		if (dame->damier[i] == POSSIBLE) {
			dame->damier[i] = VIDE;
		}
	}
}

/* Fonction qui vérifie si un coup est legal */
bool legal(Othellier *dame, Coup *coup) {
	int tab[DIRECTIONS] = {E, O, N, S, NO, NE, SO, SE};
	int i, ok;

	/* Si l'endroit où on décide de jouer n'est pas vide */
	if (dame->damier[coup->position] != VIDE)
		return False;

	for(i = 0; i < DIRECTIONS; i++) {
		/* "ok" prend la valeur des 8 cases qui entourent
		 l'emplacement qu'on a choisi
		 */
		ok = coup->position + tab[i];

		/* On regarde si la couleur du pion est différente
		 de la couleur de celui qui a le trait
		 */
		if(dame->damier[ok] == !coup->couleur) {
			while (dame->damier[ok] == !coup->couleur) {
				ok += tab[i];
			}
			
			if(dame->damier[ok] == coup->couleur)
				return True;
		}
	}

	return False;
}

/* Fonction qui retourne les pions */
void retournerPions(Othellier *dame, Coup *coup) {
	/* D'abord on compte les pions */
	int tab[DIRECTIONS] = {E, O, N, S, NO, NE, SO, SE};
	int i, position, ok;
	
	for (i = 0; i < DIRECTIONS; i++) {
		coup->retournement[i] = 0;
		position = coup->position + tab[i];
		
		while (dame->damier[position] == !coup->couleur) {
			coup->retournement[i]++;
			position += tab[i];
		}
		
		if (dame->damier[position] != coup->couleur) {
			coup->retournement[i] = 0;
		}
	}

	/* et on les retourne !! */

	for(i = 0; i < DIRECTIONS; i++) {
		position = coup->position + tab[i];
		
		for(ok = 0; ok < coup->retournement[i]; ok++) {
			dame->damier[position] = !dame->damier[position];
			position += tab[i];
		}
	}
}
