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

  BigInteger(int value) {
    *this = value;
  }

  BigInteger(const BigInteger &A) {
    this->sign = A.sign;
    this->digits = A.digits;
  }

  char& Sign();
  int Size() const; // ok
  int& operator[](int index);  //  ok
  int operator[](int index) const;  //  ok

  BigInteger& operator =(int value);  //  ok
  BigInteger& operator =(BigInteger A);  //  ok

  bool operator ==(const BigInteger &A);  //  ok

  bool IsNull();  //  ok
  void Fix();  //  ok
  void ChangeSign();  //  ok

  friend bool CompareIntegerParts(const BigInteger &A, const BigInteger &B);  //  ok

  friend std::istream &operator >>(std::istream &i, BigInteger &integer);  //ok
  friend std::ostream &operator <<(std::ostream &o, BigInteger &integer);  //ok

  friend BigInteger AddAbsoluteValues(BigInteger A, BigInteger B);  //  ok
  friend BigInteger SubtractAbsoluteValues(BigInteger A, BigInteger B);  //  ok
  friend BigInteger operator +(BigInteger A, BigInteger const & B);  //  ok
  friend BigInteger operator -(BigInteger A, BigInteger const & B);  //  ok

  friend BigInteger operator *(BigInteger A, BigInteger const & B);  //  ok

  friend BigInteger GetMaxAbsoluteValue(const BigInteger & A, const BigInteger & B);

  friend BigInteger operator /(BigInteger A, BigInteger const & B);  //  ok
  friend BigInteger operator %(BigInteger A, BigInteger const & B);  //  ok

  friend BigInteger Sqrt(BigInteger A);
};

#endif //OOP_BIG_INTEGERS_CLASS_H
