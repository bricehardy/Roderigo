/*
 *  representation.h
 *  Roderigo
 *
 *  Created by Brice Hardy on 02/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __representation__
#define __representation__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOIR     0
#define BLANC    1
#define JOUABLE  2
#define BORD    -1
#define VIDE    -2

#define NORD   -10
#define SUD		10
#define OUEST	-1
#define EST		 1


typedef struct {
	int plateau[100];
	int score[2];
	int materiel;
} Othellier;

typedef struct {
	int position;
	int joueur;
} Coup;

typedef int bool;
enum {False, True};


void initOthellier(Othellier* othellier);
void afficheOthellier(Othellier* othellier);

#endif
