/**
  *  Worg
  */
#include <iostream>
#include "vector_class.cpp"
#include "big_integers_class.cpp"
#include "big_integers_array.cpp"

void TestVector() {
  Vector<int > v;
  v.PushBack(1); v.PushBack(2); v.PushBack(3); v.PushBack(4);
  std::cout << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << '\n';
  std::cout << v.Size() << '\n';
}

void TestBigIntegerSum() {
  BigInteger a(100), b(1);
  BigInteger c; c = a + b;
  std::cout << c << '\n';
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

void TestSqrt() {
  BigInteger a(1024);
  BigInteger b; b = Sqrt(a);

  std::cout << b << '\n';
}

void TestReadingArray() {
  BigIntegersArray array(5);
  std::cin >> array;
  std::cout << array;
}

void TestArrayMultiplier() {
  BigIntegersArray a(5); a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
  BigIntegersArray b(5); b[0] = 2; b[1] = 3; b[2] = 4; b[3] = 5; b[4] = 5;

  BigInteger c = a * b;
  std::cout << c;
}

void TestArrayMaxAbsoluteValue() {
  BigIntegersArray a(5); a[0] = -100; a[1] = 120; a[2] = 300; a[3] = 400; a[4] = -420;
  BigInteger c = a.GetMaxAbsoluteValue();
  std::cout << c;
}

void TestOperator() {
  BigInteger a, b, c;
  a = b = c = 10;

  std::cout << a << " " << b << " " << c;
}

int main() {
  //TestVector();
  //TestBigIntegerSum();
  //TestBigIntegerDifference();
  //TestBigIntegerMultiplication();
  //TestDivision();
  //TestSqrt();
  //TestReadingArray();
  //TestArrayMultiplier();
  //TestArrayMaxAbsoluteValue();
  //TestOperator();
  BigInteger x(12321), y(7854);
  if (x == x / y * y + x % y) {
    std::cout << "Merge\n";
  } else {
    std::cout << "Nu merge\n";
  }

  return 0;
}
