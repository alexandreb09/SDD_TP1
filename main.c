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

     return 0;
}
