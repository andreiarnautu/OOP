/**
  *  Worg
  */
#include <iostream>
#include "vector_class.h"

#ifndef OOP_BIG_INTEGERS_CLASS_H
#define OOP_BIG_INTEGERS_CLASS_H


class BigInteger {
private:
  Vector<int > digits;
  char sign;

public:
  BigInteger() : sign('+') {}
//  ~BigInteger() {
//    digits.~Vector();
//  }

  char& Sign();
  int Size() const;
  int& operator[](int index);
  int operator[](int index) const;
  friend BigInteger operator +(BigInteger A, BigInteger const & B);
  friend std::istream &operator >>(std::istream &i, BigInteger &integer);
  friend std::ostream &operator <<(std::ostream &o, BigInteger &integer);
};

#endif //OOP_BIG_INTEGERS_CLASS_H
