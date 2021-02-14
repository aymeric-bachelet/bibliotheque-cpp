#pragma once
#ifndef livre_h
#define livre_h
#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
const int MAX_AUT = 10;
typedef struct {
	int j;
	int m;
	int a;
}t_date;
typedef struct {
	string titre;
	int auteur;
	int annee;
	int nbPages;
}t_livre;

typedef struct {
	t_livre maBib[MAX];
	int nbLivre;
}t_liste;

typedef struct {
	string nom;
	string prenom;
	string natio;
	t_date	annee_nai;
	t_date annee_dc;
	bool  mort;
}t_auteur;

typedef struct {
	t_auteur auteur[MAX_AUT];
	int nbAuteur;
}t_listeAut;



void VerifDate(int a, int m, int j, int& ok);
void date(int& a, int& m, int& j);
void affiche(t_liste biblio, t_listeAut listAut);
void ajouter(t_liste& biblio, t_listeAut& listAut);
int rechercheAut(t_listeAut listAut);
void ensemble(t_liste& biblio, t_listeAut& listAut);
int recherche(t_liste biblio, t_listeAut listAut);
void supprimer(t_liste& biblio, t_listeAut& listAut, int id);
void affiche_aut(int i, t_listeAut listAut);
void supprimerAut(t_liste& biblio, t_listeAut& listAut);
void saisir_aut(t_listeAut& listAut, int& choix);
string Majuscule(string mot);
void etat(t_liste biblio, t_listeAut listAut);


#endif