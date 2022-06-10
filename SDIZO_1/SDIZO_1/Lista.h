#pragma once
using namespace std;
#include <cstdlib>
#include <ctime>
class Lista
{
private:
	//Struktura dla pojedynczego elemntu listy
	//Przechowuje wartosc elementu
	//Oraz wskaznik na elemnt nastepny i poprzedni
	struct Node {
		Node* next;
		int data;
		Node* prev;

		Node(int value)
		{
			this->data = value;
			next = nullptr;
			prev = nullptr;
		}
	};

	Node* head, * tail;
	int size;

public:
	Lista();

	~Lista();

	void addHead(int value);

	bool addIndex(int value, int position);

	void addTail(int value);

	bool deleteHead();

	bool deleteTail();

	bool deleteIndex(int position);

	void displayList();

	int searchValue(int value);

	bool fileRead(string name);

	void createRandom(int number, int low, int high);

	bool isEmpty();
};