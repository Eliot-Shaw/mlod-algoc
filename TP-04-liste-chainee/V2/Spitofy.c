// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "LinkedListOfDaftPunk.h"

int main(){
	char* filename = "music.csv";
	FILE* file_input;
	file_input = fopen(filename,"r");

	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete(creerMusic(file_input, 5),l);
	l = ajoutTete(creerMusic(file_input, 2),l);
	l = ajoutTete(creerMusic(file_input, 1515),l);
	l = ajoutFin_i(creerMusic(file_input, 1514),l);
	l = ajoutFin_r(creerMusic(file_input, 1513),l);
	
	afficheListe_i(l);
	printf("numbermusic : %d",numberOfMusics(file_input));
	afficheListe_r(l);



	fclose(file_input);
	return EXIT_SUCCESS;
}



/*
int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

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

*/