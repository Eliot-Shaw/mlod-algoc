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

typedef struct {
    int annee;
    char* gagnant;
    char* info;
} Winner;


int numberOfWinners(FILE* file_input);

void aller_a_info(FILE* file_input, int numero_winner, int partie);

int compter_taille(FILE* file_input, int numero_winner, int zone);

void data_remplir(FILE* file_input, int numero_winner, int partie, char* data, int taille_data);

Winner* winner_creer(FILE* file_input, int numero_winner);
void winner_remplir(Winner* ptr_winner, int annee, char* gagnant, char* info);
void winner_destroy(Winner* winner_destroy);

Winner** tab_winners_creer(FILE* file_input);
void tab_winners_remplir(FILE* file_input, Winner** tab_winners, int number_of_winners);
void tab_winners_destroy(FILE* file_input, Winner** tab_winners);

Winner** readWinners(FILE* file_input);
void printWinners(FILE* file_input);