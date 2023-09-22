#include "matrices.h"

int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_printSize(matriceResultat);

    Matrice mat33 = matrix_creer(8, 3, 2);
    matrix_print(mat33);
    matrix_initLig(42, 2, mat33);
    matrix_print(mat33);


    return EXIT_SUCCESS;

}


void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]){
    for(int lig=0; lig<SIZE; lig++){
        for(int col=0; col<SIZE; col++){
            matriceResultat[lig][col]=matrix_mult_locale(matrice1, matrice2, lig, col);
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


void matrix_printSize(int64_t matriceResultat[][SIZE]){
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


Matrice matrix_creer(int64_t valInit, int64_t nbLig, int64_t nbCol){
    Matrice nouvelleMatrice;
    nouvelleMatrice.nbCol = nbCol;
    nouvelleMatrice.nbLig = nbLig;
    nouvelleMatrice.mat = malloc(sizeof(int64_t)*nbCol*nbLig);

    for (int r=0; r < nouvelleMatrice.nbLig; ++r){
        int64_t* row = matrix_lig(nouvelleMatrice, r);
        for (int c=0; c < nouvelleMatrice.nbCol; ++c)
            row[c] = c+r;
    }
    return nouvelleMatrice;
}

Matrice* matrix_creer_point(int64_t valInit, int64_t nbLig, int64_t nbCol){
    Matrice* ptrMat = malloc(sizeof(Matrice));
    ptrMat->nbCol = nbCol;
    ptrMat->nbLig = nbLig;
    ptrMat->mat = malloc(sizeof(int64_t)*nbCol*nbLig);

    for (int r=0; r < ptrMat->nbLig; ++r){
        int64_t* row = matrix_lig_point(ptrMat, r);
        for (int c=0; c < ptrMat->nbCol; ++c)
            row[c] = valInit;
    }
}

void matrix_destroy(Matrice* matADestroy){
    free(matADestroy->mat);
}

int64_t* matrix_lig(Matrice matriceAObs, int64_t nbLig){
    return (matriceAObs.mat + (nbLig * matriceAObs.nbCol));
}

int64_t* matrix_lig_point(Matrice* ptrMat, int64_t nbLig){
    return (ptrMat->mat + (nbLig * ptrMat->nbCol));
}

void matrix_print(Matrice matriceResultat){
    printf("\nImpression de la matrice finale :\n\n\n");
    for(int lig=0; lig<matriceResultat.nbLig; lig++){
        for(int col=0; col<matriceResultat.nbCol; col++){
            int64_t* row = matrix_lig(matriceResultat, lig);
            printf("%d", row[col]);
            printf("\t");
        }
        printf("\n");
        printf("\n");
    }
}



void matrix_initLig(int64_t valInit, int64_t numLig, Matrice matriceAObs){
    for (int r=0; r < matriceAObs.nbLig; ++r){
        int64_t* row = matrix_lig(matriceAObs, numLig);
        for (int c=0; c < matriceAObs.nbCol; ++c)
            row[c] = valInit;
    }}