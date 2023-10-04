// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <string.h>
#include <stdlib.h>


int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("1",l);
	l = ajoutTete("2",l);
	l = ajoutTete("4",l);
	l = ajoutTete("1",l);
	l = ajoutTete("5",l);
	l = ajoutTete("6",l);
	l = ajoutTete("2",l);
	l = ajoutTete("4",l);
	l = ajoutTete("1",l);

	afficheListe_i(l);

	printf("ajoutFin_r(99)\n");
	ajoutFin_i("99",l);
	afficheListe_i(l);

	printf("ajoutFin_r(100)\n");
	ajoutFin_r("100",l);
	afficheListe_r(l);

	p = cherche_i("200",l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve, good":"[ERREUR] trouve !!!");

	p = cherche_i("99",l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve, good ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("0",l);
	printf("cherche_r(0) : %s\n",estVide(p)?"pas trouve, good":"[ERREUR] trouve !!!");

	p = cherche_r("99",l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve, good ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(200)   : ");
	l = retirePremier_i("200",l);
	afficheListe_r(l);

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("1",l);
	afficheListe_r(l);

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("1",l);
	afficheListe_r(l);

	printf("retirePremier_i(100) : ");
	l = retirePremier_i("100",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("4",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("4",l);
	afficheListe_r(l);

	printf("retirePremier_r(99)  : ");
	l = retirePremier_r("99",l);
	afficheListe_r(l);
	detruire_r(l);

	return EXIT_SUCCESS; 
}

void afficheElement(Element e){
	printf("%s ", (char*)e);
}

void detruireElement(Element e){
	//rien c'est des caracteres
}

bool equalsElement(Element e1, Element e2){
	return (strcmp(e1, e2)==0);
}