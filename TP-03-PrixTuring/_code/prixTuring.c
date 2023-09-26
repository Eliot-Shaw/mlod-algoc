#include "prixTuring.h"

int main(int argc, char** argv){
	char filename[] = "../_data/turingWinners.csv";
	char outputFilename[] = "../_data/out.csv";

	FILE* file_input;
	FILE* file_output;

	file_input = fopen(filename,"r");

	printf("coucou, %d lignes", numberOfWinners(file_input));

	fclose(file_input);

	return EXIT_SUCCESS;
}


int numberOfWinners(FILE* file_input){
	char tete_lecture = ' ';
	int compteur=1; //on compte à partir de la ligne 1
	while(tete_lecture != EOF){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == '\n'){
			compteur++;
		}
	}
	return compteur;
}

// ---------------------------------



Ligne* ligne_creer(int valInit, int annee, char* gagnant, char* info){
	
}

void ligne_destroy(Ligne* ligADestroy){

}

void ligne_print(Ligne ligneResultat){

}


int** tab_lignes_creer(int nbLignes){

}

void tab_lignes_destroy(int* nbLignes){

}