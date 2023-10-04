#include "LinkedListOfDaftPunk.h"

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creerListe(Element v){
	Liste l_creer = malloc(sizeof(Cellule));
	if(l_creer == NULL){
		printf("TOUT CASSAY !!!\n");
		return NULL;
	}
	l_creer->val = v;
	l_creer->suiv = NULL;
	return l_creer;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste l_creer = creerListe(v);
	l_creer->val = v;
	l_creer->suiv = l;
	return l_creer;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste actuel = l;
	while(actuel != NULL){
		afficheElement(actuel->val);
		actuel = actuel->suiv;
	}
	printf("Fin de liste !\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l == NULL){
		printf("Fin de liste !\n");
		return;
	}
	afficheElement(l->val);
	afficheListe_r(l->suiv);
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste actuel = l;
	Liste viseur;
	while(actuel != NULL){
		viseur = actuel->suiv;
		detruireElement(actuel->val);
		free(actuel);
		actuel = viseur;
	}
	printf("\nFully destroyed iteratively, daddy vibes\n");
}

// version récursive
void detruire_r(Liste l) {
	if(l == NULL){
		printf("\nFully destroyed recursively, mummy vibes\n");
		return;
	}
	detruire_r(l->suiv);
	detruireElement(l->val);
	free(l);
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if(l==NULL){
		l = creerListe(v);
		return l;
	}
	Liste actuel = l;
	Liste viseur = l;
	//aller a la fin
	while(viseur != NULL){
		actuel = viseur;
		viseur = actuel->suiv;
	}
	actuel->suiv = creerListe(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l == NULL){
		l = creerListe(v);
		return l;
	}else if(l->suiv == NULL){
		l->suiv = creerListe(v);
		return l;
	}
	ajoutFin_r(v, l->suiv);
	return l;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste actuel = l;
	while(actuel != NULL){
		if(equalsElement(actuel->val, v)) return actuel;
		actuel = actuel->suiv;
	}
	return actuel;	
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l == NULL){
		return NULL;
	}
	else if(l->suiv == NULL){
		return NULL;
	}
	if(equalsElement(l->val, v)){
		return l;
	}
	return cherche_r(v, l->suiv);
	}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste actuel = l;
	Liste precedent = l;
	if(equalsElement(l->val, v)){
			actuel = l->suiv;
			detruireElement(l->val);
			free(l);
			return actuel;
		}
	while(actuel != NULL){
		if(equalsElement(actuel->val, v)){
			precedent->suiv = actuel->suiv;
			detruireElement(actuel->val);
			free(actuel);
			return l;
		}
		precedent = actuel;
		actuel = actuel->suiv;
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (!estVide(l)){
		if (equalsElement(l->val, v)){
			l=l->suiv;
			return l;
		}else{
			l->suiv=retirePremier_r(v, l->suiv);
		}		
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if (!estVide(l))
	{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}


void afficheElement(Element e){
	Music* elemento = (Music*)e;
	printf("-Name: %s\t-Artist: %s\t-Album: %s\t-Genre: %s\t-Disco Numberu: %d\t-Tracu Numberu: %d\t-Yeet: %d\n",
	elemento->name,elemento->artist,elemento->album,elemento->genre,elemento->discnumberu,elemento->tracnumberu,elemento->yeet);
}

void detruireElement(Element e){
	Music* elemento = (Music*)e;
	free(elemento->name);
	free(elemento->artist);
	free(elemento->album);
	free(elemento->genre);
	free(elemento);
}

bool equalsElement(Element e1, Element e2){
	bool egalite = true;
	Music* elemento1 = (Music*)e1;
	Music* elemento2 = (Music*)e2;
	if(strcmp(elemento1->name, elemento2->name)==0) egalite = false;
	if(strcmp(elemento1->artist, elemento2->artist)==0) egalite = false;
	if(strcmp(elemento1->album, elemento2->album)==0) egalite = false;
	if(strcmp(elemento1->genre, elemento2->genre)==0) egalite = false;
	if(elemento1->discnumberu == elemento2->discnumberu) egalite = false;
	if(elemento1->tracnumberu == elemento2->tracnumberu) egalite = false;
	if(elemento1->yeet == elemento2->yeet) egalite = false;
	return egalite;
}

//**************************************************************


int numberOfMusics(FILE* file_input){
	rewind(file_input);
	char tete_lecture = ' ';
	int compteur=0;
	while(tete_lecture != EOF){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == '\n'){
			compteur++;
		}
	}
	return compteur; // 2701 de base
}

void aller_a_info(FILE* file_input, int numero_music, int partie){
	//aller a la numero_music et à la partie
	rewind(file_input);

	int numero_music_actif=1;
	int numero_partie_active=1;
	char tete_lecture = ' ';

	while(numero_music_actif != numero_music){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == '\n'){
			numero_music_actif++;
		}
	}

	while(numero_partie_active != partie){
		tete_lecture =  fgetc(file_input);
		if (tete_lecture == ','){
			numero_partie_active++;
		}
	}
}

int compter_taille(FILE* file_input, int numero_music, int partie){
	aller_a_info(file_input, numero_music, partie);
	//compter le nombre de caracteres avant un ; ou un \n
	int compteur = 0;
	char tete_lecture = ' ';

	while(tete_lecture != EOF && tete_lecture != ',' && tete_lecture != '\n'){
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

Music* creerMusic(FILE* file_input, int numero_music){
	Music* m_creer= malloc(sizeof(Music));
	if(m_creer == NULL){
		printf("TOUT CASSAY !!!\n");
		return NULL;
	}
	int taille_name = compter_taille(file_input, numero_music, 1);
	char* name = calloc(taille_name+1, sizeof(char));
	data_remplir(file_input, numero_music, 1, name, taille_name);

	int taille_artist = compter_taille(file_input, numero_music, 2);
	char* artist = calloc(taille_artist+1, sizeof(char));
	data_remplir(file_input, numero_music, 2, artist, taille_artist);

	int taille_album = compter_taille(file_input, numero_music, 3);
	char* album = calloc(taille_album+1, sizeof(char));
	data_remplir(file_input, numero_music, 3, album, taille_album);

	int taille_genre = compter_taille(file_input, numero_music, 4);
	char* genre = calloc(taille_genre+1, sizeof(char));
	data_remplir(file_input, numero_music, 4, genre, taille_genre);
	//+1 pour le \0 a la fin du chat*
	aller_a_info(file_input, numero_music, 5);
	int discN;
	fscanf(file_input, "%d", &discN);
	aller_a_info(file_input, numero_music, 6);
	int tracN;
	fscanf(file_input, "%d", &tracN);
	aller_a_info(file_input, numero_music, 7);
	int yeet;
	fscanf(file_input, "%d", &yeet);


	m_creer->name = name;
	m_creer->artist = artist;
	m_creer->album = album;
	m_creer->genre = genre;
	m_creer->discnumberu = discN;
	m_creer->tracnumberu = tracN;
	m_creer->yeet = yeet;

	return m_creer;
}

