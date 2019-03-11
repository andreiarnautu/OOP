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

  char& Sign();
  int Size() const;
  int& operator[](int index);
  int operator[](int index) const;

  void Fix();
  void ChangeSign();

  friend bool CompareIntegerParts(const BigInteger &A, const BigInteger &B);

  friend std::istream &operator >>(std::istream &i, BigInteger &integer);
  friend std::ostream &operator <<(std::ostream &o, BigInteger &integer);

  friend BigInteger AddAbsoluteValues(BigInteger A, BigInteger B);
  friend BigInteger SubtractAbsoluteValues(BigInteger A, BigInteger B);
  friend BigInteger operator +(BigInteger A, BigInteger const & B);
  friend BigInteger operator -(BigInteger A, BigInteger const & B);

  friend BigInteger operator *(BigInteger A, BigInteger const & B);

  friend BigInteger GetMaxAbsoluteValue(const BigInteger & A, const BigInteger & B);
};

#endif //OOP_BIG_INTEGERS_CLASS_H
