#include "hamming.h"
#include <string.h>

int compute(const char* lhs, const char* rhs){
    if((int)strlen(lhs)!=(int)strlen(rhs)) return -1;
    int counteur=0;
    for(int i=0;i<(int)strlen(lhs);i++){
        counteur+=isOkay(lhs[i], rhs[i]);
    }
    return counteur;
}

int isOkay(char lhs,char rhs){
    switch (lhs){
        case 'C': if(rhs=='C') return 0; break;
        case 'A': if(rhs=='A') return 0; break;
        case 'G': if(rhs=='G') return 0; break;
        case 'T': if(rhs=='T') return 0; break;
    }
    return 1;
}