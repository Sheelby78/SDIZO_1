#include <iostream>
#include "Lista.h"
#include "Tablica.h"
#include "Kopiec.h"
#include "Timer.h"
#include "CzerwonoCzarne.h"
#include "MenuStruktur.h"
#include "MenuTesty.h"

using namespace std;

//menu dla listy
void MenuStruktur::menuLista() {
	MenuTesty mt = *(new MenuTesty());
	bool koniec = false;
	Lista list = *(new Lista());
	while (!koniec) {
		char wybor;
		cout << " MENU LISTY " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Wczytaj dane z pliku" << endl;
		cout << "2.  Dodaj element na poczatku" << endl;
		cout << "3.  Dodaj element na koncu" << endl;
		cout << "4.  Dodaj element gdziekolwiek " << endl;
		cout << "5.  Usun element na poczatku" << endl;
		cout << "6.  Usun element na koncu" << endl;
		cout << "7.  Usun element gdziekolwiek " << endl;
		cout << "8.  Wyswietl liste " << endl;
		cout << "9.  Wyszukaj element " << endl;
		cout << "a.  Automatyczne generowanie listy" << endl;
		cout << "t.  Testowanie" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1': {
			system("cls");
			cout << endl;
			string name;
			cout << "Podaj nazwe pliku bez rozszerzenia(.txt): ";
			cin >> name;
			if (list.fileRead(name)) {
				cout << endl << "Pomyslnie wczytano dane z pliku: " << name << ".txt" << endl << endl;
			}
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			list.addHead(value);
			cout << endl << "Elemnt zostal dodany na poczatek listy" << endl << endl;
			break;
		}
		case '3': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			list.addTail(value);
			cout << endl << "Elemnt zostal dodany na koniec listy" << endl << endl;
			break;
		}
		case '4': {
			system("cls");
			cout << endl;
			int value, position;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			cout << endl << "Podaj numer indeksu gdzie ma byc nowa wartosc : ";
			cin >> position;
			if (list.addIndex(value, position)) {
				cout << endl << "Elemnt zostal dodany pod indeksem [" << position << "]" << endl << endl;
			}
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			if (list.deleteHead()) {
				cout << endl << "Usunieto element z poczatku listy" << endl << endl;
			}
			break;
		}
		case '6': {
			system("cls");
			cout << endl;
			if (list.deleteTail()) {
				cout << endl << "Usunieto element z konca listy" << endl << endl;
			}
			break;
		}
		case '7': {
			system("cls");
			cout << endl;
			int position;
			if (list.isEmpty()) {
				cout << "Lista pusta" << endl << endl;
				break;
			}
			cout << "Podaj numer indeksu gdzie ma byc usuniety element: ";
			cin >> position;
			if (list.deleteIndex(position)) {
				cout << endl << "Elemnt zostal usuniety z indexu [" << position << "]" << endl << endl;
			}
			break;
		}
		case '8': {
			system("cls");
			cout << endl;
			list.displayList();
			cout << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}
		case 'a': {
			system("cls");
			cout << endl;
			int number, low, high;
			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			list.createRandom(number, low, high);
			cout << endl << "Wylosowano [" << number << "] elementow" << endl << endl;
			break;
		}
		case '9': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj poszukiwana wartosc: ";
			cin >> value;
			if (list.searchValue(value) != -1) {
				cout << endl << "Numer indeksu elementu o wartosci:" << value << " to: [" << list.searchValue(value) << "]" << endl << endl;
			}
			else {
				cout << endl << "Podana wartosc nie wystepuje w liscie" << endl << endl;
			}
			break;
		}
		case 't': {
			system("cls");
			mt.testyLista();
			break;
		}
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}
// menu dla tablicy
void MenuStruktur::menuTablica() {
	MenuTesty mt = *(new MenuTesty());
	bool koniec = false;
	Tablica tab = *(new Tablica());
	while (!koniec) {
		char wybor;
		cout << " MENU Tablicy " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Wczytaj dane z pliku" << endl;
		cout << "2.  Dodaj element na poczatku" << endl;
		cout << "3.  Dodaj element na koncu" << endl;
		cout << "4.  Dodaj element gdziekolwiek " << endl;
		cout << "5.  Usun element na poczatku" << endl;
		cout << "6.  Usun element na koncu" << endl;
		cout << "7.  Usun element gdziekolwiek " << endl;
		cout << "8.  Wyswietl tablice " << endl;
		cout << "9.  Wyszukaj element " << endl;
		cout << "a.  Automatyczne generowanie tablicy" << endl;
		cout << "t.  Testowanie" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1': {
			system("cls");
			cout << endl;
			string name;
			cout << "Podaj nazwe pliku bez rozszerzenia(.txt): ";
			cin >> name;
			if (tab.fileRead(name)) {
				cout << endl << "Pomyslnie wczytano dane z pliku: " << name << ".txt" << endl << endl;
			}
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			tab.addHead(value);
			cout << endl << "Elemnt zostal dodany na poczatek tablicy" << endl << endl;
			break;
		}
		case '3': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			tab.addTail(value);
			cout << endl << "Elemnt zostal dodany na koniec tablicy" << endl << endl;
			break;
		}
		case '4': {
			system("cls");
			int value, position;
			cout << endl << "Podaj wartosc nowego elementu: ";
			cin >> value;
			cout << endl << "Podaj numer indeksu gdzie ma byc nowa wartosc : ";
			cin >> position;
			if (tab.addIndex(value, position)) {
				cout << endl << "Elemnt zostal dodany pod indeksem [" << position << "]" << endl << endl;
			}
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			if (tab.deleteHead()) {
				cout << endl << "Usunieto element z poczatku tablicy" << endl << endl;
			}
			break;
		}
		case '6': {
			system("cls");
			cout << endl;
			if (tab.deleteTail()) {
				cout << endl << "Usunieto element z konca tablicy" << endl << endl;
			}
			break;
		}
		case '7': {
			system("cls");
			cout << endl;
			int position;
			if (tab.isEmpty()) {
				cout << "Tablica pusta" << endl << endl;
				break;
			}
			cout << "Podaj numer indeksu gdzie ma byc usuniety element: ";
			cin >> position;
			if (tab.deleteIndex(position)) {
				cout << endl << "Elemnt zostal usuniety z indexu [" << position << "]" << endl << endl;
			}
			break;
		}
		case '8': {
			system("cls");
			cout << endl;
			tab.displayArray();
			cout << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}
		case 'a': {
			system("cls");
			cout << endl;
			int number, low, high;
			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			tab.createRandom(number, low, high);
			cout << endl << "Wylosowano [" << number << "] elementow" << endl << endl;
			break;
		}
		case '9': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj poszukiwana wartosc: ";
			cin >> value;
			if (tab.searchValue(value) != -1) {
				cout << endl << "Numer indeksu elementu o wartosci:" << value << " to: [" << tab.searchValue(value) << "]" << endl << endl;
			}
			else {
				cout << endl << "Podana wartosc nie wystepuje w tablicy" << endl << endl;
			}
			break;
		}
		case 't': {
			system("cls");
			mt.testyTablica();
			break;
		}
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}

