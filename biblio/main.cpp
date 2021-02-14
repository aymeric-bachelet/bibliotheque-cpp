#include<iostream>
#include<string>
#include "livre.h"
using namespace std;


int main() {
	t_liste biblio;
	t_listeAut listAut;
	int choix, i;
	char car;
	biblio.nbLivre = 0;
	listAut.nbAuteur = 0;
	int id;
	car = 'o';
	setlocale(LC_ALL, "");

	cout << "  " << endl;


	cout << "     ...     ..         .          ..          ..    .                     s                                                                 " << endl;
	cout << "  .=*8888x <\"?88h.     @88>  . uW8\"      x .d88\"    @88>                  :8      .uef^\"                                                     " << endl;
	cout << " X>  '8888H> '8888     %8P   `t888        5888R     %8P          u.      .88    :d88E                                 x.    .                " << endl;
	cout << "'88h. `8888   8888      .     8888   .    '888R      .     ...ue888b    :888ooo `888E            .u        .u@u     .@88k  z88u        .u    " << endl;
	cout << "'8888 '8888    \"88>   .@88u   9888.z88N    888R    .@88u   888R Y888r -*8888888  888E .z8k    ud8888.   .zWF8888bx ~\"8888 ^8888     ud8888.  " << endl;
	cout << " `888 '8888.xH888x.  ''888E`  9888  888E   888R   ''888E`  888R I888>   8888     888E~?888L :888'8888. .888  9888    8888  888R   :888'8888. " << endl;
	cout << "   X\" :88*~  `*8888>   888E   9888  888E   888R     888E   888R I888>   8888     888E  888E d888 '88%\" I888  9888    8888  888R   d888 '88%\" " << endl;
	cout << " ~\"   !\"`      \"888>   888E   9888  888E   888R     888E   888R I888>   8888     888E  888E 8888.+\"    I888  9888    8888  888R   8888.+\"    " << endl;
	cout << "  .H8888h.      ?88    888E   9888  888E   888R     888E  u8888cJ888   .8888Lu=  888E  888E 8888L      I888  9888    8888 ,888B . 8888L      " << endl;
	cout << " :\"^\"88888h.    '!     888&  .8888  888\"  .888B .   888&   \"*888*P\"    ^%888*    888E  888E '8888c. .+ `888Nx?888   \"8888Y 8888\"  '8888c. .+ " << endl;
	cout << " ^    \"88888hx.+\"      R888\"  `%888*%\"    ^*888%    R888\"    'Y\"         'Y\"    m888N= 888>  \"88888%    \"88\" '888    `Y\"   'YP     \"88888%   " << endl;
	cout << "        ^\"**\"\"          \"\"       \"`         \"%       \"\"                          `Y\"   888     \"YP'           88E                    \"YP'    " << endl;
	cout << "                                                                                      J88\"                    98>                            " << endl;
	cout << "                                                                                      @%                      '8                             " << endl;
	cout << "                                                                                    :\"                         `                             " << endl;
	cout << " " << endl;
	do
	{
		cout << endl;
		etat(biblio, listAut);
		ensemble(biblio, listAut);
		cout << " _____________________________________________" << endl;
		cout << "|	  __  __                              |" << endl;
		cout << "|	 |  \\/  | ___ _ __  _   _             |" << endl;
		cout << "|	 | |\\/| |/ _ \\ '_ \\| | | |            |" << endl;
		cout << "|	 | |  | |  __/ | | | |_| |            |" << endl;
		cout << "|	 |_|  |_|\\___|_| |_|\\__,_|            |" << endl;
		cout << "|                                             |" << endl;
		cout << "|	1 - Afficher la bibliothèque          |" << endl;
		cout << "|	2 - Ajouter un livre                  |" << endl;
		cout << "|	3 - Supprimer un livre                |" << endl;
		cout << "|	4 - Rechercher un livre               |" << endl;
		cout << "|	5 - Supprimer un auteur               |" << endl;
		cout << "|	6 - Quitter                           |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << " " << endl;
		cout << "Veuillez saisir votre choix : ";
		cin >> choix;
		switch (choix)
		{
		case 1:
			if (biblio.nbLivre == 0) {
				cout << "il n'y a pas de livre" << endl;
			}
			else {
				affiche(biblio, listAut);
			}
			break;
		case 2:
			ajouter(biblio, listAut);
			break;
		case 3:
			id = recherche(biblio, listAut);
			supprimer(biblio, listAut, id);
			break;
		case 4:
			id = recherche(biblio, listAut);
			if (id == -1) {
				cout << "Aucun livre ne correspond.";
			}
			else {
				cout << "Titre : " << biblio.maBib[id].titre << endl;
				affiche_aut(biblio.maBib[id].auteur, listAut);
				cout << endl << "Date parution : " << biblio.maBib[id].annee << endl;
				cout << "Nombre de pages : " << biblio.maBib[id].nbPages << endl << endl;
			}
			break;
		case 5:
			supprimerAut(biblio, listAut);
			break;
		case 6: cout << "Au revoir !" << endl;
			break;
		default: cout << "Une erreur s'est produite." << endl;

		}



	} while (choix != 6);
}