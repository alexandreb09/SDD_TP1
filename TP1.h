/*=========================================================================*/
/*	Fichier : TP1.h										     */
/*	Role : fichier en-tete du module TP1.c                                */
/*														     */
/*	Contenu du fichier (déclaractions des fonctions):				    	*/
/*	 		FichierToMatrice								     */
/*			AfficheMatrice										*/
/*			MatToListe										*/
/* 			LibererMatrice										*/
/*			Ecrire											*/
/* 			SuppOcc										     */
/*														     */
/*	Dépendance : ListeChainee.h     							     */
/*														     */
/*=========================================================================*/





#ifndef Gard1
#define Gard1

#include "ListeChainee.h"

float ** FichierToMatrice(char *, int *, int *);
void AfficheMatrice(float **,int,int);

ListeCh_t * MatToListe(float **,int,int,int);
void LibererMatrice(float **, int);
void Ecrire(char *,ListeCh_t *);
void SuppOcc(ListeCh_t **,int);

#endif
