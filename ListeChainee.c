#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"


ListeCh_t * insereDec (ListeCh_t ** Liste, float coef, int col, int lig){
	ListeCh_t 			* NewCell 	= malloc(sizeof(ListeCh_t));
	ListeCh_t 			* cour 		= *Liste;
	ListeCh_t 			* prec		= NULL;
	NewCell->coutProd 	= coef;
	NewCell->indCol 	= col;
	NewCell->indLig 	= lig;
	NewCell->suiv 		= NULL;

	if (*Liste == NULL)
		*Liste = NewCell;
	else{
		while (cour->suiv != NULL && (cour->coutProd > coef) ){
			prec = cour;
			cour = cour->suiv;
		}
		if (cour->coutProd > coef){					// Ajout en fin
			cour->suiv = NewCell;
		}
		else{
			NewCell->suiv = cour;
			if (*Liste == cour){					// Ajout en tête
				*Liste = NewCell;
			}
			else {
				prec->suiv = NewCell;				// Ajout général
			}
		}
	}
	return *Liste;
}


ListeCh_t * suppEnTete(ListeCh_t * Liste){
	ListeCh_t * temp = Liste->suiv;
	free(Liste);
	return temp;
}


void affListe(ListeCh_t * liste){
	printf("\nMa liste : \n");
	while(liste){
     	printf("\tUsine %d, période %d, coût de production %0.2f\n", liste->indLig,liste->indCol,liste->coutProd);
   		liste = liste->suiv;
   }
}


void libererListe(ListeCh_t * Liste){
	ListeCh_t * temp, * cour = Liste;
	while(cour){
		temp = cour;
		cour = cour->suiv;
		free(temp);
	}
}

/*
void SuppOcc(ListeCh_t ** pliste){
	ListeCh_t * cour = *pliste;
	ListeCh_t * cour2;

	while (cour != NULL){
		cour2=cour;
		while(cour2 != NULL){
			if(cour->IndLig > cour2->IndLig){
				cour->IndLig = cour2->IndLig;
			}
			cour2=cour2->suiv;
		}
		cour=cour->suiv;
	}
}
*/
