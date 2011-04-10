/*
 *  genetique.c
 *  Roderigo
 */

#include "genetique.h"

void initialise_rnd() {
	srand(time(0));
}

double uniforme(double a, double b) {
	double r;
	r = rand() / (1.0 + RAND_MAX);
	
	return a + (b-a) * r;
}

Individu creerIndividu(int test) {
	Individu nouveau;
	nouveau = (Individu) malloc(sizeof(struct Individu));
	
	if (test) {
		nouveau->gene[0] = uniforme(0, 2);
		nouveau->gene[1] = uniforme(0, 2);
		nouveau->rosenbrock = rosenbrock(nouveau);
		nouveau->fitness = exp(-10 * nouveau->rosenbrock);
	}
	return nouveau;
}

Individu reproduireIndividus(Individu homme, Individu femme) {
	int g, pere;
	Individu enfant = creerIndividu(0); /* Car on souhaite définir les caractéristiques du fils nous-même */
	double poids[TAILLE_GENOME];
	double biais = homme->fitness/(homme->fitness + femme->fitness);
	double croisement, mutation;
	
	if (uniforme(0, 1) < croisement) {
		for(g = 0; g < TAILLE_GENOME; g++)
			poids[g] = uniforme(0, 1);
	}
	else {
		pere = uniforme(0, 1) <= biais ? 1.0:0.0;
		for(g=0; g<TAILLE_GENOME; g++)
			poids[g] = pere;
	}
	
	for(g = 0; g < TAILLE_GENOME; g++) {
		enfant->gene[g] = poids[g] * homme->gene[g] + (1-poids[g]) * femme->gene[g];
		if(uniforme(0, 1) < mutation)
			enfant->gene[g] = uniforme(0, 2);
	}
	enfant->rosenbrock = rosenbrock(enfant);
	enfant->fitness = exp(-10 * enfant->rosenbrock);
	
	return enfant;
}

double rosenbrock(Individu homme) {
	double x = homme->gene[0], y = homme->gene[1];
	return (1-x)*(1-x) + 100 * (y-x*x)*(y-x*x);
}

void exterminerIndividu(Individu homme) {
	if(homme)
		free(homme);
}

Population genese(int n) {
	Population pop;
	int man;
	
	pop=creerPopulation(n);
	
	for(man=0; man<n; man++){
		pop->genome[man] = creerIndividu(1);
		pop->fitness += pop->genome[man]->fitness;
	}
	
	return pop;
}

Population creerPopulation(int n) {
	Population pop;
	
	if(n%2) n = n+1;
	
	pop = (Population) malloc(sizeof(struct Population));
	pop->taille = n;
	pop->fitness = 0.0;
	pop->genome = (Individu *) malloc(n * sizeof(Individu));
	
	return pop;
}

loterie selectionParents(Population pop) {
	int p, man;
	double needle, mass;
	loterie tirage = (loterie) malloc(pop->taille * sizeof(int));
	
	for(p=0; p < pop->taille; p++){
		needle = uniforme(0,1);
		mass = 0;
		man = 0;
		while(mass < needle * pop->fitness && man < pop->taille){
			mass += pop->genome[man]->fitness;
			man ++;
		}
		tirage[p] = man-1;
	}
	return tirage;
}

Population nouvelle_generation(Population pop) {
	
	Population newpop = creerPopulation(pop->taille);
	loterie tirage = selectionParents(pop);
	int man, pere, mere;
	
	for(man=0; man < pop->taille; man+=2){
		pere = tirage[man];
		mere = tirage[man + 1];
		newpop->genome[man] = reproduireIndividus(pop->genome[pere], pop->genome[mere]);
		newpop->genome[man+1] = reproduireIndividus(pop->genome[pere], pop->genome[mere]);
		newpop->fitness += newpop->genome[man]->fitness + newpop->genome[man + 1]->fitness ;		
	}
	
	free(tirage);
	return newpop;
}

void exterminerPopulation(Population pop) {
	int man;
	
	for(man=0; man < pop->taille; man++){
		exterminerIndividu(pop->genome[man]);
	}
	free(pop->genome);
	free(pop);
}
