/*
 *  minmax.h
 *  Roderigo
 */

#ifndef __MINMAX__
#define __MINMAX__

#include "main.h"

int comptPossibilites(Othellier *dame, Coup *coup, int couleur, int position);
int mobiliteCouleur(Othellier *dame, Coup *coup, int couleur);
int differenceDeMobilite(Othellier *dame, Coup *coup, int couleur, int position);
int pionsDefinitifs(Othellier *dame);
int nbrePionsCouleur(Othellier *dame, Coup *coup, int couleur);
int coins(Othellier *dame, Coup *coup, int couleur);
int differenceCoins(Othellier *dame, Coup *coup, int couleur);


#endif
