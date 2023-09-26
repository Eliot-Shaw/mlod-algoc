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


int numberOfWinners(FILE* file_input);




Ligne* ligne_creer(int valInit, int annee, char* gagnant, char* info);
void ligne_destroy(Ligne* ligADestroy);
void ligne_print(Ligne ligneResultat);

int** tab_lignes_creer(int nbLignes);
void tab_lignes_destroy(int* nbLignes);