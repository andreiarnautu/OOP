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

  //  destructor
  ~Vector() {
    std::cout << "destructor\n";
    delete[] p;
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

  Vector *p = new Vector[100];
  delete[] p;
  return 0;
}