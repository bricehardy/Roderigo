#include "entreInfo.h"

/* Fonction qui convertit un caractere en entier et l additionne a un autre entier */ 
int nbEntrer(int n, char c){
	int i;
	/* Verifie si la position entree est valide et si tel est le cas la convertie en entier et la retourne */
	if((n > 0 && n < 9) && ((c >= 'A' && c < 'I') || (c >= 'a' && c < 'i'))){
		if(c >= 'A' && c < 'I')
			i = (n * 10) + ((c - 'A') + 1);
		else if(c >='a' && c < 'i')
			i = (n * 10) + ((c - 'a') + 1);
	}
	return i;
}


/* Fonction qui permet de saisir les noms des joueurs */
void nomJoueur(Joueur *joueur){
	printf("Nom du joueur : ");
	scanf("%s", joueur->nom);
}
