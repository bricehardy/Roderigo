#include "minmax.h"

/* **************************************************************************************/
/*										MOBILITE 										*/
/* **************************************************************************************/

/* Compte les possibilités du joueur adverse à une position donnée */
int compterPossibilites(Othellier *dame, Coup *coup, int couleur, int position){
	int i, compt;
	
	coup->position = position;
	coup->couleur = couleur;
	jouerCoup(dame, coup);
	retablirDamier(dame);
	
	coup->couleur = !coup->couleur;			
	calculerPossibilites(dame, coup);
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE)
			compt++;
	}
	annulerCoup(dame, coup);
	return compt;
}


/* Renvoie la mobilité (le nombre de possibilités) du joueur */
int mobiliteCouleur(Othellier *dame, Coup *coup, int couleur){
	int i, compt = 0;
	
	coup->couleur = couleur;
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame->damier[i] == POSSIBLE)
			compt++;
	}
	return compt;
}


/* Renvoie la mobilité */
int differenceDeMobilite(Othellier *dame, Coup *coup, int couleur, int position){
	int mobilite, possibilite, possible_adverse;
	
	possibilite = mobiliteCouleur(dame, coup, couleur);
	possible_adverse = compterPossibilites(dame, coup, couleur, position);
	
	mobilite = possibilite - possible_adverse;
	return mobilite;
}


/* **************************************************************************************/
/*									NOMBRE DE PIONS										*/
/* **************************************************************************************/

/* Renvoie le nombre de pions du damier */
int pionsDefinitifs(Othellier *dame, Coup *coup, int couleur){
	int compt;
	
	coup->couleur = couleur;
	compt = dame->score[coup->couleur] + dame->score[!coup->couleur];
	return compt;
}


/* Renvoie le nombre de pions du joueur ayant le trait */
int nbrePionsCouleur(Othellier *dame, Coup *coup, int couleur){
	int compt;
	
	coup->couleur = couleur;
	compt = dame->score[coup->couleur];
	return compt;
}


/* Retourne le nombre de pions de l'adversaire */
int nbrePionsAdverse(Othellier *dame, Coup *coup, int couleur){
	int pions_adverse;
	
	pions_adverse = pionsDefinitifs(dame, coup, couleur) - nbrePionsCouleur(dame, coup, couleur);
	return pions_adverse;
}


/* Retourne la différence de pions */
int differencePions(Othellier *dame, Coup *coup, int couleur){
	int difference;
	
	difference = nbrePionsCouleur(dame, coup, couleur) - nbrePionsAdverse(dame, coup, couleur);
	return difference;
}


/* **************************************************************************************/
/*										COINS   										*/
/* **************************************************************************************/

/* Compte le nombre de coins qu'a un joueur */
int coins(Othellier *dame, Coup *coup, int couleur){
	int compt = 0;
	
	coup->couleur = couleur;
	if(dame->damier[11] == coup->couleur)
		compt++;
	if(dame->damier[18] == coup->couleur)
		compt++;
	if(dame->damier[81] == coup->couleur)
		compt++;
	if(dame->damier[88] == coup->couleur)
		compt++;
	return compt;
}


/* Fait la difference entre le nombre de coins du joueur et de son adversaire */
int differenceCoins(Othellier *dame, Coup *coup, int couleur){
	int coins_couleur, coins_adverse, difference;
	
	coins_couleur = coins(dame, coup, couleur);
	coins_adverse = coins(dame, coup, !couleur);
	
	difference = coins_couleur - coins_adverse;
	return difference;
}


/* **************************************************************************************/
/*											BORDS 										*/
/* **************************************************************************************/

/* Compte et renvoie le nombre de bords possedés par le joueur qui a le trait */
int nbreBordsCouleur(Othellier *dame, Coup *coup, int couleur){
	int i, compt;
	
	coup->couleur = couleur;
	for(i = 12; i < (MAX_CASE - 10); i++){
		if((i >= 12 && i < 18) || (i > 81 && i < 88)){
			if(dame->damier[i] == coup->couleur)
				compt++;
		}
		if(i % 10 == 1 && i < 72){
			if(dame->damier[i] == coup->couleur)
				compt++;
		}
		if(i % 10 == 8 && (i >= 28 && i <= 78)){
			if(dame->damier[i] == coup->couleur)
				compt++;
		}
	}
	return compt;
}


/* Compte et renvoie la différence de bords */
int diffBords(Othellier *dame, Coup *coup, int couleur){
	int diff;
	
	diff = diffBords(dame, coup, couleur) - diffBords(dame, coup, !couleur);
	return diff;
}


/* **************************************************************************************/
/*										EVALUATION										*/
/* **************************************************************************************/

/* Fonction d'evaluation */
/* Fonction eval pas prete, pour la forme */
int eval(Othellier *dame, Coup *coup){
	int i, j;
	
	i = coup->couleur;
	j = dame->score[NOIR];
	return 0;
}


/* **************************************************************************************/
/*										ALPHA-BETA 										*/
/* **************************************************************************************/

/* Fonction AlphaBeta */
int alphaBeta(int profondeur, int alpha, int beta){
	Othellier dame;
	Coup coup;
	int i, score, meilleur_coup;
	
	if(profondeur <= 0 || bloque(&dame, &coup) || (!peutJouer(&dame, &coup, coup.couleur) && !peutJouer(&dame, &coup, !coup.couleur)))
		return eval(&dame, &coup); /* Fonction eval pas prete, pour la forme */
	
	for(i = 10; i < (MAX_CASE - 10); i++){
		if(dame.damier[i] == POSSIBLE){
			jouerCoup(&dame, &coup);
			score = -alphaBeta(profondeur - 1, -beta, -alpha);
			annulerCoup(&dame, &coup);
			if(score >= alpha){
				alpha = score;
				meilleur_coup = dame.damier[i];
				if(alpha >= beta)
					break;
			}
		}
	}
	return alpha;
}

