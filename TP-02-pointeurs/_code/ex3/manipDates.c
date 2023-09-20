#include "manipDates.h"

int main(){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    return 42;
}


void initialiseDate(Date* date){
    int jourUser;
    printf("Azi donnes un jour :");
    scanf("%d", &jourUser);
    date->jour = jourUser;

    int moisUser;
    printf("Okay, donnes un mois (numerique) :");
    scanf("%d", &moisUser);
    date->mois = moisUser;
    
    int anUser;
    printf("Good, donnes un an :");
    scanf("%d", &anUser);
    date->annee = anUser;
}


void afficheDate(Date* date){
    printf("\n--\nLa date d'ajourd'hui est : ");
    printf("%d %u %d\n--\n", date->jour, date->mois, date->annee);
}


Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}


