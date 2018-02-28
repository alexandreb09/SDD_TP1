#include "TP1.h"
#include "ListeChainee.h"
#include <stdio.h>


int main (){
     int                           n,m;
     char                        * NomFichier = "test.txt";
     float                      ** Matrice;
     ListeCh_t                   * liste;

     Matrice = FichierToMatrice(NomFichier,&n,&m);
     AfficheMatrice(Matrice,n,m);

     liste = matToListe(Matrice,n,m);
     affListe(liste);
     //SuppOcc(liste);
     //affListe(&liste);
     Ecrire("Fihier_rep.txt",liste);
     libererMatrice(Matrice,n);
     libererListe(liste);

     return 0;
}
