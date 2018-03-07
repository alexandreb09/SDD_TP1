/*=========================================================================*/
/*	Fichier : ListeChainee.h										*/
/*	Role : Fichier en-tête du module ListeChainee.c                       */
/* 		 (indépendant du TP)			    					    	*/
/*														     */
/*	Contenu du fichier (fonctions):							    	*/
/*	 		insereDec										    	*/
/*			suppEnTete										*/
/*			AffListe											*/
/* 			LibererListe										*/
/*	Contenu du fichier (structure):							    	*/
/*	 		ListeCh_t										    	*/
/*														     */
/*	Dépendance : aucune										    	*/
/*														     */
/*=========================================================================*/



#ifndef Gard2
#define Gard2


typedef struct ListeCh{                           // Structure de la liste chainée :
     float coutProd;                              // Coût production : coefficients c(i,j)
     int periode;                                 // Indice colonne (appartient [0;n-1])
     int usine;                                   // Indice ligne (appartient [0;m-1])
     struct ListeCh * suiv;                       // Indice de la case suivante
}ListeCh_t;


ListeCh_t * insereDec(ListeCh_t **, float, int, int);
ListeCh_t * suppEnTete(ListeCh_t *);
void AffListe(ListeCh_t *);
void LibererListe(ListeCh_t *);

#endif
