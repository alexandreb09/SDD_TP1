#ifndef Gard1
#define Gard1
#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"

float ** FichierToMatrice(char *, int *, int *);
void AfficheMatrice(float **,int,int);

ListeCh_t * matToListe(float **,int,int);
void libererMatrice(float **, int);
void Ecrire(char *,ListeCh_t *);

#endif
