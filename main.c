/*
 *  main.c
 *  Roderigo
 */

#include "main.h"

int main (int argc, const char * argv[]) {
    Coup coup;
	Joueur joueur1, joueur2;
	Othellier dame;
	int choix_menu, load;
	bool statut_programme = True;
	
	system("clear");
	
	while (statut_programme) {
		choix_menu = 0;
		afficherMenu();

		scanf("%d", &choix_menu);
			
		switch(choix_menu) {
			case 1: /* Choix 1 : Règles */
				afficherRegles();
				break;
			case 2: /* Choix 2 : humain vs humain */
				load = 0;
				humainVShumain(&dame, &coup, &joueur1, &joueur2, load);
				break;
			case 3: /* Choix 3 : humain vs CPU */
				humainVScpu(&dame, &coup, &joueur1, &joueur2, load);
				printf("Option indisponible pour l'instant");
				break;
			case 4: /* Choix 4 : charger partie */
				/*****************************************************************************************************
				 *				   Attention !! on ne gère que le cas où c'est humain vs humain						 *
				 *****************************************************************************************************/
				load = 1;
				/* rajouter choix cpu ou humain... */
				humainVShumain(&dame, &coup, &joueur1, &joueur2, load);
				break;
			case 5: /* Choix 5 : Quitter */
				printf("Petit joueur !!!");
				statut_programme = 0;
				break;
			default :
				printf("Choix incorrect.");
				break;
		}
	}

	printf("\n");
	printf("fin");
	return 0;
}

void humainVShumain(Othellier *dame, Coup *coup, Joueur *joueur1, Joueur *joueur2, int load) {
	Partie partie;
	char minibuffer[3], c;
	int n, ancien_coup = NOIR, compt;
	bool continuer = True;
    FILE *fichier = NULL;
	FILE *save = NULL;

	/* On initialise l'othellier */
	initialiserOthellier(dame);
    coup->couleur = NOIR;

	system("clear");

	/* On vérifie s'il s'agit d'une partie sauvegardée */
	if (load == 1) { /* Si oui : on la charge */
        fichier = fopen("partie.sav", "r+");
        chargerPartie(dame, coup, fichier, joueur1, joueur2);
        save = fopen("temp.txt", "w+");
        copierFichier(fichier, save);
        fclose(fichier);
        fclose(save);
        fichier = fopen("temp.txt", "r+");
        coup->couleur = !coup->couleur;
    }
    else { /* Si non : on se prépare à la sauvegarder */
        fichier = fopen("temp.txt", "w+");
        nomJoueur(joueur1);
        nomJoueur(joueur2);

		/* Pour les fonctions "(dés)annuler" */
		partie.final = partie.longueur = 0;
		coup->couleur = ancien_coup;
    }

	/* Et apès tout ça, on rentre dans la boucle qui nous permet de jouer */
	while (continuer) {
		compterPions(dame);
	    system("clear");

		/* On verifie si il est encore possible de jouer. Si non, on arrête le jeu */
		if (bloque(dame, coup)) {
			continuer = False;
			break; /* Pour sortir de la boucle */
		}

		calculPossibilite(dame, coup);
		afficherOthellier(dame, joueur1, joueur2);

		/* On affiche le nom du joueur */
		if (coup->couleur == NOIR)
			printf("Au tour de %s\n",joueur1->nom);
		else
			printf("Au tour de %s\n",joueur2->nom);

		/* On entre les coordonnees du coup a jouer et on les enregistre */
		printf("Position = ");
		scanf("%s", minibuffer);

		c = minibuffer[0];
		n = minibuffer[1] - '0';

		/* On vérifie si le caractère entré appelle le menu */
		switch (c) {
			case 'q': /* On quitte la partie */
				fclose(fichier);
                fclose(save);
				continuer = False;
				break;
			case 'l': /* On charge la partie */
				fclose(fichier);
                fclose(save);
                load = 1;
                continuer = 0;
                humainVShumain(dame, coup, joueur1, joueur2, load);
				break;
			case 'i': /* On annule le coup si possible */
				if(partie.final > 0) {
					coup->position = partie.coup[partie.final - 1].position;
					for(compt = 0; compt < DIRECTIONS; compt++)
						coup->retournement[compt] = partie.coup[partie.final - 1].retournement[compt];
					annulerCoup(dame, coup);
					coup->couleur = partie.coup[partie.final - 1].couleur;
					ancien_coup = coup->couleur;
					partie.final--;
				}
				break;
			case 'j': /* On rétablit le coup si possible */
				if(partie.final < partie.longueur){
					coup->position = partie.coup[partie.final].position;
					retablirCoup(dame, coup);
					partie.final++;
				}
				break;
			case 's': /* On sauvegarde la partie */
				save = fopen("partie.sav", "w+");
				copierFichier(fichier, save);
				fclose(save);
				save = fopen("partie.sav", "r+");
				fseek(save, 0, SEEK_END);
				printf("Partie sauvegardée\n");
				break;
			default: /* Tous les autres cas (en gros si on entre une position ^^) */
				/* coup->couleur = ancien_coup; */

				coup->position = nbEntrer(n, c);

				/* On joue le coup */
				if(dame->damier[coup->position] == POSSIBLE) {
					jouerCoup(dame, coup);

					/* Pour les fonction "dés(annuler)" */
					partie.coup[partie.final].position = coup->position;
					partie.coup[partie.final].couleur = coup->couleur;
					for(compt = 0; compt < DIRECTIONS; compt++)
						partie.coup[partie.final].retournement[compt] = coup->retournement[compt];
					partie.final++;
					partie.longueur = partie.final;

					coup->couleur = !coup->couleur;

					sauvegarderPartie(dame, coup, fichier, joueur1, joueur2);
				}
				else {
					printf("Coup illegal\n");
				}

				if (peutJouer(dame, coup, coup->couleur))
					ancien_coup = coup->couleur;
				else { /* Si le joueur qui a la main ne peut pas jouer, on change la couleur, on retablit le damier, on simule les coups et on affiche le damier */
					ancien_coup = !coup->couleur;
					coup->couleur = ancien_coup;
				}

				retablirDamier(dame);
				calculerPossibilites(dame, coup);

				break;
		}

		/* Et on n'oublie pas de remettre les cases POSSIBLEs à VIDE */
		retablirDamier(dame);
	}

	system("clear");
    afficherOthellier(dame, joueur1, joueur2);
	printf("Partie terminee\n");
    fclose(fichier);

	/* On determine le gagnant */
	if (dame->score[NOIR] > dame->score[BLANC])
		printf("%s a gagne\n", joueur1->nom);
	else if (dame->score[BLANC] > dame->score[NOIR])
		printf("%s a gagne\n", joueur2->nom);
	else
		printf("Egalite !!");

	printf("\n");
}

