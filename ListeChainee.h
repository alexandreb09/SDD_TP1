#ifndef Gard2
#define Gard2
#include <stdio.h>
#include <stdlib.h>


typedef struct ListeCh{                           // Structure de la liste chainée :
     float coutProd;                              // Coût production : coefficients c(i,j)
     int indCol;                                  // Indice colonne (appartient [0;n-1])
     int indLig;                                  // Indice ligne (appartient [0;m-1])
     struct ListeCh * suiv;                       // Indice de la case suivante
}ListeCh_t;


ListeCh_t * insereDec(ListeCh_t **, float, int, int);
ListeCh_t * suppEnTete(ListeCh_t *);
void affListe(ListeCh_t *);

#endif
