/*=========================================================================*/
/*	Fichier : TP1.c										     */
/*	Role : Module regroupant les différentes fonctions propres au problème*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		FichierToMatrice								     */
/*			AfficheMatrice										*/
/*			MatToListe										*/
/* 			LibererMatrice										*/
/*			Ecrire											*/
/* 			SuppOcc										     */
/*														     */
/*	Dépendance : ListeChainee.h     							     */
/*=========================================================================*/



#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"
#include "ListeChainee.h"

/* -----------------------------------------------------------------------*/
/*                            FichierToMatrice                            */
/*                                                                        */
/*     Role : Lit un fichie et renvoie la matrice (crée dynamiquement)    */
/*            contenue dans ce fichier (NULL si échec)                    */
/*                                                                        */
/*   Entrée :  Nom       : le nom du fichier à lire (chaine de caractères)*/
/*             NbLigne   : nombre de lignes (actualisé dans la fonction)  */
/*             NbColonne : nombre de colonnes (actualisé dans la fonction)*/
/*                                                                        */
/*   Sortie : une matice contenant les coefficients du fichier lu         */
/*            (NULL si échec)                                             */
/*   Variable locales : n : nombre de colonnes (variable locale, type int)*/
/*                      m : Nombre de lignes   (variable locale, type int)*/
/*                      fichier : fichier lu                              */
/*   Sous-fonction  : LibererMatrice                                      */
/* -----------------------------------------------------------------------*/
float ** FichierToMatrice(char * Nom, int * NbLigne, int * NbColonne) {
     int                      n, m, i, j, alloc = 1;
     float                 ** Tab            = NULL;
     FILE 			   * fichier        = NULL;

     fichier = fopen(Nom, "r");
     if (fichier != NULL){                                            // Si le fichier s'est ouvert
          if (fscanf(fichier, "%d %d", NbLigne, NbColonne) != EOF){   // Si le fichier est NON vide
               m = *NbLigne;
               n = *NbColonne;
               Tab = malloc(m*sizeof(*Tab));                          // alloue 1 tableau de pointeurs
               if (Tab != NULL){
                    for (j=0; j<m && alloc; ++j){                     // alloue pour chaque case une liste
                         Tab[j] = malloc(n*sizeof(**Tab));            // pour créer la matrice
                         if (Tab[j] == NULL)                          // Si alloc échoue
                              alloc = 0;
                    }
                    if (alloc > 0){                                   // si matrice correctement allouée
                         for (i=0; i<m; i++){
                              for (j=0;j<n; j++){
                                   fscanf(fichier,"%f",&Tab[i][j]);
                              }
                         }
                    }
                    else {                                            // Cas où l'allocation a échoué
                         LibererMatrice(Tab,j);                       // Libération de l'espace occupé par la matrice
                    }
               }
          }
          fclose(fichier);
     }
     return Tab;
}


/* -----------------------------------------------------------------------*/
/*                            AfficheMatrice                              */
/*                                                                        */
/*   Role : Affiche la matrice (dimension 2)                              */
/*                                                                        */
/*   Entrée : Tab :       matrice de dimension (contenant des flottants)  */
/*            nbLigne :   nombre de lignes                                */
/*            nbColonne : nombre de colonnes                              */
/*   Sortie : -                                                           */
/*   Variable locales : i : Ligne courrante                               */
/*                      j : Colonne courrante                             */
/* -----------------------------------------------------------------------*/
void AfficheMatrice(float ** Tab,int nbLigne,int nbColonne){
     int                 i, j;

     printf("Matrice : \n\t");
     for (i=0; i<nbLigne;++i){
          for (j=0;j<nbColonne;++j){
               printf(" %.2f",Tab[i][j]);
          }
          printf("\n\t");
     }
     printf("\n");
}



