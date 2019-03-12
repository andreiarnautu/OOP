#ifndef OOP_BIG_INTEGERS_ARRAY_H
#define OOP_BIG_INTEGERS_ARRAY_H

#include "vector_class.h"
#include "big_integers_class.h"

class BigIntegersArray {
private:
  Vector<BigInteger > v;

public:
  BigIntegersArray();
  BigIntegersArray(int size);
  void SetArraySize(int size);
  int Size();

  BigInteger& operator[](int index);
  BigInteger operator[](int index) const;

  friend std::istream &operator >>(std::istream &i, BigIntegersArray &array);
  friend std::ostream &operator <<(std::ostream &o, BigIntegersArray &array);

  friend BigInteger operator *(BigIntegersArray array_a, BigIntegersArray array_b);

  BigInteger GetMaxAbsoluteValue();
};


#endif //OOP_BIG_INTEGERS_ARRAY_H
