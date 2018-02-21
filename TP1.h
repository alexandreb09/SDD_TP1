#ifndef Gardien
#define Gardien
#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"

float ** FichierToMatrice(char *, int *, int *);

void AfficheMatrice(float **,int,int);

ListeCh_t * Mattoliste(float **,int,int,int);

#endif
