/*=========================================================================*/
/*	Fichier : ListeChainee.c										*/
/*	Role : Module regroupant différentes fonctions sur les listes chainées*/
/* 		 (indépendant du TP)			    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		insereDec										    	*/
/*			suppEnTete										*/
/*			AffListe											*/
/* 			LibererListe										*/
/*														     */
/*	Dépendance : aucune		     							     */
/*=========================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"


/* -----------------------------------------------------------------------*/
/*                            insereDec

     Role : Ajouter une valeur dans une liste TRIEE par ordre décroissant

     Entrée :  Liste     : liste chainée TRIEE par ordre décroissant
               coef   	: cout de l'usine
               col 		: période
			lig 		: usine

     Sortie : liste chainée TRIEE par ordre décroissant avec la nouvelle cellule
     Variable locales : n : nombre de colonnes
                        m : Nombre de lignes
                        fichier : fichier lu                              */
/* -----------------------------------------------------------------------*/
ListeCh_t * insereDec (ListeCh_t ** Liste, float coef, int col, int lig){
	ListeCh_t 			* NewCell,
						* cour 		= *Liste,
						* prec		= NULL;

	NewCell 	= malloc(sizeof(ListeCh_t));
	if (NewCell != NULL){
		NewCell->coutProd 					= coef;
		NewCell->periode 					= col;
		NewCell->usine 					= lig;
		NewCell->suiv 						= NULL;

		if (*Liste == NULL)											// Si la liste est vide
			*Liste = NewCell;										// Ajout en tête (cas liste vide)
		else{
			while (cour->suiv != NULL && (cour->coutProd > coef) ){		// Recherche position pour insertion
				prec = cour;
				cour = cour->suiv;
			}
			if (cour->coutProd > coef){								// Ajout en fin
				cour->suiv = NewCell;
			}
			else{
				NewCell->suiv = cour;
				if (*Liste == cour){								// Ajout en tête
					*Liste = NewCell;
				}
				else {
					prec->suiv = NewCell;							// Ajout général
				}
			}
		}
	}
	return *Liste;
}


/* -----------------------------------------------------------------------*/
/*                            suppEnTete

     Role : Supprimer la 1ere valeur d'une liste chainée

     Entrée :  Liste     : liste chainée

     Sortie : liste chainée à laquelle on a retiré la première valeur
     Variable locales : temp : variable temporaire                        */
/* -----------------------------------------------------------------------*/
ListeCh_t * suppEnTete(ListeCh_t * Liste){
	ListeCh_t 			* temp = Liste->suiv;
	free(Liste);
	return temp;
}

/* -----------------------------------------------------------------------*/
/*                            AffListe

     Role : Afficher une liste chainée

     Entrée :  Liste     : liste chainée

     Sortie : -
     Variable locales : -					                        */
/* -----------------------------------------------------------------------*/
void AffListe(ListeCh_t * liste){
	printf("\nListe : \n");
	while(liste){
     	printf("\tUsine %d, période %d, coût de production %0.2f\n", liste->usine,liste->periode,liste->coutProd);
   		liste = liste->suiv;
   }
}

/* -----------------------------------------------------------------------*/
/*                            LibererListe

     Role : Libérer l'espace alloué par une liste chainée

     Entrée :  Liste     : liste chainée

     Sortie : -
     Variable locales : cour : pointeur courant
                   	    temp : variable temporaire				    */
/* -----------------------------------------------------------------------*/
void LibererListe(ListeCh_t * Liste){
	ListeCh_t  			* temp,
						* cour = Liste;
	while(cour){
		temp = cour;
		cour = cour->suiv;
		free(temp);
	}
}
