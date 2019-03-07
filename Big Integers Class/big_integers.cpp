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

void TestBigInteger() {
  BigInteger a, b;
  std::cin >> a >> b;
  std::cout << a.Size() << " " << b.Size() << '\n';
  BigInteger c = a + b;

}

int main() {
  //TestVector();
  TestBigInteger();
  return 0;
}