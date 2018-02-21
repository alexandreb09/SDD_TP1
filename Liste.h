#ifndef Gardien2
#define Gardien2



typedef struct ListeCh{                           // Structure de la liste chainée :
     float CoutPord;                              // Coût production : coefficients c(i,j)
     int IndCol;                                  // Indice colonne (appartient [0;n-1])
     int IndLig;                                  // Indice ligne (appartient [0;m-1])
     struct ListeCh * suiv;                       // Indice de la case suivante
}ListeCh_t;



ListeCh_t * InsertionCroissant (ListeCh_t **,float,int, int);
void AffichageListe(ListeCh_t *);
void LibererListe(ListeCh_t *);

#endif
