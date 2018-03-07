/*========================================================================*/
/*	Fichier : erreur.c										    */
/*	Role : Gérer les erreurs et en informer l'utilisateur			    */
/*	Contenu du fichier (fonctions):							    */
/*	 		AfficheErreur									    */
/*														    */
/*	Dépendance : aucune		     							    */
/*========================================================================*/



#include <stdio.h>
#include <stdlib.h>
#include "erreur.h"



/* -----------------------------------------------------------------------*/
/*                            AfficheErreur

     Role : Afficher une message d'erreur lorsqu'une erreur se produit

     Entrée :  codeErreur : code de l'erreur

     Sortie : -
     Variable locales : -				                             */
/* -----------------------------------------------------------------------*/
void AfficheErreur( int codeErreur ){
	printf("ERREUR possible: \n");
	switch (codeErreur) {
	case 0 :
		printf("\t- Nombre d'arguments incorrect (4 demandés)\n");
		break;
	case 1 :
		printf("\t- Fichier Matrice Introuvalbe \n\t- Fichier vide\n\t- Erreur Allocation\n\t- k trop grand\n\t- Valeur usine trop grande\n");
		break;
	case 2 :
		printf("\t- Nombre K trop grand (k>n*m)\n\t- Erreur Allocation\n");
		break;
	case 3 :
		printf("\t- L'usine U n'appartient pas à la liste des usines\n");
		break;
	default:
		printf("\t - Une erreur s'est produite\n");
		break;
	}
}
