#include "prixTuring.h"

int main(int argc, char** argv){
	char* filename = "_data/turingWinners.csv";
	char* outputFilename = "_data/out.csv";
	int arg_annee = 0;
	int arg_sort = 0;

	// remplir les infos des arguments
	for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 2 < argc) {
			filename = argv[i + 1];
			outputFilename = argv[i + 2];
            i++;
        } else if (strcmp(argv[i], "--info") == 0 && i + 1 < argc) {
            arg_annee = atoi(argv[i + 1]);
            i++;
        }else if(strcmp(argv[i], "--sort") == 0) {
			arg_sort = 1;
        }
    }
	
	FILE* file_input;
	FILE* file_output;
	file_input = fopen(filename,"r");
	file_output = fopen(outputFilename,"w");

	Winner** tab_winners = readWinners(file_input);

	if(arg_annee != 0){
		infosAnnee(file_input, tab_winners, arg_annee);
	}
	if(arg_sort == 0){
		printWinners(file_input, file_output, tab_winners);
	}else{
		sortTuringWinnersByYear(file_input, file_output, tab_winners);
	}

	tab_winners_destroy(file_input, tab_winners);

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
	return compteur; // 57 de base
}

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

Winner** readWinners(FILE* file_input){
	return tab_winners_creer(file_input);
	//oui on rename pas les fonctions
}

void printWinners(FILE* file_input, FILE* file_output, Winner** tab_winners){
	for(int i=0; i<numberOfWinners(file_input); i++){
		fprintf(
			file_output, 
			"%d;%s;%s\n", 
			tab_winners[i]->annee,
			tab_winners[i]->gagnant,
			tab_winners[i]->info);
	}
}

void infosAnnee(FILE* file_input, Winner** tab_winners, int arg_annee){
	int winner_line = 0;
	
	for(int i=0; i<numberOfWinners(file_input);i++){
		if(arg_annee == tab_winners[i]->annee){
			winner_line = i;
		}
	}
	if(winner_line != 0){
		printf("\n--\nL'annee %d, le(s) gagnant(s) ont ete : %s\nNature des travaux : %s\n--\n\n", tab_winners[winner_line]->annee, tab_winners[winner_line]->gagnant, tab_winners[winner_line]->info);
	}else{
		printf("\n--\nPas de gagnants pour l'annee %d\n--\n\n", arg_annee);
	}
}

void sortTuringWinnersByYear(FILE* file_input, FILE* file_output, Winner** tab_winners){
	
	
	for(int i=0; i<numberOfWinners(file_input); i++){
		fprintf(
			file_output, 
			"%d;%s;%s\n", 
			tab_winners[i]->annee,
			tab_winners[i]->gagnant,
			tab_winners[i]->info);
	}
}
