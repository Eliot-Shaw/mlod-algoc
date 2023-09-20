#include "echangeContenu.h"

void echangeContenu(int* addA, int* addB){
    int temp;
    temp = *addA;
    *addA = *addB;
    *addB = temp;
}