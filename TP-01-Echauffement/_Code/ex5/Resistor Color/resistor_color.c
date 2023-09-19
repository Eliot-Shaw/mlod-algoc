#include "resistor_color.h"
const resistor_band_t tableau[]={
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
};
int color_code(resistor_band_t couleur){
    return couleur;
}


const resistor_band_t* colors(){
    return tableau;
}