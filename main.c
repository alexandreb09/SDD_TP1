#include "TP1.h"
#include "ListeChainee.h"
#include <stdio.h>


int main (){
     int n,m;
     char * NomFichier = "test.txt";
     float ** Matrice = FichierToMatrice(NomFichier,&n,&m);
     AfficheMatrice(Matrice,n,m);
     /*
     ListeCh_t * maListe = NULL;
     insere(&Liste,2.5,20,40);
     insere(&Liste,55,22,44);
     insere(&Liste,99,4,88);*/
}
