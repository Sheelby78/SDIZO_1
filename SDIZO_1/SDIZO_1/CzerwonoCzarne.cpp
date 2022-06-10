#include <iostream>
#include "CzerwonoCzarne.h"
#include <fstream>

using namespace std;

//konstruktor
CzerwonoCzarne::CzerwonoCzarne() {
    S.color = 'B';
    root = &S;
}

//destruktor
CzerwonoCzarne::~CzerwonoCzarne() {
    rekDelete(root);
}


//rekurencyjne usuwanie drzewa
void CzerwonoCzarne::rekDelete(Node* temp){
	
    if (temp != &S)
    {
        if (temp->left != &S) {
            rekDelete(temp->left);
        }

        if (temp->right != &S) {
            rekDelete(temp->right);
        }

        delete temp;
    }

}

//lewa rotacja
void CzerwonoCzarne::leftRotate(Node* x)
{
    Node* temp, * temp2;

    temp = x->right;
    if (temp != &S)
    {
        temp2 = x->parent;
        x->right = temp->left;
        if (x->right != &S) x->right->parent = x;

        temp->left = x;
        temp->parent = temp2;
        x->parent = temp;

        if (temp2 != &S)
        {
            if (temp2->left == x) temp2->left = temp; else temp2->right = temp;
        }
        else root = temp;
    }
}


//prawa rotacja 
void CzerwonoCzarne::rightRotate(Node* x)
{
    Node* temp, * temp2;

    temp = x->left;
    if (temp != &S)
    {
        temp2 = x->parent;
        x->left = temp->right;
        if (x->left != &S) x->left->parent = x;

        temp->right = x;
        temp->parent = temp2;
        x->parent = temp;

        if (temp2 != &S)
        {
            if (temp2->left == x) temp2->left = temp; else temp2->right = temp;
        }
        else root = temp;
    }
}


//dodawanie elemntu do drzewa
void CzerwonoCzarne::add(int k) {

    //utworzenie nowego elemntu drzewa
    Node* temp, * temp2;
    temp = new Node;
    temp->left = &S;
    temp->right = &S;
    temp->parent = root;
    temp->data = k;

    if (temp->parent == &S) {
        root = temp;
    }
    else {
        while (true){
            if (k < temp->parent->data){
                if (temp->parent->left == &S){
                    temp->parent->left = temp;
                    break;
                }
                temp->parent = temp->parent->left;
            }
            else{
                if (temp->parent->right == &S){
                    temp->parent->right = temp;
                    break;
                }
                temp->parent = temp->parent->right;
            }
        }
    }
    temp->color = 'R'; 

    while ((temp != root) && (temp->parent->color == 'R')){
        if (temp->parent == temp->parent->parent->left){
            temp2 = temp->parent->parent->right;

            if (temp2->color == 'R'){ // Przypadek 1

                temp->parent->color = 'B';
                temp2->color = 'B';
                temp->parent->parent->color = 'R';
                temp = temp->parent->parent;
                continue;
            }

            if (temp == temp->parent->right){ // Przypadek 2

                temp = temp->parent;
                leftRotate(temp);
            }

            temp->parent->color = 'B'; // Przypadek 3
            temp->parent->parent->color = 'R';
            rightRotate(temp->parent->parent);
            break;
        }
        else{  // Przypadki lustrzane
            temp2 = temp->parent->parent->left;

            if (temp2->color == 'R'){ // Przypadek 1

                temp->parent->color = 'B';
                temp2->color = 'B';
                temp->parent->parent->color = 'R';
                temp = temp->parent->parent;
                continue;
            }

            if (temp == temp->parent->left){ // Przypadek 2

                temp = temp->parent;
                rightRotate(temp);
            }

            temp->parent->color = 'B'; // Przypadek 3
            temp->parent->parent->color = 'R';
            leftRotate(temp->parent->parent);
            break;
        }
    }
    root->color = 'B';
}

Node* CzerwonoCzarne::successor(Node* x)
{// wyszukanie nastepnika podanego elemntu 
    Node* r;

    if (x != &S)
    {
        if (x->right != &S) return min(x->right);
        else
        {
            r = x->parent;
            while ((r != &S) && (x == r->right))
            {
                x = r;
                r = r->parent;
            }
            return r;
        }
    }
    return &S;
}

Node* CzerwonoCzarne::min(Node* x){
    //wyszukanie najmniejszego elementu od podanego 
    if (x != &S)
        while (x->left != &S) x = x->left;
    return x;
}

