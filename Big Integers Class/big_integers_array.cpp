#include "big_integers_array.h"

BigIntegersArray::BigIntegersArray() {
  v.SetSize(2);
}


BigIntegersArray::BigIntegersArray(int size) {
  v.SetSize(size);
}


void BigIntegersArray::SetArraySize(int size) {
  v.SetSize(size);
}


int BigIntegersArray::Size() {
  return v.Size();
}


BigInteger& BigIntegersArray::operator[](int index) {
  return v[index];
}


BigInteger BigIntegersArray::operator[](int index) const {
  return v[index];
}


std::istream &operator >>(std::istream &i, BigIntegersArray &array) {
  for (int i = 0; i < array.v.Size(); i++) {
    std::cin >> array.v[i];
  }

  return i;
}


std::ostream &operator <<(std::ostream &o, BigIntegersArray &array) {
  for (int i = 0; i < array.v.Size(); i++) {
    std::cout << array.v[i] << " ";
  }
  return o;
}


BigInteger operator *(BigIntegersArray array_a, BigIntegersArray array_b) {
  BigInteger result(0);

  for (int i = 0; i < array_a.Size(); i++) {
    result = result + array_a[i] * array_b[i];
  }

  return result;
}


BigInteger BigIntegersArray::GetMaxAbsoluteValue() {
  BigInteger result = v[0];

  for (int i = 1; i < this->Size(); i++) {
    if (CompareIntegerParts(v[i], result)) {
      result = v[i];
    }
  }

  if (result.Sign() == '-') {
    result.ChangeSign();
  }
  return result;
}