#include <iostream>
#include "Kopiec.h"
#include <fstream>

using namespace std;

//konstruktor
Kopiec::Kopiec() {

	Kopiec::array = nullptr;
	Kopiec::size = 0;
}

//destruktor
Kopiec::~Kopiec() {

	if (Kopiec::size > 0) {
		delete[]array;
	}
}

//dodawanie elemntu do kopca
void Kopiec::add(int value) {

    //przepisywanie tablicy do nowej
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}

    temp[size] = value;
	delete[]array;
	array = temp;

    //wywolanie funkcji naprawczej
    heapifyUp(size);
    size++;
    
}

//usuwanie lementu z tablicy 
bool Kopiec::remove() {

    if (size == 0) {
        cout << "Kopiec pusty" << endl <<endl;
        return false;
    }

    if (size == 1) {
        int* temp = new int[size - 1];
        delete[]array;
        array = temp;
        size--;
        return true;
    }


    int* temp = new int[size - 1];
    temp[0] = array[size - 1];

    //przepisywanie tablicy do nowej
    for (int i = 1; i < size-1; i++) {
        temp[i] = array[i];
    }

    delete[]array;
    array = temp;
    size--;

    //wywolanie funkcji naprawczej
    heapifyDown(0);
    return true;
}

//automatyczne tworzenie kopca
void Kopiec::createRandom(int number, int low, int high) {

    int value;

    for (int i = 0; i < number; i++) {
        value = (low + rand() % (high - low + 1));
        add(value);
    }
}

//funkcja naprawcza dla dodawania
void Kopiec::heapifyUp(int i) {

    int parent = (i - 1) / 2;

    if (parent >= 0) {

        if (array[i] > array[parent]) {
            swap(array[i] , array[parent]);
            heapifyUp(parent);
        }
    }
}

//funkcja naprawcza dla usuwania
void Kopiec::heapifyDown(int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(array[i], array[largest]);
        heapifyDown(largest);
    }
}

//czytanie danych z pliku
bool Kopiec::fileRead(string name) {

    string name3 = ".txt";
    ifstream odczyt(name + name3);

    if (!odczyt.good()) {
        cout <<endl<< "Blad odczytu pliku" << endl<<endl;
        return false;
    }
    int value, quantity;
    odczyt >> quantity;

    for (int i = 0; i < quantity; i++) {
        odczyt >> value;
        add(value);
    }
    odczyt.close();
    return true;
}

//rysowanie kopca
void Kopiec::draw(string x, string y, int poz) {

    string s,up,vertical,down;

    //Ustawianie znakow do rysowania galezi drzewa
    up = down = vertical = "  ";
    up[0] = 218; up[1] = 196;
    down[0] = 192; down[1] = 196;
    vertical[0] = 179;

    //rekurencyjne rysowanie kopca
    if (poz < size)
    {
        s = x;
        if (y == up) s[s.length() - 2] = ' ';
        draw(s + vertical, up, 2 * poz + 2);

        s = s.substr(0, x.length() - 2);

        cout << s << y << array[poz] << endl;

        s = x;
        if (y == down) s[s.length() - 2] = ' ';
        draw(s + vertical, down, 2 * poz + 1);
    }
}

//poszukiwanie klucza 
int Kopiec::searchValue(int value) {
   
    if (size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

