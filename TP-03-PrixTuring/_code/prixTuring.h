/**
Compilation
    gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

Exécution
    ./prixTuring

Tests
    diff out.csv turingWinners.csv

Exemple valeurs du csv
    annee;nomGagnant1,nomGagnant2;info1,info2,info3
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct LIGNE{
    int annee;
    char* gagnant;
    char* info;
    int* ptr;
} Ligne;


Ligne ligne_creer(int valInit, int annee, char* gagnant, char* info);
void ligne_destroy(Ligne* ligADestroy);
void ligne_print(Ligne ligneResultat);
int* ligne_lig(Ligne ligne,int nbLig);
