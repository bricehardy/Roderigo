/*
 *  main.h
 *  Roderigo
 */

#ifndef __MAIN__
#define __MAIN__


#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "affichage.h"
#include "gestion.h"
#include "init.h"
#include "io.h"
#include "infos.h"

int main (int argc, const char * argv[]);
int choixMenu(int nombre);

void humainVShumain(Othellier *dame, Coup *coup, Joueur *joueur1, Joueur *joueur2, int load);

#endif
