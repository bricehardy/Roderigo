/*
 *  io.c
 *  Roderigo
 */

#include "io.h"

/* Fonction qui permet de sauvegarder la partie dans un fichier */
void sauvegarderPartie(Othellier *dame, Coup *coup, FILE* fichier_sauvegarde, Joueur *joueur1, Joueur *joueur2) {
    fseek(fichier_sauvegarde, 0, SEEK_SET);
    fprintf(fichier_sauvegarde, "%s9\n", joueur1->nom);
    fprintf(fichier_sauvegarde, "%s8\n", joueur2->nom);
    fseek(fichier_sauvegarde, 0, SEEK_END);
    fprintf(fichier_sauvegarde, "%d %d\n",coup->couleur, coup->position);
}

/* Fonction qui permet de charger une partie */
void chargerPartie(Othellier *dame, Coup *coup, FILE* fichier_sauvegarde, Joueur *joueur1, Joueur *joueur2) {
    int c = 0, i = 0;
    char chaine[2] = "";

	for (i = 0 ; i < 16 ; i++){
        joueur1->nom[i] = 0;
        joueur2->nom[i] = 0;
    }

	i = 0;
    c = fgetc(fichier_sauvegarde);

	while (c != '9'){
        joueur1->nom[i] = c;
        c = fgetc(fichier_sauvegarde);
        i++;
    }

	i = 0;
    c = fgetc(fichier_sauvegarde);
    c = fgetc(fichier_sauvegarde);

	while (c != '8'){
        joueur2->nom[i] = c;
        c = fgetc(fichier_sauvegarde);
        i++;
    }

	while (fgets(chaine, 4, fichier_sauvegarde) != NULL) {
        if (fgetc(fichier_sauvegarde) == EOF)
            break;
        else
            fseek(fichier_sauvegarde, -1, SEEK_CUR);

		fscanf(fichier_sauvegarde, "%d %d", &chaine[0], &chaine[1]);
        coup->couleur = (chaine[0]+1)%2;
        coup->position = chaine[1];
        jouerCoup(dame, coup);
    }
}

void copierFichier(FILE* temporaire, FILE* sauvegarde) {
    char chaine[100] = "";

    fseek(temporaire, 0, SEEK_SET);
    fseek(sauvegarde, 0, SEEK_SET);

    while (fgets(chaine, 100, temporaire) != NULL)
        fprintf(sauvegarde, "%s", chaine);
}
