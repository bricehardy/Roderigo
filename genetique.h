/*
 *  genetique.h
 *  Roderigo
 */

#ifndef __GENETIQUE__
#define __GENETIQUE__

#include "main.h"

void initialise_rnd();
double uniforme(double a, double b);

Individu creerIndividu(int test);
Individu reproduireIndividus(Individu homme, Individu femme);
double rosenbrock(Individu homme);
void exterminerIndividu(Individu homme);

Population genese(int n);
Population creerPopulation(int n);
loterie selectionParents(Population pop);
Population nouvelle_generation(Population pop);
void exterminerPopulation(Population pop);

#endif
