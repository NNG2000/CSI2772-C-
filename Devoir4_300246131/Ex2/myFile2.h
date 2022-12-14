#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};

SetInt::~SetInt() {
    delete this->elem;
    this->size = 0;
}
SetInt::SetInt(int newelem[], int taille) {
    this->size = 0;
    this->elem = NULL;
    for (int i = 1; i <= taille; i++) {
        add(newelem[i]);
    }
}
SetInt::SetInt(const SetInt& copyElem) {  // copy constructor
    this->size = 0 ;
    this->elem = NULL;
    for (int i = 1; i <= copyElem.size; i++) {
        add(copyElem.elem[i]);
    }
}

void SetInt::add(int n) { //SetInt(const SetInt & this->elem);
    if (contains(n) == true) {
        return;
    }
    int* temporalElem = (int*)realloc(elem, (size + 1) * sizeof(int));
    elem = new int(size + 1);
    elem = temporalElem;
    *(elem + size) = n;
    size++;
}
void SetInt::remove(int n) {
    if (contains(n) == true && this->size == 1) {
        size = 0;
        delete[] elem;
        elem = NULL;
    }
    else if (contains(n) == true && this->size > 1) {
        SetInt temporalElem;
        int i = 0;
        bool replace = false;
        while (i < size) {
            if (*(elem + i) == n) {
                *(elem + i) = *(elem + i + 1);
                replace = true;
            }
            else if (replace) {
                *(elem + i) = *(elem + i + 1);
            }
            i++;
        }
        size--;
    }
}
bool SetInt::contains(int n) {
    for (int i = 0; i < size; i++) {
        if (*(elem + i) == n)
            return true;
        else
            return false;
    }
}
int SetInt::nbElem() {
    return size;
}
int* SetInt::tabElem() {
    if (this->elem == NULL) {
        return NULL;
    }
    else {
        return this->elem;
    }
}
bool SetInt::containsIn(int n, int& pos) {
    if (n == *(this->elem) + pos)
        return true;
    else
        return false;
}
