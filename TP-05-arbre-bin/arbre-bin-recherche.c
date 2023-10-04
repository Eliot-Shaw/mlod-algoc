#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return true;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire nouvArbre = malloc(sizeof(Noeud));
	nouvArbre->val = e;
	nouvArbre->filsDroit = NULL;
	nouvArbre->filsGauche = NULL;
	return nouvArbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire currentNode = a;
	while(currentNode!=NULL){
		if(currentNode->val<e){
			if(currentNode->filsGauche==NULL){currentNode->filsGauche = creer(e);return a;}
			currentNode=currentNode->filsGauche;
		}else if(currentNode->val>e){
			if(currentNode->filsDroit==NULL){currentNode->filsDroit = creer(e);return a;}
			currentNode=currentNode->filsGauche;
		}
		return a;
	}	
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(a->val == e){
		return a; //rien faire
	}
	if(a == NULL){
		return creer(e); //arbre vide->creer nouvel arbre
	}
	if(a->val > e){
		if(a->filsGauche==NULL){a->filsGauche = creer(e);return a;}
		insere_r(a->filsGauche,e);
	}else{
		if(a->filsDroit==NULL){a->filsDroit = creer(e);return a;}
		insere_r(a->filsDroit,e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(a==NULL){
		return 0;
	}
	return 1+nombreDeNoeud(a->filsGauche)+nombreDeNoeud(a->filsDroit);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(a==NULL){
		return -1;
	}
	if(a->val>e){
		return 1+profondeur(a->filsGauche, e);
	}else if(a->val<e){
		return 1+profondeur(a->filsDroit, e);
	}
	return 1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(a==NULL){
		return 0;
	}
	int hg = hauteur(a->filsGauche);
	int hd = hauteur(a->filsDroit);
	return(hg>hd? 1+hg:1+hd);
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element e){
	if(a == NULL){
		return a; //arbre vide
	}
	if(a->val > e){
		if(a->filsGauche->val==e){return a;}
		return pere(a->filsGauche,e);
	}else if(a->val < e){
		if(a->filsDroit==e){return a;}
		return pere(a->filsDroit,e);
	}
	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	if(a==NULL){
		return;
	}
	for(int i=1;i<hauteur(a);i++){
		printf("\t");
	}
	printf("%d\n",a->val);
	afficheRGD_r(a->filsGauche);
	afficheRGD_r(a->filsDroit);
}

void afficheGRD_r(ArbreBinaire a){
	if(a==NULL){
		return;
	}
	afficheRGD_r(a->filsGauche);
	for(int i=1;i<hauteur(a);i++){
		printf("\t");
	}
	printf("%d\n",a->val);
	afficheRGD_r(a->filsDroit);
}

void afficheGDR_r(ArbreBinaire a){
	if(a==NULL){
		return;
	}
	afficheRGD_r(a->filsGauche);
	afficheRGD_r(a->filsDroit);
	for(int i=1;i<hauteur(a);i++){
		printf("\t");
	}
	printf("%d\n",a->val);
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(a == NULL){
		return a; //arbre vide
	}
	if(a->filsGauche==NULL){return a;}
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(a == NULL){
		return a; //arbre vide
	}
	if(a->filsDroit==NULL){return a;}
	return min(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est e et NULL si e n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element e){
	if(a->val == e || a == NULL){
		return a;
	}
	if(a->val > e){
		return recherche_r(a->filsGauche,e);
	}else{
		return recherche_r(a->filsDroit,e);
	}
}


// suppime e de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element e){
	if(a == NULL){
		return creer(e); //arbre vide->creer nouvel arbre
	}
	if(a->val > e){
		if(a->filsGauche->val==e){
			ArbreBinaire doomed = a->filsGauche;
			a->filsGauche = doomed->filsGauche;
			detruire_r(doomed);
			return a;
		}
		supprimer_r(a->filsGauche,e);
	}else{
		if(a->filsDroit->val==e){
			ArbreBinaire doomed = a->filsDroit;
			a->filsDroit = doomed->filsDroit;
			detruire_r(doomed);
			return a;
		}
		supprimer_r(a->filsDroit,e);
	}
	return a;
}

void detruire_r(ArbreBinaire a){

}

