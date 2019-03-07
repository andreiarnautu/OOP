#include <iostream>

class Vector {
private:
  int  *p;
  int length, capacity;

public:
  Vector() {
    length = 10; capacity = 10; p = new int[10];
    for (int i = 0; i < 10; i++) {
      p[i] = i;
    }
    std::cout << "constructor 1\n";
  }

  ~Vector() {
    delete[] p;
  }

  Vector(const Vector &v2) {
    this->length = v2.length; this->capacity = v2.capacity;
    this->p = new int[this->capacity];

    for (int i = 0; i < this->length; i++) {
      p[i] = v2.p[i];
    }
    std::cout << "constructor 2\n";
  }

  Vector(int capacity_p, int length_p) : capacity(capacity_p), length(length_p), p(new int[capacity_p]) {
    for (int i = 0; i < length; i++) {
      p[i] = -i;
    }
    std::cout << "constructor 3\n";
  }

  int Get(int position) {
    return p[position];
  }

  const Vector& operator =(const Vector &v2) {
    if (this == &v2) return *this;
    this->length = v2.length; this->capacity = v2.capacity;

    delete[] p;

    this->p = new int[this->capacity];

    for (int i = 0; i < length; i++) {
      p[i] = v2.p[i];
    }
    std::cout << "operator =\n";

    return *this;
  }
};


void F(Vector v) {  // -> se apeleaza constructorul de copiere

}


Vector g() {
  Vector v;
  return v;  //  -> se apeleaza constructorul de copiere
}


int main() {
  Vector v;
  Vector v2();
  Vector *v3 = new Vector();

  F(Vector());
  Vector v4 = Vector();
  //Vector v5(v4);  //  -> se apeleaza constructorul de copiere

  //Vector v6 = v4;  //  -> se apeleaza constructorul de copiere
  Vector v7 = g();
  //std::cout << v7.Get(3);
  Vector v8;
  v8 = g();  //  da eroare, fiindca acceseaza operatorul =, care este cel by default care copiaza bit cu bit
  Vector v9;
  v9 = v8 = v7;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}