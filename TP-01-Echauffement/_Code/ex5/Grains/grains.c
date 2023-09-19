#include "grains.h"

uint64_t square(uint8_t index){
    if(index==0) return 0;
    uint64_t grains=1;
    for(int i=1; i<index; i++){
        grains*=2;
    }
    return grains;
}

uint64_t total(void){
    uint64_t sumGrains=0;
    for(uint64_t i=1; i<=64; i++){
        sumGrains+=square(i);
    }
    return sumGrains;
}