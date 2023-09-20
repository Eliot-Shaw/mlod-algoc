#pragma once
#include <stdio.h>
#include <stdint.h>

typedef enum MOIS {
    janvier=1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    novembre,
    octobre,
    decembre
} Mois;

typedef struct DATE{
    int jour;
    Mois mois;
    int annee;
} Date;

void initialiseDate(Date* date);
void afficheDate(Date* date);
Date creerDateParCopie();
