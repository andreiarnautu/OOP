/**
  *  This file contains all the functions implemented for the BigInteger class.
  *  add_executable("Lab 2" constructor_destructor.cpp)
  */
#include <iostream>
#include "big_integers_class.h"

/*
 *  TODO:
 *    -> the sum of 2 big integers (by overloading the operator '+') - DONE
 *    -> the difference of 2 big integers (by overloading the operator '-') - DONE
 *    -> the product of 2 big integers (by overloading the operator '*') - DONE
 *    -> the maximum between the absolute values of 2 big integers - DONE
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


void BigInteger::Fix() {
  //  Erase leading zeroes
  while (this->Size() > 1 && this->digits[this->Size()] == 0) {
    this->digits.SetSize(this->Size() - 1);
  }

  //  Fix the sign if the number is equal to zero.
  if (this->Size() == 0 || (this->Size() == 1 && this->digits[1] == 0)) {
    this->sign = '+';
    this->digits[1] = 0;
  }
}


void BigInteger::ChangeSign() {
  if (this->sign == '+') {
    this->sign = '-';
  } else {
    this->sign = '+';
  }
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


bool CompareIntegerParts(const BigInteger & A, const BigInteger & B) {
  //  Function returns 1 if abs(A) > abs(B) and 0 otherwise

  if (A.Size() > B.Size()) {
    return true;
  } else if (A.Size() < B.Size()) {
    return false;
  }

  for (int i = A.Size(); i > 0; i--) {
    if (A.digits[i] > B.digits[i]) {
      return true;
    } else if (A.digits[i] < B.digits[i]) {
      return false;
    }
  }

  return false;  //  if this line is reached abs(A) == abs(B)
}


BigInteger AddAbsoluteValues(BigInteger A, BigInteger B) {
  BigInteger result;
  int t = 0;
  for (int i = 1; i <= A.Size() || i <= B.Size() || t > 0; i++, t /= 10) {
    if (i <= A.Size()) {
      t += A.digits[i];
    }
    if (i <= B.Size()) {
      t += B.digits[i];
    }

    //result.digits.SetSize(i);
    result.digits[i] = t % 10;
  }
  return result;
}


BigInteger SubtractAbsoluteValues(BigInteger A, BigInteger B) {
  int t = 0;

  BigInteger result = A; result.sign = '+';
  for (int i = 1; i <= result.Size(); i++) {
    if (i <= B.Size()) {
      result.digits[i] -= (B.digits[i] + t);
    } else {
      result.digits[i] -= t;
    }

    if (result.digits[i] < 0) {
      t = 1;
    } else {
      t = 0;
    }

    result.digits[i] += 10 * t;
  }

  result.Fix();

  return result;
}


BigInteger operator +(BigInteger A, const BigInteger &B) {
  BigInteger result;

  if (A.sign == '+' && B.sign == '+') {
    result = AddAbsoluteValues(A, B);
    return result;
  }

  if (A.sign == '-' && B.sign == '-') {
    result = AddAbsoluteValues(A, B);
    result.ChangeSign();
    return result;
  }

  if (A.sign == '-' && B.sign == '+') {
    A.ChangeSign();
    result = B - A;
    return result;
  }

  if (A.sign == '+' && B.sign == '-') {
    BigInteger B_copy = B; B_copy.ChangeSign();
    result = A - B_copy;
    return result;
  }
}


BigInteger operator -(BigInteger A, BigInteger const & B) {
  BigInteger result;

  if (A.sign == '+' && B.sign == '-') {
    BigInteger B_copy = B;
    B_copy.ChangeSign();
    result = A + B_copy;
    return result;
  }

  if (A.sign == '+' && B.sign == '+') {
    if(CompareIntegerParts(B, A)) {  //  if A < B
      result = B - A;
      result.ChangeSign();
    } else {
      result = SubtractAbsoluteValues(A, B);
    }
    return result;
  }

  if (A.sign == '-' && B.sign == '-') {
    if (CompareIntegerParts(B, A)) {
      result = SubtractAbsoluteValues(B, A);
    } else {
      result = SubtractAbsoluteValues(A, B);
      result.ChangeSign();
    }
    return result;
  }

  if (A.sign == '-' && B.sign == '+') {
    A.ChangeSign();
    result = A + B;
    result.ChangeSign();
    return result;
  }
}


BigInteger operator *(BigInteger A, BigInteger const & B) {
  BigInteger result; result.digits.SetSize(A.Size() + B.Size() - 1);

  for (int i = 1; i <= A.Size(); i++) {
    for (int j = 1; j <= B.Size(); j++) {
      result.digits[i + j - 1] += A.digits[i] * B.digits[j];
    }
  }

  int t = 0;
  for (int i = 1; i <= result.Size(); i++) {
    result.digits[i] += t;
    t = result.digits[i] / 10;
    result.digits[i] %= 10;
  }

  if (t != 0) {
    result.digits[result.Size() + 1] = t;
  }

  //  Check the sign of the result.
  if (A.sign == '+' && B.sign == '-') {
    result.sign = '-';
  }
  if (A.sign == '-' && B.sign == '+') {
    result.sign = '-';
  }

  return result;
}


BigInteger GetMaxAbsoluteValue(const BigInteger & A, const BigInteger & B) {
  if (CompareIntegerParts(A, B)) {
    BigInteger result = A; result.sign = '+';
    return result;
  }

  BigInteger result = B; result.sign = '+';
  return result;
}