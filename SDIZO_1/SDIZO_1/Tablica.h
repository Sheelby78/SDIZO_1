#pragma once
using namespace std;
class Tablica {
private:
	int* head;
	int size;

public:
    Tablica();

    ~Tablica();

    void addHead(int);

    void addTail(int value);

    bool addIndex(int value, int position);

    bool deleteHead();

    bool deleteTail();

    bool deleteIndex(int position);

    void displayArray();

    int searchValue(int value);

    bool fileRead(string name);

    void createRandom(int number, int low, int high);

    bool isEmpty();

};