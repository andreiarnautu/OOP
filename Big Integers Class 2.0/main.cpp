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

void TestAdditionAndSubtraction() {
    BigInteger a(1023), b(-5012), d(5);
    BigInteger c = a - b + d;

    std::cout << c << '\n';
}

void TestMultiplication() {
    BigInteger a(-12), b(101);
    BigInteger c = a * b;

    std::cout << c << '\n';
}

void TestDivision() {
    BigInteger a(1300), b(40);
    BigInteger c = a % b;

    std::cout << c << '\n';
}


void TestSqrt() {
    BigInteger a(-1025), b = a.Sqrt();

    std::cout << b;
}


void FinalTest() {
    BigInteger x(23123123), y(89234);

    if (x == x / y * y + x % y) {
        std::cout << "ok\n";
    } else {
        std::cout << "not ok\n";
    }
}


void TestIterator() {
    Vector<int > v;
    v[1] = 2; v[2] = 3; v[3] = 5; v[4] = 7;

    for (Vector<int >::Iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    for (Vector<int >::Iterator it = v.rbegin(); it != v.rend(); it--) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

int main() {
    FinalTest();
    TestIterator();
    return 0;
}