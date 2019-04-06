/**
  *  Worg
  */
#include <iostream>
#include "big_integer_class.h"

void TestConstructor() {
    BigInteger a(1023);
    std::cout << a << '\n';
    BigInteger b(a);
    std::cout << b << '\n';

    BigInteger c = 100; c = -902123123;

    std::cout << c;
}

int main() {

    return 0;
}