/**
  *  This file contains all the functions implemented for the BigInteger class.
  *  add_executable("Lab 2" constructor_destructor.cpp)
  */
#include <iostream>
#include "big_integers_class.h"

/*
 *  TODO:
 *    -> the sum of 2 big integers (by overloading the operator '+')
 *    -> the difference of 2 big integers (by overloading the operator '-')
 *    -> the product of 2 big integers (by overloading the operator '*')
 *    -> the maximum between the absolute values of 2 big integers
 *    -> compute the quotient when dividing 2 big integers (by overloading the operator '/') -> returns BigInteger
 *    -> compute the remainder of the division of 2 big integers (by overloading operator '%'); check for division by Zero
 *    -> compute the integer part of the square root of a big integer's integer part -> returns BigInteger
 */

char& BigInteger::Sign() {
  return sign;
}


int BigInteger::Size() const{
  return digits.Size();
}


int& BigInteger::operator[](int index) {
  return digits[index];
}

int BigInteger::operator[](int index) const {
  return digits[index];
}


void Swap(int& a, int& b) {
  int c = a;
  a = b; b = c;
}


std::istream &operator>>(std::istream &i, BigInteger &integer) {
  char c;
  bool found_number = false;

  integer.digits.Reset();
  integer.sign = '+';

  while (!i.eof()) {
    i.get(c);

    if (c < '0' || c > '9') {
      if (found_number) {
        break;
      } else if (c == '-') {
        integer.sign = c;
      }
    } else {
      c -= '0';
      integer.digits.PushBack((int)c);
      found_number = true;
    }
  }

  //  We want to reverse the order of digits, such that the least significant one is placed first.
  for (int j = 1, k = integer.digits.Size(); j <= k; j++, k--) {
    Swap(integer[j], integer[k]);
  }

  return i;
}


std::ostream &operator<<(std::ostream &o, BigInteger &integer) {
  if (integer.Sign() == '-') {
    o <<'-';
  }
  for (int i = integer.Size(); i >= 1; i--) {
    o << integer[i];
  }

  //  A number with virtually no size is equal to zero.
  if (integer.Size() == 0) {
    o << "0";
  }

  return o;
}

BigInteger operator +(BigInteger A, const BigInteger &B) {
  BigInteger result;
  int t = 0;

  for (int i = 1; i <= A.Size() || i <= B.Size() || t > 0; i++, t /= 10) {
    if (i <= A.Size()) {
      t += A.digits[i];
    }
    if (i <= B.Size()) {
      t += B.digits[i];
    }

    std::cout << "Am ajuns la litera " << i << '\n';

    result.digits.SetSize(i);
    result.digits[i] = t % 10;
  }
  std::cout << "Am ajuns aici\n";
  std::cout << result << '\n';
  return result;
}
//
//BigInteger BigInteger::operator +(BigInteger a) {
//  BigInteger result;
//  int t = 0;
//  for (int i = 1; i <= this->Size() || i <= a.Size() || t != 0; i++, t /= 10) {
//    t += this->digits[i] + a[i];
//    this->digits[i] = t % 10;
//  }
//
//  return result;
//}