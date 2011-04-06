/*
 *  minmax.h
 *  Roderigo
 */

#ifndef __MINMAX__
#define __MINMAX__

#include "main.h"

int alphaBeta(int profondeur, int alpha, int beta);
int coins(Othellier *dame, Coup *coup, int couleur);
int compterPossibilites(Othellier *dame, Coup *coup, int couleur, int position);
int diffBords(Othellier *dame, Coup *coup, int couleur);
int differenceCoins(Othellier *dame, Coup *coup, int couleur);
int differenceDeMobilite(Othellier *dame, Coup *coup, int couleur, int position);
int differencePions(Othellier *dame, Coup *coup, int couleur);
int eval(Othellier *dame, Coup *coup);
int nbreBordsCouleur(Othellier *dame, Coup *coup, int couleur);
int nbrePionsAdverse(Othellier *dame, Coup *coup, int couleur);
int nbrePionsCouleur(Othellier *dame, Coup *coup, int couleur);
int mobiliteCouleur(Othellier *dame, Coup *coup, int couleur);
int pionsDefinitifs(Othellier *dame, Coup *coup, int couleur);

#endif
