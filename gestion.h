/*
 *  gestion.h
 *  Roderigo
 */

#ifndef __GESTION__
#define __GESTION__

#include "main.h"
#include "infos.h"

bool bloque(Othellier *dame, Coup *coup);
bool legal(Othellier *dame, Coup *coup);

void calculPossibilite(Othellier *dame, Coup *coup);
void annulerCoup(Othellier *dame, Coup *coup);
void retablirCoup(Othellier *dame, Coup *coup);
void jouerCoup(Othellier *dame, Coup *coup);
void retablirDamier(Othellier *dame);
void retournerPions(Othellier *dame, Coup *coup);

int peutJouer(Othellier *dame, Coup *coup, int coul);

#endif