void humainVScpu(Othellier *dame, Coup *coup, Joueur *joueur1, Joueur *joueur2, int load) {
	Partie partie;
	char minibuffer[3], c;
	int n, ancien_coup = NOIR, compt, niveau;
	bool continuer = True;
    FILE *fichier = NULL;
	FILE *save = NULL;
	
	/* On initialise l'othellier */
	initialiserOthellier(dame);
    coup->couleur = NOIR;
	
	system("clear");
	
	/* On vérifie s'il s'agit d'une partie sauvegardée */
	if (load == 1) { /* Si oui : on la charge */
        fichier = fopen("partie.sav", "r+");
        chargerPartie(dame, coup, fichier, joueur1, joueur2);
        save = fopen("temp.txt", "w+");
        copierFichier(fichier, save);
        fclose(fichier);
        fclose(save);
        fichier = fopen("temp.txt", "r+");
        coup->couleur = !coup->couleur;
    }
    else { /* Si non : on se prépare à la sauvegarder */
        fichier = fopen("temp.txt", "w+");
        nomJoueur(joueur1);
        nomJoueur(joueur2);
		
		while (niveau < 1 || niveau > 15) {
			printf("Entrez le niveau choisi (entre 1 et 15) :");
			scanf("%d", &niveau);
		}
		
		/* Pour les fonctions "(dés)annuler" */
		partie.final = partie.longueur = 0;
		coup->couleur = ancien_coup;
    }
	
	/* Et apès tout ça, on rentre dans la boucle qui nous permet de jouer */
	while (continuer) {
		compterPions(dame);
	    system("clear");
		
		/* On verifie si il est encore possible de jouer. Si non, on arrête le jeu */
		if (bloque(dame, coup)) {
			continuer = False;
			break; /* Pour sortir de la boucle */
		}
		
		calculPossibilite(dame, coup);
		afficherOthellier(dame, joueur1, joueur2);
		
		/* On affiche le nom du joueur */
		if (coup->couleur == NOIR) { /* Si le joueur est l'humain */
			printf("Au tour de %s\n",joueur1->nom);
			printf("Position = ");
			scanf("%s", minibuffer);
			
			c = minibuffer[0];
			n = minibuffer[1] - '0';
			
			/* On vérifie si le caractère entré appelle le menu */
			switch (c) {
				case 'q': /* On quitte la partie */
					fclose(fichier);
					fclose(save);
					continuer = False;
					break;
				case 'l': /* On charge la partie */
					fclose(fichier);
					fclose(save);
					load = 1;
					continuer = 0;
					humainVShumain(dame, coup, joueur1, joueur2, load);
					break;
				case 'i': /* On annule le coup si possible */
					if(partie.final > 0) {
						coup->position = partie.coup[partie.final - 1].position;
						for(compt = 0; compt < DIRECTIONS; compt++)
							coup->retournement[compt] = partie.coup[partie.final - 1].retournement[compt];
						annulerCoup(dame, coup);
						coup->couleur = partie.coup[partie.final - 1].couleur;
						ancien_coup = coup->couleur;
						partie.final--;
					}
					break;
				case 'j': /* On rétablit le coup si possible */
					if(partie.final < partie.longueur){
						coup->position = partie.coup[partie.final].position;
						retablirCoup(dame, coup);
						partie.final++;
					}
					break;
				case 's': /* On sauvegarde la partie */
					save = fopen("partie.sav", "w+");
					copierFichier(fichier, save);
					fclose(save);
					save = fopen("partie.sav", "r+");
					fseek(save, 0, SEEK_END);
					printf("Partie sauvegardée\n");
					break;
				default: /* Tous les autres cas (en gros si on entre une position ^^) */
					
					coup->position = nbEntrer(n, c);
					
					/* On joue le coup */
					if(dame->damier[coup->position] == POSSIBLE) {
						jouerCoup(dame, coup);
						
						/* Pour les fonction "dés(annuler)" */
						partie.coup[partie.final].position = coup->position;
						partie.coup[partie.final].couleur = coup->couleur;
						for(compt = 0; compt < DIRECTIONS; compt++)
							partie.coup[partie.final].retournement[compt] = coup->retournement[compt];
						partie.final++;
						partie.longueur = partie.final;
						
						coup->couleur = !coup->couleur;
						
						sauvegarderPartie(dame, coup, fichier, joueur1, joueur2);
					}
					else {
						printf("Coup illegal\n");
					}
					
					if (peutJouer(dame, coup, coup->couleur))
						ancien_coup = coup->couleur;
					else { /* Si le joueur qui a la main ne peut pas jouer, on change la couleur, on retablit le damier, on simule les coups et on affiche le damier */
						ancien_coup = !coup->couleur;
						coup->couleur = ancien_coup;
					}
					
					retablirDamier(dame);
					calculerPossibilites(dame, coup);
					
					break;
			}
			/* Et on n'oublie pas de remettre les cases POSSIBLEs à VIDE */
			retablirDamier(dame);
		}
		
		else { /* Si c'est au tour de Roderigo */
			printf("Au tour de %s\n",joueur2->nom);
			
			/* On lance alphabeta avec la variable "niveau" (pour la profondeur) puis on entre le meilleur coup */
			coup->position = alphaBeta(niveau, 0 /* alpha */, 1 /* beta*/ );
			
			/* On joue le coup */
			if(dame->damier[coup->position] == POSSIBLE) {
				jouerCoup(dame, coup);
				
				/* Pour les fonction "dés(annuler)" */
				partie.coup[partie.final].position = coup->position;
				partie.coup[partie.final].couleur = coup->couleur;
				for(compt = 0; compt < DIRECTIONS; compt++)
					partie.coup[partie.final].retournement[compt] = coup->retournement[compt];
				partie.final++;
				partie.longueur = partie.final;
				
				coup->couleur = !coup->couleur;
				
				sauvegarderPartie(dame, coup, fichier, joueur1, joueur2);
			}
			else {
				printf("Coup illegal\n");
			}
			
			if (peutJouer(dame, coup, coup->couleur))
				ancien_coup = coup->couleur;
			else { /* Si le joueur qui a la main ne peut pas jouer, on change la couleur, on retablit le damier, on simule les coups et on affiche le damier */
				ancien_coup = !coup->couleur;
				coup->couleur = ancien_coup;
			}
			
			retablirDamier(dame);
			calculerPossibilites(dame, coup);
		}
		
		/* Et on n'oublie pas de remettre les cases POSSIBLEs à VIDE */
		retablirDamier(dame);
	}
	system("clear");
    afficherOthellier(dame, joueur1, joueur2);
	printf("Partie terminee\n");
    fclose(fichier);
	
	/* On determine le gagnant */
	if (dame->score[NOIR] > dame->score[BLANC])
		printf("%s a gagne\n", joueur1->nom);
	else if (dame->score[BLANC] > dame->score[NOIR])
		printf("%s a gagne\n", joueur2->nom);
	else
		printf("Egalite !!");
	
	printf("\n");
}
