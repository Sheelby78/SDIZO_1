#pragma once
using namespace std;

//Struktura dla pojedynczego elemntu drzewa
//Przechowuje wartosc elementu, kolor
//wskaznik na rodzica, lewego i prawego syna
struct Node {
	int data;
	char color;
	Node* parent;
	Node* left;
	Node* right;
};

class CzerwonoCzarne {
private:

	Node* root,S;

	Node* successor(Node* x);
	Node* min(Node* x);

public:

	CzerwonoCzarne();

	~CzerwonoCzarne();

	void add(int key);

	bool remove(int key);

	void leftRotate(Node* x);

	void rightRotate(Node* x);

	void rekDelete(Node* x);

	void draw(string sp, string sn, Node* pow);

	void draw2();

	bool fileRead(string name);

	char search(int value);

	void createRandom(int number);

	bool isEmpty();

};