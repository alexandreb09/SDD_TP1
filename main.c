/*=========================================================================*/
/*	Fichier : main.c										     */
/*	Role : Rsoudre l'ensemble du problème (décomposer le problème en      */
/*          sous fonctions)                                                */
/*														     */
/*	Contenu du fichier (déclaractions des fonctions):				    	*/
/*	 		   main                                                     */
/*														     */
/*	Dépendance : ListeChainee.h     							     */
/*                TP1.h                                                    */
/*                erreur.h                                                 */
/*														     */
/*=========================================================================*/



#include "TP1.h"
#include "ListeChainee.h"
#include "erreur.h"
#include <stdio.h>
#include <stdlib.h>


/* -----------------------------------------------------------------------*/
/*                            MAIN                                        */
/*                                                                        */
/*   Entrée :  4 arguments (chaine carac, chaine carac, entier,entier)    */
/*              - FichierMatrice.txt : fichier contenant la matrice       */
/*              - FichierResultat.txt : fichier où seront sauvegardés     */
/*                                      les résultats (créé si inexistant)*/
/*              - K : entier = nombre de coefficients à selectionner      */
/*              - usine : entier = usine à supprimer                      */
/*                                                                        */
/*   Sortie : Créer un fichier avec les différents coefficients si tout   */
/*            s'est bien passé                                            */
/*            Affiche un message d'erreur sinon                           */
/*   Variable locales : n : nombre de colonnes (variable locale, type int)*/
/*                      m : Nombre de lignes   (variable locale, type int)*/
/*                      NomFichier : nom ficher matrice                   */
/*                      NomFichierRep : nom fichier réponse               */
/*                      chaineK : nombre de coefficients (type char *)    */
/*                      chaineUsine : numéro usine (type char *)          */
/*                      Matrice : Tableau de pointeurs de pointeurs       */
/*                      liste : liste chainée contenant les K coefficients*/
/*                      k : (type int) nombre de coefficients conservés   */
/*                      usine : (type int) numéro usine                   */
/*   Sous-fonction  : AfficheErreur                                       */
/*                    FichierToMatrice                                    */
/*                    AfficheMatrice                                      */
/*                    MatToListe                                          */
/*                    SuppOcc                                             */
/*                    AffListe                                            */
/*                    Ecrire                                              */
/*                    LibererListe                                        */
/*                    LibererMatrice                                      */
/* -----------------------------------------------------------------------*/

int main (int argc, char * argv[]){
     int                           n,m;
     char                        * NomFichier,
                                 * NomFichierRep,
                                 * chaineK,
                                 * chaineUsine;
     float                      ** Matrice;
     ListeCh_t                   * liste;
     int                           k,
                                   usine;

     if (argc < 5){
          AfficheErreur(0);
     }
     else {
          NomFichier          = (char*)argv[1];                                 //Sauvegarde des différents arguments
          NomFichierRep       = (char*)argv[2];
          chaineK             = (char*)argv[3];
          chaineUsine         = (char*)argv[4];
          k                   = atoi(chaineK);                                  // Conversion chaine caractère en entier
          usine               = atoi(chaineUsine);

          Matrice = FichierToMatrice(NomFichier,&n,&m);                         // Création matrice
          if (Matrice!= NULL && usine<n){                                       // Si création réussie
               AfficheMatrice(Matrice,n,m);                                     // Affichage matrice
               liste = MatToListe(Matrice,n,m,k);                               // Création de la liste chainée
               if (liste != NULL){                                              // Si la création a réussi
                    SuppOcc(&liste,usine);                                      // Suppression de l'usine u
                    AffListe(liste);                                            // Affichage de la liste
                    Ecrire(NomFichierRep,liste);                                // Sauvegarde des données dans un fichier en mémoire
                    LibererListe(liste);                                        // Libération mémoire de la Liste
               }
               else AfficheErreur(2);

               LibererMatrice(Matrice,n);                                       // Libération mémoire de la matrice
          }
          else AfficheErreur(1);
     }
     return 0;
}
