#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"


ListeCh_t * InsertionCroissant (ListeCh_t ** ListePara,float coef,int ligne, int colonne){
     ListeCh_t                          * Liste   = *ListePara;
     ListeCh_t                          * newCell = malloc(sizeof(ListeCh_t));
     ListeCh_t                          * cour;
     listeCh_t                          ** prec;
     if (newCell != NULL){                                            // si allocation ok
          newCell->CoutPord = coef;
          newCell->IndCol = colonne;
          newCell->IndLig = ligne;
          newCell->suiv = NULL;
          if (Liste==NULL){                                           // Si la liste est vide
               Liste = newCell;                                       // Insertion en tête
          }
          else {
               cour = Liste;
               while (cour->suiv != NULL && coef > cour->CoutPord){
                    cour = cour->suiv;
               }
               cour->suiv = newCell;
               newCell->suiv = cour->suiv->suiv;
          }
     }
     return Liste;
}

void AffichageListe(ListeCh_t * Liste){
     int                      i=1;
     printf("\nVoici ma liste : \n");
     while (Liste!= NULL){
          printf("Element %d : coef : %.2f ligne : %d colonne : %d\n",i++,Liste->CoutPord,Liste->IndLig,Liste->IndCol);
          Liste = Liste->suiv;
     }
}


/*
void LibererListe(ListeCh_t * Liste){

}*/
