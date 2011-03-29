/*
 *  io.h
 *  Roderigo
 */

#ifndef __IO__
#define __IO__

#include "main.h"

void sauvegarderPartie(Othellier *dame, Coup *coup, FILE* fichier_sauvegarde, Joueur *joueur1, Joueur *joueur2);
void chargerPartie(Othellier *dame, Coup *coup, FILE* fichier_sauvegarde, Joueur *joueur1, Joueur *joueur2);
void copierFichier(FILE* temporaire, FILE* sauvegarde);

#endif