//menu dla kopca
void MenuStruktur::menuKopiec() {
	MenuTesty mt = *(new MenuTesty());
	bool koniec = false;
	Kopiec kop = *(new Kopiec());
	while (!koniec) {
		char wybor;
		cout << " MENU KOPCA " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Wczytaj dane z pliku" << endl;
		cout << "2.  Dodaj element do kopca" << endl;
		cout << "3.  Usun korzen kopca " << endl;
		cout << "4.  Wyswietl kopiec " << endl;
		cout << "5.  Wyszukaj element " << endl;
		cout << "a.  Automatyczne generowanie kopca" << endl;
		cout << "t.  Testowanie" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1': {
			system("cls");
			cout << endl;
			string name;
			cout << "Podaj nazwe pliku bez rozszerzenia(.txt): ";
			cin >> name;
			if (kop.fileRead(name)) {
				cout << endl << "Pomyslnie wczytano do kopca dane z pliku: " << name << ".txt" << endl << endl;
			}
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			kop.add(value);
			cout << endl << "Element zostal dodany do kopca" << endl << endl;
			break;
		}
		case '3': {
			system("cls");
			cout << endl;
			if (kop.remove()) {
				cout << endl << "Korzen kopca zostal usuniety" << endl << endl;
			}
			break;
		}
		case '4': {
			system("cls");
			cout << endl;
			kop.draw("", "", 0);
			cout << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}
		case 'a': {
			system("cls");
			cout << endl;
			int number, low, high;
			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			kop.createRandom(number, low, high);
			cout << endl << "Wylosowano [" << number << "] elementow do kopca" << endl << endl;
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj poszukiwana wartosc: ";
			cin >> value;
			if (kop.searchValue(value) != -1) {
				cout << endl << "Numer indeksu elementu o wartosci:" << value << " to: [" << kop.searchValue(value) << "]" << endl << endl;
			}
			else {
				cout << endl << "Podana wartosc nie wystepuje w kopcu" << endl << endl;
			}
			break;
		}
		case 't': {
			system("cls");
			mt.testyKopiec();
			break;
		}
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}

