#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Matrice{
    int64_t** mat;
} Matrice;


void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]);
int matrix_mult_locale(int64_t matrice1[][SIZE], int64_t matrice2[][SIZE], int lig, int col);
void matrix_print(int64_t matriceResultat[][SIZE]);
Matrice* creer(int64_t valInit, int64_t nbLig, int64_t nbCol);