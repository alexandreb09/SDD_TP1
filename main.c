#include "TP1.h"
#include <stdio.h>


int main (){
     int n,m;
     char * NomFichier = "test.txt";
     float ** Matrice = FichierToMatrice(NomFichier,&n,&m);
     AfficheMatrice(Matrice,n,m);
}
