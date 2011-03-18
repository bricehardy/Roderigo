#include "io.h"

void sauvegarderPartie(Othellier *dame, Coup *coup, FILE* fichierSauvegarde) {
	char* couleur;
	int i;
	char* position;
	char* retournement;
	
	sprintf(position,"%d",coup->position);
	
	if (coup->couleur == NOIR)
		couleur = "NOIR";
	else
		couleur = "BLANC";
	
	fputs(couleur, fichierSauvegarde);
	fputs(":", fichierSauvegarde);
	fputs(position, fichierSauvegarde);
	fputs(";", fichierSauvegarde);
	
	for (i = 0; i < DIRECTIONS; i++) {
		sprintf(retournement,"%d",coup->retournement[i]);
		fputs(retournement, fichierSauvegarde);
		fputs(",", fichierSauvegarde);
	}
	
	fputs("\n", fichierSauvegarde);
	
	printf("fichier sauvegarder");
}
