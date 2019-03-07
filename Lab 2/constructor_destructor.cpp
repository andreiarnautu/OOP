/**
  *  Worg
  */
#include <iostream>

class Vector {
  int length, capacity;
  int *p;

public:

  //  constructor
  Vector() {
    std::cout << "constructor\n";
    this->p = new int[10];
    this->length = 0;
    this->capacity = 10;
  }

  Vector(int _initial_capacity, int _length = 0) {
    std::cout << "constructor #2\n";
    this->p = new int[_initial_capacity];
    this->length = length;
    this->capacity = _initial_capacity;
  }

  //  destructor
  ~Vector() {
    std::cout << "destructor\n";
    delete[] p;
  }

  int GetSize() {
    return length;
  }


};

int main() {
  Vector v1;
  {
    Vector v;
  }

  {
    Vector v2;
  }

  bool test_0 = false;
  if (test_0) {
    Vector *p = new Vector[100];
    delete[] p;
  }

  bool test_1 = true;
  if (test_1) {
    Vector v(1);
    Vector v2 = Vector(2, 0);
  }

  bool test_2 = true;
  if (test_2) {
    Vector *v3 = new Vector(2, 1);
    delete v3;
  }

  bool test_3 = true;
  if (test_3) {
    Vector *v4 = new Vector[100]{Vector(), Vector(1, 1), Vector(2, 2)};
  }
  return 0;
}