/*
 *  infos.c
 *  Roderigo
 */

#include "infos.h"

/* Fonction qui compte les pions et enregistre le score */
void compterPions(Othellier *dame) {
	int i;

	dame->score[NOIR] = 0;
	dame->score[BLANC] = 0;
	for (i = 10; i < (MAX_CASE - 10); i++){
		if (dame->damier[i] == NOIR)
			dame->score[NOIR] ++;
		else if (dame->damier[i] == BLANC)
			dame->score[BLANC] ++;
	}
}

/* Fonction qui permet de saisir les noms des joueurs */
void nomJoueur(Joueur *joueur) {
	printf("Nom du joueur : ");
	scanf("%s", joueur->nom);
}

/* Fonction qui convertit un caractère en entier et l additionne à un autre entier */
int nbEntrer(int n, char c) {
	int i;

	/* Verifie si la position entree est valide et si tel est le cas, la convertie en entier et la retourne */
	if((n > 0 && n < 9) && ((c >= 'A' && c < 'I') || (c >= 'a' && c < 'i'))){
		if(c >= 'A' && c < 'I')
			i = (n * 10) + ((c - 'A') + 1);
		else if(c >='a' && c < 'i')
			i = (n * 10) + ((c - 'a') + 1);
	}
	return i;
}

/* Fonction qui simule les coup possible et les enregistre dans le damier */
void calculerPossibilites(Othellier *dame, Coup *coup) {
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
