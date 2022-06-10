#include <iostream>
#include "Lista.h"
#include "Tablica.h"
#include "Kopiec.h"
#include "Timer.h"
#include "CzerwonoCzarne.h"
#include "MenuTesty.h"

using namespace std;

// testowanie tablicy
void MenuTesty::testyTablica() {
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE TABLICY " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Dodaj element na poczatku" << endl;
		cout << "2.  Dodaj element na koncu" << endl;
		cout << "3.  Dodaj element gdziekolwiek " << endl;
		cout << "4.  Usun element na poczatku" << endl;
		cout << "5.  Usun element na koncu" << endl;
		cout << "6.  Usun element gdziekolwiek " << endl;
		cout << "7.  Wyszukaj element " << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.addHead(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania na poczatku to: " << count / 100 << endl << endl;
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.addTail(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania na koncu to: " << count / 100 << endl << endl;
			break;
		}
		case '3': {

			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high, position;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));
			position = (number / 2) - 1;

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.addIndex(value, position);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania pod wskazanym indeksem to: " << count / 100 << endl << endl;
			break;
		}
		case '4': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.deleteHead();
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania na poczatku to: " << count / 100 << endl << endl;
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.deleteTail();
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania na koncu to: " << count / 100 << endl << endl;
			break;
		}
		case '6': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high, position;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			position = (number / 2) - 1;

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.deleteIndex(position);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania pod wskazanym indeksem to: " << count / 100 << endl << endl;
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		case '7': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high, value;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = high + 1;

			for (int i = 0; i < 100; i++) {
				Tablica tabliczka = *(new Tablica());
				tabliczka.createRandom(number, low, high);
				test.start();
				tabliczka.searchValue(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji poszukiwania elemntu to: " << count / 100 << endl << endl;
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

// testowanie listy
void MenuTesty::testyLista() {
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE LISTY " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Dodaj element na poczatku" << endl;
		cout << "2.  Dodaj element na koncu" << endl;
		cout << "3.  Dodaj element gdziekolwiek " << endl;
		cout << "4.  Usun element na poczatku" << endl;
		cout << "5.  Usun element na koncu" << endl;
		cout << "6.  Usun element gdziekolwiek " << endl;
		cout << "7.  Wyszukaj element " << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.addHead(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania na poczatku to: " << count / 100 << endl << endl;
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.addTail(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania na koncu to: " << count / 100 << endl << endl;
			break;
		}
		case '3': {

			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high, position;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));
			position = (number / 2) - 1;

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.addIndex(value, position);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania pod wskazanym indeksem to: " << count / 100 << endl << endl;
			break;
		}
		case '4': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.deleteHead();
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania na poczatku to: " << count / 100 << endl << endl;
			break;
		}
		case '5': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.deleteTail();
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania na koncu to: " << count / 100 << endl << endl;
			break;
		}
		case '6': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high, position;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			position = (number / 2) - 1;

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.deleteIndex(position);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania pod wskazanym indeksem to: " << count / 100 << endl << endl;
			break;
		}

		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		case '7': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high, value;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = high + 1;

			for (int i = 0; i < 100; i++) {
				Lista li = *(new Lista());
				li.createRandom(number, low, high);
				test.start();
				li.searchValue(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji poszukiwania elemntu to: " << count / 100 << endl << endl;
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

// testowanie Kopca
void MenuTesty::testyKopiec() {
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE KOPCA " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Dodaj element do kopca" << endl;
		cout << "2.  Usun korzen kopca " << endl;
		cout << "3.  Wyszukaj element " << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = (low + rand() % (high - low + 1));

			for (int i = 0; i < 100; i++) {
				Kopiec ko = *(new Kopiec());
				ko.createRandom(number, low, high);
				test.start();
				ko.add(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania to: " << count / 100 << endl << endl;
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;

			for (int i = 0; i < 100; i++) {
				Kopiec ko = *(new Kopiec());
				ko.createRandom(number, low, high);
				test.start();
				ko.remove();
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania korzenia to: " << count / 100 << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		case '3': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, low, high, value;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			cout << endl << "Podaj dolna granice losowania: ";
			cin >> low;
			cout << endl << "Podaj gorna granice losowania: ";
			cin >> high;
			value = high + 1;

			for (int i = 0; i < 100; i++) {
				Kopiec ko = *(new Kopiec());
				ko.createRandom(number, low, high);
				test.start();
				ko.searchValue(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji poszukiwania elementu to: " << count / 100 << endl << endl;
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

// testowanie Drzewa czerwono czarnego
void MenuTesty::testyCzerwonoCzarne() {
	bool koniec = false;
	Timer test = *(new Timer());
	while (!koniec) {
		char wybor;
		cout << " TESTOWANIE DRZEWA CZERWONO CZARNEGO " << endl;
		cout << "---------------------------" << endl;
		cout << "1.  Dodaj element do drzewa" << endl;
		cout << "2.  Usun wezel drzewa " << endl;
		cout << "3.  Wyszukaj element " << endl;
		cout << "x.  Powrot" << endl;
		cout << "---------------------------" << endl;
		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{

		case '1': {
			system("cls");
			cout << endl;
			long count = 0;
			int value, number;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			value = (rand() % number);

			for (int i = 0; i < 100; i++) {
				CzerwonoCzarne* rbb = new CzerwonoCzarne;
				rbb->createRandom(number);
				test.start();
				rbb->add(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji dodawania to: " << count / 100 << endl << endl;
			break;
		}
		case '2': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, value;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			value = (rand() % number);

			for (int i = 0; i < 100; i++) {
				CzerwonoCzarne* rbb = new CzerwonoCzarne;
				rbb->createRandom(number);
				test.start();
				rbb->remove(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji usuwania to: " << count / 100 << endl << endl;
			break;
		}
		case 'x': {
			system("cls");
			koniec = true;
			break;
		}

		case '3': {
			system("cls");
			cout << endl;
			long count = 0;
			int number, value;

			cout << "Podaj ilosc elementow do wylosowania: ";
			cin >> number;
			value = (rand() % number);

			for (int i = 0; i < 100; i++) {
				CzerwonoCzarne* rbb = new CzerwonoCzarne;
				rbb->createRandom(number);
				test.start();
				rbb->search(value);
				test.stop();
				count += test.timeCount();
			}

			cout << endl << "Sredni czas wykonania operacji poszukiwania elementu to: " << count / 100 << endl << endl;
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