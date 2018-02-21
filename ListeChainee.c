#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"


ListeCh_t * insereDec (ListeCh_t ** Liste, float coef, int col, int lig){
	ListeCh_t 			* NewCell 	= malloc(sizeof(ListeCh_t));
	ListeCh_t 			* cour 		= *Liste;
	ListeCh_t 			** prec		= Liste;
	NewCell->CoutProd = coef;
	NewCell->IndCol = col;
	NewCell->IndLig = lig;
	NewCell->suiv	= NULL;

	if (*Liste == NULL)
		*Liste = NewCell;
	else{
		while (cour->suiv != NULL && (cour->CoutProd < coef)){
			*prec = cour;
			cour = cour->suiv;
		}
		if (cour->suiv == NULL)
			cour->suiv = NewCell;
		else{
			NewCell->suiv = cour;
			(*prec)->suiv = NewCell;
		}
	}
	return *Liste;
}
