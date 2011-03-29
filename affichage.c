/*
 *  affichage.c
 *  Roderigo
 */

#include "affichage.h"

void afficherMenu(){
	system("clear");

	printf("\t\t\t---- Bienvenue sur Roderigo ----\n\n");
	printf("Ce projet a ete fait par DIALLO Aboubacar Sidy, HARDY Brice et MA Jhonny\n\n");

	printf("\t\t.: Faites votre choix :.\n");
	printf("1. Lire les règles du jeu\n");
	printf("2. Jouer contre un autre joueur\n");
	printf("3. Jouer contre l'ordinateur\n");
	printf("4. Recharger une partie enregistrée\n");
	printf("5. Quitter\n\n");

	printf("Entrez 1, 2, 3, 4 ou 5 pour continuer : ");
}

void afficherRegles(){	
	/* But du projet */
	printf("\n\t\t\t ----- But du projet -----\n\n");
	printf("Ce programme est un projet à réaliser pour notre deuxième année de licence de mathématiques informatique.\n\n");
	printf("Il s'agit d'un jeu connu sous le nom d'Othello ou Reversi.\n");
	printf("Ci-dessous vous pouvez avoir un apercu des fonctionnalités demandées :\n");
	printf("- La position de départ doit être respectée (les 2 couleurs se croisent).\n");
	printf("- Les pions noirs doivent commencer.\n");
	printf("- Chaque joueur doit être identifié par son nom.\n");
	printf("- Un indicateur doit préciser quel joueur a le trait.\n");
	printf("- Le format à utiliser pour indiquer un coup à jouer doit être de la forme 'a1'.\n");
	printf("- À chaque instant de la partie, le nombre de pion de chaque joueur doit être affiché.\n");
	printf("- L'ensemble des coups possibles pour le joueur ayant le trait doit être affiché.\n");
	printf("- Le programme doit détecter de lui-meme la fin de la partie.\n");
	printf("- Une fonction \"Annuler\" et \"Refaire\" doit être disponible.\n");
	printf("- Fonction de sauvegarde et de chargement de la partie.\n");
	printf("- Possibilité de jouer contre l'ordinateur avec une difficulté variable.\n\n");
	printf("En plus, on peut réaliser :\n");
	printf("- Une interface graphique (pour sortir du terminal...) \n\n");

	/* Regles du jeu */
	printf("\t\t\t ----- Les règles -----\n\n");
	printf("Othello est un jeu de stratégie à deux joueurs : Noir et Blanc. Il se joue sur un plateau unicolore de 64 cases, 8 sur 8, appelé othellier. Ces joueurs disposent de 64 pions bicolores, noirs d'un côté et blancs de l'autre. Par commodité, chaque joueur a devant lui 32 pions mais ils ne lui appartiennent pas et il doit en donner a son adversaire si celui-ci n'en a plus. Un pion est noir si sa face noire est visible et blanc si sa face blanche est sur le dessus.\n\n");
	printf("\t .: But du jeu :.\n");
	printf("Avoir plus de pions de sa couleur que l'adversaire à la fin de la partie. Celle-ci s'achève lorsqu'aucun des deux joueurs ne peut plus jouer de coup légal. Cela intervient généralement lorsque les 64 cases sont occupées.\n\n");
	printf("\t .: Position de départ :.\n");
	printf("Au début de la partie, deux pions noirs sont placés en e4 et d5 et deux pions blancs sont placés en d4 et e5.\n\n");
	printf("\t .: Fin de la partie :.\n");
	printf("La partie est terminée lorsqu'aucun des deux joueurs ne peut plus jouer. Cela arrive généralement lorsque les 64 cases sont occupées. Mais il se peut qu'il reste des cases vides où personne ne peut plus jouer : par exemple lorsque tous les pions deviennent d'une même couleur après un retournement.\n");
}

/* Fonction qui affiche l'othellier */
void afficheOthellier(Othellier *dame, Joueur *joueur1, Joueur *joueur2) {
	int i, j, k;

	j = k = 1;

	printf("    a   b   c   d   e   f   g   h\n");
	for(i = 10; i < MAX_CASE; i++){
		switch(dame->damier[i]){
			case BORD:
				if(i % 10 == 0 && i < 90){
					printf("  ");
					traceLigne();
					printf("%d ", j);
					j++;
				}
				else if(i < 90 && i % 10 == 9){
					printf("| %d", k);
					if(i == 29)
						printf("\t\ti. pour annuler un coup");
					if(i == 39)
						printf("\t\tj. pour retablir un coup");
					if(i == 49)
						printf("\t\ts. pour enregistrer la partie en cours");
					if(i == 59)
						printf("\t\tl. pour charger une nouvelle partie");
					if(i == 69)
						printf("\t\tq. pour quitter la partie");
					k++;
					printf("\n");
				}
				break;
			case NOIR:
				printf("| x ");
				break;
			case BLANC:
				printf("| o ");
				break;
			case POSSIBLE:
				printf("| . ");
				break;
			default:
				printf("|   ");
				break;
		}
	}
	printf("  ");
	traceLigne();
	printf("    a   b   c   d   e   f   g   h\n\n");

	/* affiche le score et les noms des joueurs */
	printf("\tNb de pions de %s (x) = %d\n \tNb de pions de %s (o) = %d\n\n", joueur1->nom, dame->score[NOIR], joueur2->nom, dame->score[BLANC]); 
}

/* Fonction qui trace les lignes horizontales de l'othellier */
void traceLigne(){
	int i;

	for (i = 0; i < (MAX_CASE / 10) - 2; i++)
		printf("*---");

	printf("* \n");
}
