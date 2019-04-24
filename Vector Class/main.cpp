/**
  *  Worg
  */
#include <iostream>
#include "vector.h"

int main() {
    Vector<int > v(10);

    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    v.PushBack(20); v.PushBack(25); v[7] = 105; v[15] = 20;

    for (Vector<int >::Iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (Vector<int >::Iterator it = v.rbegin(); it != v.rend(); it--) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    return 0;
}
