#include "affichage.h"


/* Fonction qui trace les lignes horizontales de l'othellier */
void traceLigne(){
	int i;
	
	for (i = 0; i < (MAX_CASE / 10) - 2; i++)
		printf("*---");
	
	printf("* \n");
    return;
}


/* Fonction qui affiche l'othellier */
void afficheOthellier(Othellier *dame){
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
					printf("| %d\n", k);
					k++;
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
	
	/* affiche le score */
	printf("\tNb de pions de noir = %d\n \tNb de pions de blanc = %d\n", dame->score[NOIR], dame->score[BLANC]); 
	
	return;
}



/* Fonction qui affiche le menu */
void afficheMenu(){
	system("clear");
	
	printf("\t\t\t---- Bienvenue sur OTHELLO ----\n\n");
	printf("Ce projet a ete fait par DIALLO Aboubacar Sidy, HARDY Brice et MA Jhony\n\n");
	
	printf("\t\t.: Faite votre choix :.\n");
	printf("1. Lire les regles du jeu\n");
	printf("2. Jouer contre un autre joueur\n");
	printf("3. Jouer contre l'ordinateur\n");
	printf("4. Recharger une partie enregistree\n");
	printf("5. Quitter\n\n");
	
	printf("Entrez 1, 2, 3, 4 ou 5 pour continuer : ");
	
	return;
}


/* Fonction qui permet de faire un choix dans le menu*/
int choix(int nombre){
	
	if (nombre >= 1 && nombre <= 5)
		return nombre;
	return 0;
}


/* Fonction qui affiche le but du projet et quelques regles du jeu */
void afficheRegles(){	
	/* But du projet */
	printf("\n\t\t\t ----- But du projet -----\n\n");
	printf("Ce programme est un projet a realiser pour notre deuxieme annee de licence de mathematiques informatique.\n\n");
	printf("Il s'agit d'un jeu connu sous le nom d'Othello ou Reversi.\n");
	printf("Ci-dessous vous pouvez avoir un apercu des fonctionnalites demandees :\n");
	printf("- La position de depart doit etre respectee (les 2 couleurs se croisent).\n");
	printf("- Les pions noirs doivent commencer.\n");
	printf("- Chaque joueur doit etre identifie par son nom.\n");
	printf("- Un indicateur doit preciser quel joueur a le trait.\n");
	printf("- Le format e utiliser pour indiquer un coup a jouer doit etre de la forme 'a1'.\n");
	printf("- A chaque instant de la partie le nombre de pion de chaque joueur doit etre affiche.\n");
	printf("- L'ensemble des coups possibles pour le joueur ayant le trait doit etre affiche.\n");
	printf("- Le programme doit detecter lui-meme la fin de partie.\n");
	printf("- Une fonction 'Annuler' et ('Refaire') doit être disponible.\n");
	printf("- Fonction de sauvegarde et de chargement de la partie.\n");
	printf("- Possibilite de jouer contre l'ordinateur avec une difficulte variable.\n\n");
	printf("En plus, on peut realiser :\n");
	printf("- Une interface graphique (pour sortir du terminal...) \n\n");
	
	/* Regles du jeu */
	printf("\t\t\t ----- Les regles -----\n\n");
	printf("Othello est un jeu de strategie a deux joueurs : Noir et Blanc. Il se joue sur un plateau unicolore de 64 cases, 8 sur 8, appele othellier. Ces joueurs disposent de 64 pions bicolores, noirs d'un cote et blancs de l'autre. Par commodite, chaque joueur a devant lui 32 pions mais ils ne lui appartiennent pas et il doit en donner a son adversaire si celui-ci n'en a plus. Un pion est noir si sa face noire est visible et blanc si sa face blanche est sur le dessus.\n\n");
	printf("\t .: But du jeu :.\n");
	printf("Avoir plus de pions de sa couleur que l'adversaire a la fin de la partie. Celle-ci s'acheve lorsque aucun des deux joueurs ne peut plus jouer de coup legal. Cela intervient generalement lorsque les 64 cases sont occupees.\n\n");
	printf("\t .: Position de depart :.\n");
	printf("Au debut de la partie, deux pions noirs sont places en e4 et d5 et deux pions blancs sont places en d4 et e5.\n\n");
	printf("\t .: Fin de la partie :.\n");
	printf("La partie est terminee lorsque aucun des deux joueurs ne peut plus jouer. Cela arrive generalement lorsque les 64 cases sont occupees. Mais il se peut qu'il reste des cases vides où personne ne peut plus jouer : par exemple lorsque tous les pions deviennent d'une meme couleur apres un retournement.\n");
	
	return;
}
