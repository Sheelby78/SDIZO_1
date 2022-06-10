#pragma once
using namespace std;
class Kopiec {
private:
	int* array;
	int size;

public:
	Kopiec();

	~Kopiec();

	bool fileRead(string name);

	bool remove();

	void add(int value);

	int searchValue(int value);

	void draw(string sp, string sn, int v);

	void createRandom(int number, int low, int high);

	void heapifyUp(int key);

	void heapifyDown(int key);
};