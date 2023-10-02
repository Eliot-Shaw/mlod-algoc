#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
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
	Liste l_creer = creer(v);
	l_creer->val = v;
	l_creer->suiv = l;
	return l_creer;
}


void afficheElement(Element e) {
	printf("%i ",e);
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
	printf("\tFin de liste !\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l == NULL){
		printf("\tFin de liste !\n");
		return;
	}
	afficheElement(l->val);
	afficheListe_r(l->suiv);
}

void detruireElement(Element e) {}

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
		detruireElement(l->val);
		free(l);
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
		l = creer(v);
		return l;
	}
	Liste actuel = l;
	Liste viseur = l;
	//aller a la fin
	while(viseur != NULL){
		actuel = viseur;
		viseur = actuel->suiv;
	}
	actuel->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l == NULL){
		l = creer(v);
		return l;
	}else if(l->suiv == NULL){
		l->suiv = creer(v);
		return l;
	}
	ajoutFin_r(v, l->suiv);
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
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



