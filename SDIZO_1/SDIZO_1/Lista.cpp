#include <iostream>
#include <fstream>
#include "Lista.h"

using namespace std;

//konstruktor listy
Lista::Lista() {

    Lista::head = NULL;
    Lista::tail = NULL;
    Lista::size = 0;

}

//destruktor listy
Lista::~Lista() {
	Node* temp = head;
	if (temp != nullptr && tail != nullptr)
		while (temp->next != nullptr)
		{
			head = temp;
			temp = temp->next;
			delete head;
		}
}

//Dodawanie elementu na poczatek listy
void Lista::addHead(int value) {

	if (size==0) {
		head = new Node(value);
		tail = head;
		size++;

	}
	else {
		Node* temp;
		temp = head;
		head = new Node(value);
		temp->prev = head;
		head->next = temp;
		size++;
	}
}

//Dodawanie elemntu na koniec listy
void Lista::addTail(int value) {
	if (size == 0) {
		addHead(value);
	}
	else {
		Node* temp;
		temp = tail;
		tail = new Node(value);
		temp->next = tail;
		tail->prev = temp;
		size++;
	}
}

//Dodawanie elementu pod wsazanym indeksem
bool Lista::addIndex(int value, int position) {
	if (position < 0 || position > size)
	{
		cout << endl << "Bledny index: [ " << position << " ]" << endl << endl;
		return false;
	}
	else if (position == 0)
		addHead(value);
	else if (position == size)
		addTail(value);
	else if (position > (size / 2))
	{
		Node* temp = tail;
		Node* newNode = new Node(value);
		for (int i = size; i > position + 1; i--)
			temp = temp->prev;

		newNode->prev = temp->prev;
		newNode->prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;
		size++;
	}
	else
	{
		Node* temp = head;
		Node* newNode = new Node(value);
		for (int i = 0; i < position - 1; i++)
			temp = temp->next;

		temp->next->prev = newNode;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		size++;
	}
	return true;
}

//usuwanie poczatkowego elementu listy
bool Lista::deleteHead() {
	if (size == 0) {
		cout << "Lista pusta" << endl << endl;
		return false;
	}
	Node* temp = head;
	head = head->next;
	delete temp;

	if (head != nullptr) {
		head->prev = nullptr;
	}

	size--;
	return true;
}

//usuwanie koncowego elemntu listy
bool Lista::deleteTail() {
	if (size == 0) {
		cout << "Lista pusta" << endl << endl;
		return false;
	}
	if (size == 1) {
		deleteHead();
		return true;
	}

	Node* temp = tail;
	tail = tail->prev;

	tail->next = nullptr;

	delete temp;
	size--;
	return true;
}

//usuwanie elementu listy o wskazanym indeksie
bool Lista::deleteIndex(int position) {
	if (size == 0) {
		cout <<endl<< "Lista pusta" << endl<<endl;
		return false;
	}
	if (position >= size || position < 0)
	{
		cout << endl << "Bledny index: [ " << position << " ]" << endl <<endl;
		return false;
	}
	else if (position == 0)
		deleteHead();
	else if (position == size - 1)
		deleteTail();
	else if (position >= (size / 2))
	{
		Node* temp = tail;
		Node* buf;

		for (int i = size - 1; i > position + 1; i--)
			temp = temp->prev;

		buf = temp->prev->prev;
		delete temp->prev;
		buf->next = temp;
		temp->prev = buf;

		size--;
	}
	else
	{
		Node* temp = head;
		Node* buf;

		for (int i = 0; i < position - 1; i++)
			temp = temp->next;

		buf = temp->next->next;
		delete temp->next;
		temp->next = buf;
		buf->prev = temp;

		size--;
		return true;
	}
	return true;
}

//wyszukiwanie inkeksu listy o wskazanej wartosci
int Lista::searchValue(int value) {
	if (size == 0) {
		return -1;
	}

	Node* temp = head;
	int i = 0;

	while (temp != nullptr)
	{
		if (temp->data == value) return i;
		temp = temp->next;
		i++;
	}
	return -1;
}

//wyswietlanie zawartosci listy
void Lista::displayList() {
	Node* temp = head;
	for (int i = 0; i < size;i++) {
		cout << "[" << i << "] " << temp->data << endl;
		temp = temp->next;
	}
}

//wczytywanie danych do listy z pliku tekstowego znajdujacego sie na pulpicie
bool Lista::fileRead(string name) {

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

void Lista::createRandom(int number, int low, int high) {

	int value;
	for (int i = 0; i < number; i++) {
		value = (low + rand() % (high - low + 1));
		addTail(value);
	}
}

//sprawdzenie czy lista jest pusta
bool Lista::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}
