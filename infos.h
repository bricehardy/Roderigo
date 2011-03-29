/*
 *  infos.h
 *  Roderigo
 */

#ifndef __INFOS__
#define __INFOS__

#include "main.h"

int nbEntrer(int n, char c);

void compterPions(Othellier *dame);
void nomJoueur(Joueur *joueur);
void calculerPossibilites(Othellier *dame, Coup *coup);

#endif
