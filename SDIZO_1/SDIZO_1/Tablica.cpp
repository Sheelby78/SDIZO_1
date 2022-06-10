#include <iostream>
#include "Tablica.h"
#include <fstream>

using namespace std;

//konstruktor tablicy przypisujacy wskaznikowi pierwszego elementu tablicy wartosc null 
//oraz wielkosci tablicy wartosc 0
Tablica::Tablica() {
    Tablica::head = nullptr;
    Tablica::size = 0;

}

//destruktor tablicy usuwajacy powstala tablice
Tablica::~Tablica() {

    if (head != nullptr) {
        delete[]head;
    }
}

//dodawanie elementu na poczatek tablicy 
void Tablica::addHead(int value) {
    //tworzenie tablicy o 1 wiekszej od poprzedniej
    int* temp = new int[size + 1];
    temp[0] = value;
    //przepisanie elemntow tablicy do nowej
    for (int i = 0; i < size; i++) {
        temp[i + 1] = head[i];
    }
    delete head;
    head = temp;
    size++;
}

//dodawanie elemntu na koniec tablicy 
void Tablica::addTail(int value) {
    //tworzenie tablicy o 1 wiekszej od poprzedniej
    int* temp = new int[size + 1];
    temp[size] = value;
    //przepisanie elemntow tablicy do nowej
    for (int i = 0; i < size; i++) {
        temp[i] = head[i];
    }
    delete head;
    head = temp;
    size++;
}

//dodawanie elemntu w dowolnym miejscu tablicy
bool Tablica::addIndex(int value, int position) {
    if (position < 0 || position > size)
    {
        cout << endl << "Bledny index: [ " << position << " ]" << endl << endl;
        return false;
    }
    if (position == 0) {
        addHead(value);
        return true;
    }
    if (position == size) {
        addTail(value);
        return true;
    }
    //utworzenie nowej tablicy o 1 wiekszej
    int* temp = new int[size + 1];
    temp[position] = value;
    //piersza petla przepisujaca wartosci do momentu dodania nowego elemntu
    for (int i = 0; i < position; i++) {
        temp[i] = head[i];
    }
    //druga petla przepisujaca wartosci po dodaniu nowego elemntu
    for (int i = position; i < size; i++) {
        temp[i + 1] = head[i];
    }

    delete head;
    head = temp;
    size++;
    return true;
}

//usuwanie lelmtu z poczatku
bool Tablica::deleteHead() {
    if (size == 0) {
        cout << "Tablica pusta" << endl << endl;
        return false;
    }
    //utworzenie nowej tablicy o 1 mniejszej
    int* temp = new int[size - 1];
    //przepisanie elemntow tablicy do nowej
    for (int i = 0; i < size - 1; i++) {
        temp[i] = head[i+1];
    }
    delete[] head;
    head = temp;
    size--;
    return true;
}

//usuwanie elementu z konca
bool Tablica::deleteTail() {
    if (size == 0) {
        cout << "Tablica pusta" << endl << endl;
        return false;
    }
    //utworzenie nowej tablicy o 1 mniejszej
    int* temp = new int[size - 1];
    //przepisanie elemntow tablicy do nowej
    for (int i = 0; i < size - 1; i++) {
        temp[i] = head[i];
    }
    delete[] head;
    head = temp;
    size--;
    return true;
}

//usuwanie elemntu pod wskazanym indeksem
bool Tablica::deleteIndex(int position) {

    if (position < 0 || position > size)
    {
        cout << endl << "Bledny index: [ " << position << " ]" << endl << endl;
        return false;
    }
    if (position == 0) {
        deleteHead();
        return true;
    }
    if (position == size) {
        deleteTail();
        return true;
    }
    //utworzenie nowej tablicy o 1 mniejszej
    int* temp = new int[size - 1];

    //piersza petla przepisujaca wartosci do momentu dodania nowego elemntu
    for (int i = 0; i < position; i++) {
        temp[i] = head[i];
    }
    //druga petla przepisujaca wartosci po dodaniu nowego elemntu
    for (int i = position; i < size-1; i++) {
        temp[i] = head[i+1];
    }

    delete head;
    head = temp;
    size--;
    return true;
}

//wyswietlanie tablicy
void Tablica::displayArray() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] " << head[i] << " | ";
    }
}

//szukanie indeksu z podana wartoscia elemtu
int Tablica::searchValue(int value) {
    if (size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (head[i] == value) {
            return i;
        }
    }
    return -1;
}

//wczytywanie elemntow z pliku
bool Tablica::fileRead(string name) {

    string name3 = ".txt";
    ifstream odczyt(name + name3);

    if (!odczyt.good()) {
        cout << endl << "Blad odczytu pliku" << endl << endl;
        return false;
    }
    int value, quantity;
    odczyt >> quantity;

    for (int i = 0; i < quantity; i++) {
        odczyt >> value;
        addTail(value);
    }
    odczyt.close();
    return true;
}

//tworzenie losowej tablicy z zadanym rozmiarem dolna i gorna granica rozmiaru
void Tablica::createRandom(int number, int low, int high) {

    int value;

    for (int i = 0; i < number; i++) {
        value = (low + rand() % (high - low + 1));
        addTail(value);
    }
}

//sprawdzenie czy tablica jest pusta
bool Tablica::isEmpty() {
    if (size == 0) {
        return true;
    }
    return false;
}