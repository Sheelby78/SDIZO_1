#include <iostream>
#include "MenuStruktur.h"

using namespace std;


int main()
{
	//menu glowne programu
	MenuStruktur mstr = *(new MenuStruktur());
	bool koniec = false;
	int wybor;
	while (!koniec) {
		cout << " MENU GLOWNE " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Tablica" << endl;
		cout << "2.  Lista" << endl;
		cout << "3.  Kopiec" << endl;
		cout << "4.  Drzewo czerwono czarne" << endl;
		cout << "5.  Zamkniecie programu " << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case 1:;	system("cls"); mstr.menuTablica(); break;
		case 2:;	system("cls"); mstr.menuLista(); break;
		case 3:;	system("cls"); mstr.menuKopiec(); break;
		case 4:;	system("cls"); mstr.menuCzerwonoCzarne(); break;
		case 5:;	koniec = true; break;
		default:	cout << "POMYLKA!";
		}
	}
}



