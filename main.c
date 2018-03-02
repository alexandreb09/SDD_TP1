#include "TP1.h"
#include "ListeChainee.h"
#include "erreur.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[]){  //NomFichier - FichierReponse k usine
     int                           n,m;
     char                        * NomFichier,* NomFichierRep, * chaineK, * chaineUsine;
     float                      ** Matrice;
     ListeCh_t                   * liste;
     int                           k, usine;
     
     if (argc < 5){
          afficheErreur(0);
     }
     else {
          NomFichier          = (char*)argv[1];
          NomFichierRep       = (char*)argv[2];
          chaineK             = (char*)argv[3];
          chaineUsine         = (char*)argv[4];
          k                   = atoi(chaineK);
          usine               = atoi(chaineUsine);

          Matrice = FichierToMatrice(NomFichier,&n,&m);
          if (Matrice!= NULL && usine<n){
               AfficheMatrice(Matrice,n,m);
               liste = matToListe(Matrice,n,m,k);
               if (liste != NULL){
                    SuppOcc(&liste,usine);
                    affListe(liste);
                    Ecrire(NomFichierRep,liste);
                    libererListe(liste);
               }
               else afficheErreur(2);

               libererMatrice(Matrice,n);
          }
          else afficheErreur(1);
     }
     return 0;
}