//menu dla Drzewa czerwono czarnego
void MenuStruktur::menuCzerwonoCzarne() {
	MenuTesty mt = *(new MenuTesty());
	bool koniec = false;
	CzerwonoCzarne* rb;
	rb = new CzerwonoCzarne;
	while (!koniec) {
		char wybor;
		cout << " MENU DRZEWA CZERWONO-CZARNEGO " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Wczytaj dane z pliku" << endl;
		cout << "2.  Dodaj element do drzewa" << endl;
		cout << "3.  Usun Wezel " << endl;
		cout << "4.  Wyswietl drzewo " << endl;
		cout << "5.  Wyszukaj element " << endl;
		cout << "a.  Automatyczne generowanie drzewa" << endl;
		cout << "t.  Testowanie" << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1': {
			system("cls");
			cout << endl;
			string name;
			cout << "Podaj nazwe pliku bez rozszerzenia(.txt): ";
			cin >> name;
			if (rb->fileRead(name)) {
				cout << endl << "Pomyslnie wczytano do drzewa dane z pliku: " << name << ".txt" << endl << endl;
			}
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> value;
			rb->add(value);
			cout << endl << "Element zostal dodany do drzewa" << endl << endl;
			break;
		}
		case '3': {
			system("cls");
			cout << endl;
			int value;
			if (rb->isEmpty()) {
				cout << "Drzewo puste" << endl << endl;
				break;
			}
			cout << "Podaj wartosc wezla do usuniecia: ";
			cin >> value;
			if (rb->remove(value)) {
				cout << endl << "Wezel zostal usuniety" << endl << endl;
			}
			break;
		}
		case '4': {
			system("cls");
			cout << endl;
			rb->draw2();
			cout << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}
		case 'a': {
			system("cls");
			cout << endl;
			int number;
			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			rb->createRandom(number);
			cout << endl << "Wylosowano [" << number << "] elementow do drzewa" << endl << endl;
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			int value;
			cout << "Podaj poszukiwana wartosc: ";
			cin >> value;
			if (rb->search(value) != 'q') {
				cout << endl << "Kolor wezla o wartosci: " << value << " to: " << rb->search(value) << endl << endl;
			}
			else {
				cout << endl << "Podana wartosc nie wystepuje w drzewie" << endl << endl;
			}
			break;
		}
		case 't': {
			system("cls");
			mt.testyCzerwonoCzarne();
			break;
		}
		default: {
			system("cls");
			cout << endl << "POMYLKA!" << endl << endl;
			break;
		}
		}
	}
}