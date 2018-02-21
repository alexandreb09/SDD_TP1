#ifndef Gard2
#define Gard2
#include <stdio.h>
#include <stdlib.h>


typedef struct ListeCh{                           // Structure de la liste chainée :
     float CoutProd;                              // Coût production : coefficients c(i,j)
     int IndCol;                                  // Indice colonne (appartient [0;n-1])
     int IndLig;                                  // Indice ligne (appartient [0;m-1])
     struct ListeCh * suiv;                       // Indice de la case suivante
}ListeCh_t;


ListeCh_t * insere(ListeCh_t **, float, int, int);


#endif


