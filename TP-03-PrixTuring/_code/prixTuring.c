#include "prixTuring.h"

int main(int argc, char** argv){
	char filename[] = "../_data/turingWinners.csv";
	char outputFilename[] = "../_data/out.csv";

	FILE* file_input;
	FILE* file_output;

	file_input = fopen(filename,"r");
	file_output = fopen(outputFilename,"w");

	Winner** coucou = readWinners(file_input);

	printWinners(file_output, coucou);

	tab_winners_destroy(file_input, coucou);

	fclose(file_input);
	fclose(file_output);

	return EXIT_SUCCESS;
}


int numberOfWinners(FILE* file_input){
	rewind(file_input);
	char tete_lecture = ' ';
	int compteur=0;
	while(tete_lecture != EOF){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == '\n'){
			compteur++;
		}
	}
	return compteur;
}

// ---------------------------------

void aller_a_info(FILE* file_input, int numero_winner, int partie){
	//aller a la numero_winner et à la partie
	rewind(file_input);

	int numero_winner_actif=1;
	int numero_partie_active=1;
	char tete_lecture = ' ';

	while(numero_winner_actif != numero_winner){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == '\n'){
			numero_winner_actif++;
		}
	}

	while(numero_partie_active != partie){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == ';'){
			numero_partie_active++;
		}
	}
}

int compter_taille(FILE* file_input, int numero_winner, int partie){
	aller_a_info(file_input, numero_winner, partie);
	//compter le nombre de caracteres avant un ; ou un \n
	int compteur = 0;
	char tete_lecture = ' ';

	while(tete_lecture != EOF && tete_lecture != ';' && tete_lecture != '\n'){
		tete_lecture =  fgetc(file_input);
		compteur++;
	}
	return compteur;
}

void data_remplir(FILE* file_input, int numero_winner, int partie, char* data, int taille_data){
	aller_a_info(file_input, numero_winner, partie);
	fgets(data, taille_data, file_input);
	data[taille_data] = '\0';
}

Winner* winner_creer(FILE* file_input, int numero_winner){
	Winner* ptr_winner = malloc(sizeof(Winner));
	int taille_gagnant = compter_taille(file_input, numero_winner, 2);
	int taille_info = compter_taille(file_input, numero_winner, 3);
	char* gagnant = calloc(taille_gagnant+1, sizeof(char));
	char* info = calloc(taille_info+1, sizeof(char));
	//+1 pour le \0 a la fin du chat*
	aller_a_info(file_input, numero_winner, 1);
	
	int annee;
	fscanf(file_input, "%d", &annee);
	data_remplir(file_input, numero_winner, 2, gagnant, taille_gagnant);
	data_remplir(file_input, numero_winner, 3, info, taille_info);

	winner_remplir(ptr_winner, annee, gagnant, info);
	return ptr_winner;
}

void winner_remplir(Winner* ptr_winner, int annee, char* gagnant, char* info){
	ptr_winner->annee = annee;
    ptr_winner->gagnant = gagnant;
    ptr_winner->info = info;
}

void winner_destroy(Winner* winner_destroy){
	free(winner_destroy);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++

Winner** tab_winners_creer(FILE* file_input){
	int number_of_winners = numberOfWinners(file_input);
	Winner** tab_winners = calloc(number_of_winners, sizeof(Winner*));
	tab_winners_remplir(file_input, tab_winners, number_of_winners);
	return tab_winners;
}

void tab_winners_remplir(FILE* file_input, Winner** tab_winners, int number_of_winners){
	for(int i=0; i<number_of_winners; i++){
		tab_winners[i] = winner_creer(file_input, i+1);
	}

}

void tab_winners_destroy(FILE* file_input, Winner** tab_winners){
	int number_of_winners = numberOfWinners(file_input);
	for(int i=0; i<number_of_winners; i++){
		winner_destroy(tab_winners[i]);
	}
	free(tab_winners);
}

// +*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+


Winner** readWinners(FILE* file_input){
	return tab_winners_creer(file_input);
	//oui on rename pas les fonctions
}

void printWinners(FILE* file_output, Winner** tab_winners){
	for(int i=0; i<57; i++){
		fprintf(
			file_output, 
			"%d;%s;%s\n", 
			tab_winners[i]->annee,
			tab_winners[i]->gagnant,
			tab_winners[i]->info);
	}
}