bool CzerwonoCzarne::remove(int key){

    Node* temp, * temp2, * temp3, * temp4;
    temp = root;

    if (temp == &S) {
        cout << endl << "Drzewo Puste" << endl << endl;
        return false;
    }

    //Wyszukanie wskaznika na dana wartosc w drzewie
    while ((temp != &S) && (temp->data != key))
        if (key < temp->data) {
            temp = temp->left; 
        }
        else { 
            temp = temp->right; 
        }

    if (temp == &S) {
        cout << endl << "Brak wezla o podanej wartosci" << endl << endl;
        return false;
    }

    if ((temp->left == &S) || (temp->right == &S)) {
        temp2 = temp;
    }
    else {
        temp2 = successor(temp);
    }

    if (temp2->left != &S) {
        temp3 = temp2->left;
    }
    else {
        temp3 = temp2->right;
    }

    temp3->parent = temp2->parent;

    if (temp2->parent == &S) {
        root = temp3;
    }
    else if (temp2 == temp2->parent->left) {
        temp2->parent->left = temp3;
    }
    else {
        temp2->parent->right = temp3;
    }

    if (temp2 != temp) {
        temp->data = temp2->data;
    }

    //Odbudowa drzewa
    if (temp2->color == 'B')
        while ((temp3 != root) && (temp3->color == 'B'))
            if (temp3 == temp3->parent->left)
            {
                temp4 = temp3->parent->right;

                if (temp4->color == 'R'){ // Przypadek 1
                    temp4->color = 'B';
                    temp3->parent->color = 'R';
                    leftRotate(temp3->parent);
                    temp4 = temp3->parent->right;
                }

                if ((temp4->left->color == 'B') && (temp4->right->color == 'B')){ // Przypadek 2
                    temp4->color = 'R';
                    temp3 = temp3->parent;
                    continue;
                }

                if (temp4->right->color == 'B'){ // Przypadek 3
                    temp4->left->color = 'B';
                    temp4->color = 'R';
                    rightRotate(temp4);
                    temp4 = temp3->parent->right;
                }

                temp4->color = temp3->parent->color; // Przypadek 4
                temp3->parent->color = 'B';
                temp4->right->color = 'B';
                leftRotate(temp3->parent);
                temp3 = root;
            }
            else{ // Przypadki lustrzane
                temp4 = temp3->parent->left;

                if (temp4->color == 'R'){ // Przypadek 1
                    temp4->color = 'B';
                    temp3->parent->color = 'R';
                    rightRotate(temp3->parent);
                    temp4 = temp3->parent->left;
                }

                if ((temp4->left->color == 'B') && (temp4->right->color == 'B')){  // Przypadek 2
                    temp4->color = 'R';
                    temp3 = temp3->parent;
                    continue;
                }

                if (temp4->left->color == 'B'){  // Przypadek 3            
                    temp4->right->color = 'B';
                    temp4->color = 'R';
                    leftRotate(temp4);
                    temp4 = temp3->parent->left;
                }

                temp4->color = temp3->parent->color;  // Przypadek 4
                temp3->parent->color = 'B';
                temp4->left->color = 'B';
                rightRotate(temp3->parent);
                temp3 = root;     
            }

    temp3->color = 'B';

    delete temp2;
    return true;
}

void CzerwonoCzarne::draw(string x, string y, Node* poz) {
    string s, up, vertical, down;

    //Ustawianie znakow do rysowania galezi drzewa
    up = down = vertical = "  ";
    up[0] = 218; up[1] = 196;
    down[0] = 192; down[1] = 196;
    vertical = "  | ";

    //rekurencyjne rysowanie kopca
    if (poz !=&S)
    {
        s = x;
        if (y == up) s[s.length() - 2] = ' ';
        draw(s + vertical, up, poz->right);

        s = s.substr(0, x.length() - 2);

        cout << s << y << poz->data<<":"<< poz->color << endl;

        s = x;
        if (y == down) s[s.length() - 2] = ' ';
        draw(s + vertical, down, poz->left);
    }
}

void CzerwonoCzarne::draw2() {
    //wywolanie rekurencyjnego rysowania drzewa
    draw("", "", root);
}


//odczyt danych z pliku do drzewa
bool CzerwonoCzarne::fileRead(string name) {

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
        add(value);
    }
    odczyt.close();
    return true;
}

//wyszukiwanie wartosci w drzewie
char CzerwonoCzarne::search(int value) {

    Node* temp;
    temp = root;

    while ((temp != &S) && (temp->data != value))
        if (value < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    if (temp == &S) {
        return 'q';
    }
    return temp->color;
}

//Automatyczne generowanie drzewa 
void CzerwonoCzarne::createRandom(int number) {
    int T[20000] = {};
    int temp1, temp2;

    for (int i=0; i < number; i++) {
        T[i] = i + 1;
    }

    for (int i = 0; i < number; i++)
    {
        temp1 = rand() % number;
        temp2 = rand() % number;
        swap(T[temp1],T[temp2]);
    }

    for (int i = 0; i < number; i++) {
        add(T[i]);
    }
}

//sprawdzenie czy drzewo jest pusty
bool CzerwonoCzarne::isEmpty() {
    if (root == &S) {
        return true;
    }
    return false;
}