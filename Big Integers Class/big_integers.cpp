/**
  *  Worg
  */
#include <iostream>
#include "vector_class.cpp"
#include "big_integers_class.cpp"

void TestVector() {
  Vector<int > v;
  v.PushBack(1); v.PushBack(2); v.PushBack(3); v.PushBack(4);
  std::cout << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << '\n';
  std::cout << v.Size() << '\n';
}

void TestBigIntegerSum() {
  BigInteger a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a.Size() << " " << b.Size() << " " << c.Size() << '\n';
  BigInteger d = a + b + c;
  std::cout << d;
}

void TestBigIntegerDifference() {
  BigInteger a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a << " " << b << " " << c << '\n';

  BigInteger d = a - b - c;
  std::cout << d;
}

void TestBigIntegerMultiplication() {
  BigInteger a, b, c;
  std::cin >> a >> b >> c;
  BigInteger d = a * b * c;
  std::cout << d;
}

void TestDivision() {
  BigInteger a; a = -100;
  BigInteger b; b = 2;
  BigInteger e; e = -5;
  BigInteger c; c = a / b / e;
  BigInteger d; d = a % e;
  std::cout << c << '\n' << d << '\n';
}

int main() {
  //TestVector();
  //TestBigIntegerSum();
  //TestBigIntegerDifference();
  //TestBigIntegerMultiplication();
  //TestDivision();

  return 0;
}