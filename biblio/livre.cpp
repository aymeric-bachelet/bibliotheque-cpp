#include<iostream>
#include<string>
#include"livre.h"
using namespace std;

void VerifDate(int a, int m, int j, int& ok)
{
	if (m < 1 || m > 12) //On vérifie que le mois saisie est compris entre Janvier et Décembre.
	{
		cout << "Erreur, veuillez saisir une valeur de mois comprise entre 1 et 12." << endl;
		ok = 0;
	}
	else
	{
		if (m == 2) //On traite le cas particulier de Février.
		{
			if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) //On vérifie si une année est bisextile.
			{
				if (j >= 1 && j <= 29) //On vérifie si en cas d'années bisextiles le jour de Février est compris entre le 1 et le 29.
				{
					cout << "La date est valide." << endl;
					ok = 1;
				}
				else
				{
					cout << "La date n'est pas valide." << endl;
					ok = 0;
				}
			}
			else
			{
				if (j < 1 && j > 28) //On vérifie si en cas d'années classiques le jour de Février est compris entre le 1 et le 28.
				{
					cout << "La date n'est pas valide." << endl;
					ok = 0;
				}
				else
				{
					cout << "La date est valide." << endl;
					ok = 1;
				}
			}
		}
		else
		{
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 10 || m == 12) //Représente tout les mois de 31 jours.
			{
				if (j<1 || j>31) //On vérifie que le jour saisie soit compris entre 1 et 31.
				{
					cout << "La date saisie n'est pas valide." << endl;
					ok = 0;
				}
				else
				{
					cout << "La date saisie est valide." << endl;
					ok = 1;
				}
			}
			else
			{
				if (m != 2)
				{
					if (j<1 || j>30) //Les mois qui n'ont pas 31 jours en ont 30 à l'exception de Février, cas traité plus haut.
					{
						cout << "La date saisie n'est pas valide." << endl;
						ok = 0;
					}
					else
					{
						cout << "La date saisie est valide." << endl;
						ok = 1;
					}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void date(int& a, int& m, int& j)
{
	int ok;

	do
	{
		cout << "Veuillez saisir le jour : ";
		cin >> j;
		cout << "Veuillez saisir le mois : ";
		cin >> m;
		cout << "Veuillez saisir l'annee : ";
		cin >> a;
		VerifDate(a, m, j, ok);
	} while (ok != 1);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

string Majuscule(string mot)
{
	int i;

	for (i = 0; i < mot.length(); i++)
	{
		if (mot[i] >= 'a' && mot[i] <= 'z')
		{
			mot[i] = (mot[i] - 'a' + 'A');
		}
	}
	return mot;
}

void affiche(t_liste biblio, t_listeAut listAut) {
	setlocale(LC_ALL, "");
	int i;
	for (i = 0; i <= biblio.nbLivre - 1; i++) {
		cout << "Titre : " << biblio.maBib[i].titre << endl;
		affiche_aut(biblio.maBib[i].auteur, listAut);
		cout << "Date parution : " << biblio.maBib[i].annee << endl;
		cout << "Nombre de pages : " << biblio.maBib[i].nbPages << endl << endl;
	}
}

void ajouter(t_liste& biblio, t_listeAut& listAut) {
	setlocale(LC_ALL, "");
	int choix;
	choix = 0;
	if (biblio.nbLivre >= 0 && biblio.nbLivre < MAX) {
		cout << "Saisir  le titre : ";
		cin >> biblio.maBib[biblio.nbLivre].titre;
		cout << "Saisir l'auteur : ";
		saisir_aut(listAut, choix);
		biblio.maBib[biblio.nbLivre].auteur = choix;
		cout << "Saisir  l'annee de parution : ";
		cin >> biblio.maBib[biblio.nbLivre].annee;
		if (listAut.auteur[choix].mort) {
			while (biblio.maBib[biblio.nbLivre].annee < listAut.auteur[biblio.maBib[biblio.nbLivre].auteur].annee_nai.a || biblio.maBib[biblio.nbLivre].annee > listAut.auteur[biblio.maBib[biblio.nbLivre].auteur].annee_dc.a) {
				cout << "Une erreur s'est produite, veuillez resaisir : ";
				cin >> biblio.maBib[biblio.nbLivre].annee;
			}
		}
		else {
			while (biblio.maBib[biblio.nbLivre].annee < listAut.auteur[biblio.maBib[biblio.nbLivre].auteur].annee_nai.a) {
				cout << "Une erreur s'est produite, veuillez resaisir : ";
				cin >> biblio.maBib[biblio.nbLivre].annee;
			}
		}
		cout << "Saisir  le nb de pages : ";
		cin >> biblio.maBib[biblio.nbLivre].nbPages;
		while (biblio.maBib[biblio.nbLivre].nbPages < 0) {
			cout << "impossible de saisir un nombre négatif, resaisir : ";
			cin >> biblio.maBib[biblio.nbLivre].nbPages;
		}
		biblio.nbLivre++;
	}
	else {
		cout << "Une erreurs'est produite." << endl;
	}
}

int recherche(t_liste biblio, t_listeAut listAut) {
	setlocale(LC_ALL, "");
	string livre;
	int i;

	cout << "Saisir un livre : ";
	cin >> livre;
	i = 0;



	while (Majuscule(livre) != Majuscule(biblio.maBib[i].titre) && i < biblio.nbLivre) {

		i++;
	}
	if (Majuscule(biblio.maBib[i].titre) == Majuscule(livre)) {
		return i;
	}
	else {
		return -1;
	}
}
int rechercheAut(t_listeAut listAut) {
	setlocale(LC_ALL, "");
	string nom, prenom;
	int i;

	cout << "Saisir nom de l'auteur : ";
	cin >> nom;

	cout << "Saisir prenom de l'auteur : ";
	cin >> prenom;


	i = 0;

	while (Majuscule(nom) != Majuscule(listAut.auteur[i].nom) && Majuscule(prenom) != Majuscule(listAut.auteur[i].prenom) && i < listAut.nbAuteur) {

		i++;
	}
	if (Majuscule(nom) == Majuscule(listAut.auteur[i].nom) && Majuscule(prenom) == Majuscule(listAut.auteur[i].prenom)) {
		return i;
	}
	else {
		return -1;
	}
}

void supprimer(t_liste& biblio, t_listeAut& listAut, int id) {
	setlocale(LC_ALL, "");

	if (id < 0) {
		cout << "Aucun livre correspondant.";
	}
	else {
		while (id < MAX - 1) {
			biblio.maBib[id].titre = biblio.maBib[id + 1].titre;
			biblio.maBib[id].auteur = biblio.maBib[id + 1].auteur;
			biblio.maBib[id].annee = biblio.maBib[id + 1].annee;
			biblio.maBib[id].nbPages = biblio.maBib[id + 1].nbPages;
			id++;
		}

		biblio.nbLivre--;
	}
}
void supprimerAut(t_liste& biblio, t_listeAut& listAut) {
	setlocale(LC_ALL, "");
	int id, y, comp;
	comp = 0;
	id = rechercheAut(listAut);
	if (id < 0) {
		cout << "Aucun auteur correspondant.";
	}
	else {

		for (y = 0; y <= biblio.nbLivre - 1; y++) {
			if (biblio.maBib[y].auteur == id) {
				supprimer(biblio, listAut, id);
			}
		}
		biblio.nbLivre = biblio.nbLivre - comp;
		while (id < MAX_AUT - 1) {
			listAut.auteur[id].nom = listAut.auteur[id + 1].nom;
			listAut.auteur[id].prenom = listAut.auteur[id + 1].prenom;
			listAut.auteur[id].natio = listAut.auteur[id + 1].natio;
			listAut.auteur[id].annee_nai = listAut.auteur[id + 1].annee_nai;
			listAut.auteur[id].annee_dc = listAut.auteur[id + 1].annee_dc;
			for (y = id; y <= biblio.nbLivre - 1; y++) {
				if (id < biblio.maBib[y].auteur) {
					biblio.maBib[y].auteur = biblio.maBib[y].auteur - 1;
				}
			}
			id++;
		}

		listAut.nbAuteur--;
	}
}

void etat(t_liste biblio, t_listeAut listAut)
{
	if (biblio.nbLivre == 0) {
		cout << "Votre bibliotheque est vide." << endl;
	}
	else {
		if (biblio.nbLivre == MAX) {
			cout << "Votre bibliotheque est pleine." << endl;
		}
		else {
			cout << "La bibliotheque contient : " << biblio.nbLivre << " livre(s) et " << listAut.nbAuteur << " auteur(s)." << endl;
		}
	}
}

void ensemble(t_liste& biblio, t_listeAut& listAut)
{
	int i, j, n, occ;

	n = biblio.nbLivre;
	occ = 0;		//occ correspond au nombre d occurence(s) d un meme livre dans la bibliotheque
	i = 0;
	j = 1;			//on fait j a 1 afin de ne pas comparer un livre avec lui meme

	while ((occ < 1) && (i < n))		//on s arrete lorsque le nombre d occurence d un meme livre depasse 0
	{
		while ((j < n) && (occ < 1))
		{
			if ((biblio.maBib[i].titre == biblio.maBib[j].titre) && (biblio.maBib[i].auteur == biblio.maBib[j].auteur) && (biblio.maBib[i].nbPages == biblio.maBib[j].nbPages) && (biblio.maBib[i].annee == biblio.maBib[j].annee))
			{							//on verifie que tous les elements des deux livres soit egaux avant d augmenter occ de 1
				occ = occ + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}

	if (occ >= 1)			//si occ est superieur ou egal a 1 on indique que la bibliotheque n est pas un ensemble
	{
		cout << "La bibliotheque n'est pas un ensemble" << endl;
	}
	else					//on indique que la bibliotheque est un ensemble dans le cas contraire
	{
		cout << "La bibliotheque est un ensemble" << endl;
	}

}

void affiche_aut(int i, t_listeAut listAut) {
	setlocale(LC_ALL, "");
	cout << "Auteur : ";
	cout << "	Nom : " << listAut.auteur[i].nom << endl;
	cout << "	Prenom : " << listAut.auteur[i].prenom << endl;
	cout << "	Nationalite : " << listAut.auteur[i].natio << endl;
	cout << "	Annee de naissance : " << listAut.auteur[i].annee_nai.j << "/" << listAut.auteur[i].annee_nai.m << "/" << listAut.auteur[i].annee_nai.a << endl;

	if (listAut.auteur[i].mort) {
		cout << "	Annee de décès : " << listAut.auteur[i].annee_dc.j << "/" << listAut.auteur[i].annee_dc.m << "/" << listAut.auteur[i].annee_dc.a << endl;
	}
}

void saisir_aut(t_listeAut& listAut, int& choix) {
	setlocale(LC_ALL, "");

	int choix2, j, m, a,
		i;
	char car;

	for (i = 0; i <= listAut.nbAuteur - 1; i++) {
		cout << i << " " << listAut.auteur[i].nom << endl;
	}

	cout << "Donnez votre choix (-1 pour ajouter un auteur) : ";
	cin >> choix2;

	if (choix2 == -1) {
		if (listAut.nbAuteur < MAX_AUT) {

			cout << "Saisir le nom : ";
			cin >> listAut.auteur[listAut.nbAuteur].nom;
			cout << "Saisir le prenom : ";
			cin >> listAut.auteur[listAut.nbAuteur].prenom;
			cout << "Saisir la nationalite : ";
			cin >> listAut.auteur[listAut.nbAuteur].natio;
			cout << "Saisir la date de naissance : ";
			date(a, m, j);
			listAut.auteur[listAut.nbAuteur].annee_nai.j = j;
			listAut.auteur[listAut.nbAuteur].annee_nai.m = m;
			listAut.auteur[listAut.nbAuteur].annee_nai.a = a;
			cout << "Saisir la date de deces (o/n) : ";
			cin >> car;
			if (car == 'o') {
				date(a, m, j);
				listAut.auteur[listAut.nbAuteur].annee_dc.j = j;
				listAut.auteur[listAut.nbAuteur].annee_dc.m = m;
				listAut.auteur[listAut.nbAuteur].annee_dc.a = a;
				while (listAut.auteur[listAut.nbAuteur].annee_dc.j <= listAut.auteur[listAut.nbAuteur].annee_nai.j && listAut.auteur[listAut.nbAuteur].annee_dc.m <= listAut.auteur[listAut.nbAuteur].annee_nai.m && listAut.auteur[listAut.nbAuteur].annee_dc.a <= listAut.auteur[listAut.nbAuteur].annee_nai.a) {
					cout << " Erreur date impossible, ressaisir : ";
					date(a, m, j);
					listAut.auteur[listAut.nbAuteur].annee_dc.j = j;
					listAut.auteur[listAut.nbAuteur].annee_dc.m = m;
					listAut.auteur[listAut.nbAuteur].annee_dc.a = a;
				}
				listAut.auteur[listAut.nbAuteur].mort = true;
			}
			else {
				listAut.auteur[listAut.nbAuteur].mort = false;
			}
			choix = listAut.nbAuteur;
			listAut.nbAuteur++;

		}
		else {
			cout << "Impossible d'ajouter l'auteur, plus de place." << endl;
		}
	}
	else {
		choix = choix2;
	}
}