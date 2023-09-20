#include "matrices.h"

int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);
    return EXIT_SUCCESS;
}


void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]){
    for(int lig=0; lig<SIZE; lig++){
        for(int col=0; col<SIZE; col++){
            matriceResultat[lig][col]=matrix_mult_locale(matrice1,matrice2, lig, col);
        }
    }
}


int matrix_mult_locale(int64_t matrice1[][SIZE], int64_t matrice2[][SIZE], int lig, int col){
    int result = 0;
    for(int i=0; i<SIZE; i++){
        result += matrice1[lig][i]*matrice2[i][col];
    }
    return result;
}


void matrix_print(int64_t matriceResultat[][SIZE]){
    printf("\nImpression de la matrice finale :\n\n\n");
    for(int lig=0; lig<SIZE; lig++){
        for(int col=0; col<SIZE; col++){
            printf("%d", matriceResultat[lig][col]);
            printf("\t");
        }
        printf("\n");
        printf("\n");
    }
}