/* -----------------------------------------------------------------------*/
/*                            MatToListe                                  */
/*                                                                        */
/*   Role : Renvoie les K-plus-petits coefficients d'une matrice sous     */
/*          forme de liste chainée (NULL si échec)                        */
/*                                                                        */
/*   Entrée : Tab :       matrice 2 dimensions (contenant des flottants)  */
/*            nbLigne :   nombre de lignes (de la matrice)                */
/*            nbColonne : nombre de colonnes (de la matrice)              */
/*   Sortie : Une liste chainée contenant les K-plus-petits coefficients  */
/*            (ainsi que l'usine et la période)                           */
/*            NULL si échec                                               */
/*                                                                        */
/*   Variable locales : i : Ligne courrante                               */
/*                      l : Colonne courrante                             */
/*                      cmp : compteur, nombre d'élément dans la liste    */
/*                      list : la liste en question                       */
/*   Sous fonctions : suppEnTete                                          */
/*                    insereDec                                           */
/* -----------------------------------------------------------------------*/
ListeCh_t * MatToListe(float ** Tab,int nbLigne,int nbColonne,int k){
    ListeCh_t                 * list = NULL;
    int                         i,l, cmp =0;
    
    for (i=0; i<nbLigne;++i){                                                   // Pour chaque élément de la matrice
         for (l=0; l<nbColonne;++l){
              if (cmp < k){                                                     // Si on a pas inséré les k premiers éléments
                   list = insereDec(&list,Tab[i][l],l,i);                       // On les insère (dans tous les cas)
                   cmp++;                                                       // on incrémente le compteur
              }
              else{
                   if(Tab[i][l] < list->coutProd){                              // Regarde si l'élt courant < au premier élt de la liste
                        list = suppEnTete(list);
                        list = insereDec(&list,Tab[i][l],l,i);                  // et on insère l'élt courant
                   }
              }
         }
    }
    return list;
}


/* -----------------------------------------------------------------------*/
/*                            LibererMatrice                              */
/*                                                                        */
/*   Role : libérer la mémoire allouée pour la matrice                    */
/*                                                                        */
/*   Entrée : Matrice :   matrice 2 dimensions (contenant des flottants)  */
/*              nbLigne :   nombre de lignes (de la matrice)              */
/*   Sortie : -                                                           */
/*                                                                        */
/*   Variable locales : i : Ligne courrante                               */
/* -----------------------------------------------------------------------*/
void LibererMatrice(float ** Mat, int nbLigne){
     int            i = 0;
     for (i; i < nbLigne; ++i){
          free(Mat[i]);
          }
     free(Mat);
}


/* -----------------------------------------------------------------------*/
/*                            Ecrire                                      */
/*                                                                        */
/*   Role : Sauvergarder la liste chainée en mémoire (dans un fichier)    */
/*                                                                        */
/*   Entrée : Nom :      Nom du fichier dans lequel on enregistre la      */
/*                       liste                                            */
/*            pliste :   liste chainée à sauvegarder                      */
/*   Sortie : -                                                           */
/*                                                                        */
/*   Variable locales : fichier                                           */
/* -----------------------------------------------------------------------*/
void Ecrire(char * Nom, ListeCh_t * pliste){
     FILE                   * fichier = NULL;
     fichier = fopen(Nom, "w");
     if (fichier != NULL){
          while(pliste){
               fprintf(fichier,"%d %d %0.2f\n", pliste->usine,pliste->periode,pliste->coutProd);
               pliste = pliste->suiv;
          }
          fclose(fichier);
     }
}


/* -----------------------------------------------------------------------*/
/*                            SuppOcc                                     */
/*                                                                        */
/*   Role : Supprimer toutes les occurences de l'usine u                  */
/*                                                                        */
/*   Entrée : pliste :   liste chainée                                    */
/*            usine  :   usine à supprimer                                */
/*   Sortie : la liste sans occurence de l'usine "usine"                  */
/*                                                                        */
/*   Variable locales :                                                   */
/*                  - cour : pointeur courant                             */
/*                  - prec: pointeur précédent                            */
/*                  - temp : variable temporaire                          */
/* -----------------------------------------------------------------------*/
void SuppOcc(ListeCh_t ** pliste,int usine){
	ListeCh_t *                  cour = *pliste;
     ListeCh_t *                  prec = NULL;
     ListeCh_t *                  temp;

	while (cour != NULL){                                  // Parcours de la liste
		if(cour->usine == usine){                         // Cas où il faut supprimer la case
               if (prec == NULL){                           // Si on est en tête
                    *pliste = cour->suiv;                   // Suppression en tête
               }
               else {
                    prec->suiv = cour->suiv;                // Suppression cas générale
               }
               temp = cour;
               cour=cour->suiv;
               free(temp);
          }
          else {
               prec = cour;                                 // pas de suppression
               cour=cour->suiv;
          }
	}
}
