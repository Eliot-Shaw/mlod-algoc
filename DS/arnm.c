// Shaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct difference{
	int index;
	int distance;
} Difference;


// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int* statistics(char* nucleotides){
	int nucleotides_length = strlen(nucleotides);
	int* stat_ATCG= calloc(sizeof(int), 4);
	for(int i=0; i<nucleotides_length; i++){
		switch(nucleotides[i]) {
			case 'A': stat_ATCG[0]++;break;
			case 'T': stat_ATCG[1]++;break;
			case 'C': stat_ATCG[2]++;break;
			case 'G': stat_ATCG[3]++;break;
			default: return NULL;
		}
	}
	for(int i=0; i<4; i++){
		stat_ATCG[i] = (stat_ATCG[i]*100)/nucleotides_length;
	}
	return stat_ATCG;
}

Difference* computeDifferenceBetween(const char* nucleotides_original,const char* nucleotides_replique){
	int nucleotides_length = strlen(nucleotides_original);
	int* is_difference = calloc(sizeof(int), nucleotides_length);
	int number_difference=0;
	for(int i=0; i<nucleotides_length; i++){
		if(nucleotides_original[i] != nucleotides_replique[i]){
			is_difference[i]++;
			number_difference++;
		}
	}

	Difference* differences = calloc(sizeof(Difference), number_difference);
	int index_actuel_differences=0;
	for(int i=0; i<nucleotides_length; i++){
		if(is_difference[i] == 1){
			differences[index_actuel_differences].index = i;
			differences[index_actuel_differences].distance = abs(distanceBetweenNucleotides(nucleotides_original[i], nucleotides_replique[i]));
			index_actuel_differences++;
		}
	}

	return differences;
}

void printDifferences(Difference* differences){
	printf("\nComputed differences between two sequences :\n");

	int index_differences_courant = 0;
	while(differences[index_differences_courant].index < differences[index_differences_courant+1].index){ //je vais lire dans la memoire suivante alors que je sais pas si j'ai le droit, pasbo
		printf("<%d,%d>\t",differences[index_differences_courant].index, differences[index_differences_courant].distance);
		index_differences_courant++;
	}
	printf("\n");
}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    // printf("%s\n",code_proteine_spike_moderna);

	int* stat_ATCG= calloc(sizeof(int), 4);
	stat_ATCG = statistics(sequenceDeNucleotides);
	printf("Statistiques des nucleotides dans la sequence : %d,%d,%d,%d\n", stat_ATCG[0], stat_ATCG[1], stat_ATCG[2], stat_ATCG[3]);

	Difference* differences = computeDifferenceBetween(code_proteine_spike_pfizer, code_proteine_spike_moderna);

	printDifferences(differences);

	return EXIT_SUCCESS;
}

