/*
 *  structures.h
 *  Roderigo
 */

#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constantes.h"

#ifdef __WIN32__
#define system("clear") system("cls")
#endif

typedef struct Coup Coup;
struct Coup {
	int position;
	int couleur;
	int retournement[DIRECTIONS];
};

typedef struct Othellier Othellier;
struct Othellier {
	int damier[MAX_CASE];
	int score[NB_JOUEURS];
};

typedef struct Joueur Joueur;
struct Joueur {
	char nom[15];
	int type;
	int niveau;
};

typedef struct Partie Partie;
struct Partie {
	int longueur;
	int final;
	Joueur joueur[2];
	Coup coup[MAX_COUPS];
	Othellier othellier;
};

typedef int bool;
enum {False, True};

#endif
