#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"
#include "ListeChainee.h"
#define K 5

/* -----------------------------------------------------------------------*/
/*                            FichierToMatrice

     Role : Lit un fichie et renvoie la matrice (crée dynamiquement)
            contenue dans ce fichier

     Entrée :  Nom       : le nom du fichier à lire (chaine de caractères)
               NbLigne   : nombre de lignes (actualisé dans la fonction)
               NbColonne : nombre de colonnes (actualisé dans la fonction)

     Sortie : une matice contenant les coefficients du fichier lu
     Variable locales : n : nombre de colonnes
                        m : Nombre de lignes
                        fichier : fichier lu                              */
/* -----------------------------------------------------------------------*/

float ** FichierToMatrice(char * Nom,int * NbLigne, int * NbColonne) {
     FILE                   * fichier = NULL;
     int                      n, m, i,j;
     float                 ** Tab = NULL;

     fichier = fopen(Nom, "r");
     if (fichier != NULL){                                       // Si le fichier s'est ouvert
          fscanf(fichier, "%d %d", NbLigne, NbColonne);          // récupère nb colonnes-lignes
          m = *NbLigne;
          n = *NbColonne;
          Tab = malloc(m*sizeof(*Tab));                          // alloue 1 tableau de pointeurs
          if (Tab != NULL){
               for (j=0;j<m;++j){                                // alloue pour chaque case une liste
                    Tab[j] = malloc(n*sizeof(**Tab));            // pour créer la matrice
               }
               if (Tab[m-1] != NULL){                            // la dernière correctement affectée
                    for (i=0; i<m; i++){
                         for (j=0;j<n; j++){
                              fscanf(fichier,"%f",&Tab[i][j]);
                         }
                    }
               }
          }
          fclose(fichier);
     }
     return Tab;
}


/* -----------------------------------------------------------------------*/
/*                            AfficheMatrice

     Role : Affiche la matrice (dimension 2)

     Entrée : Tab :       matrice de dimension (contenant des flottants)
              nbLigne :   nombre de lignes
              nbColonne : nombre de colonnes
     Sortie : -
     Variable locales : i : Ligne courrante
                        j : Colonne courrante                             */
/* -----------------------------------------------------------------------*/

void AfficheMatrice(float ** Tab,int nbLigne,int nbColonne){
     int                 i, j;
     printf("Ma matrice : \n\t");
     for (i=0; i<nbLigne;++i){
          for (j=0;j<nbColonne;++j){
               printf(" %.2f",Tab[i][j]);
          }
          printf("\n\t");
     }
     printf("\n");
}



/* -----------------------------------------------------------------------*/
/*                            matToListe

     Role : Renvoie les K-plus-petits coefficients d'une matrice sous forme de
            de liste chainée

     Entrée : Tab :       matrice 2 dimensions (contenant des flottants)
              nbLigne :   nombre de lignes (de la matrice)
              nbColonne : nombre de colonnes (de la matrice)
     Sortie : Une liste chainée contenant les K-plus-petits coefficients
               (ainsi que l'usine et la période)

     Variable locales : i : Ligne courrante
                        l : Colonne courrante
                        cmp : compteur, nombre d'élément dans la liste
                        list : la liste en question
    Sous fonctions : suppEnTete
                     insereDec                                            */
/* -----------------------------------------------------------------------*/

ListeCh_t * matToListe(float ** Tab,int nbLigne,int nbColonne){
    ListeCh_t                 * list = NULL;
    ListeCh_t                 * temp;
    int                         i,l, cmp =0;                                    // Nombre d'elt dans la liste
    for (i=0; i<nbLigne;++i){                                                   // Pour chaque élément de la matrice
         for (l=0; l<nbColonne;++l){
              if (cmp < K){                                                     // Si on a pas inséré les k premiers éléments
                   list = insereDec(&list,Tab[i][l],i,l);                       // On les insère (dans tous les cas)
                   cmp++;                                                       // on incrémente le compteur
              }
              else{
                   if(Tab[i][l] < list->coutProd){                              // Regarde si l'élt courant < au premier élt de la liste
                        list = suppEnTete(list);
                        list = insereDec(&list,Tab[i][l],i,l);                  // et on insère l'élt courant
                   }
              }
         }
    }
    return list;
}
