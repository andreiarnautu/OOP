/**
  *  Worg
  */
#include <iostream>

class Punct {
private:
  double x, y;

public:

  Punct(double x_p = 0, double y_p = 0) : x(x_p), y(y_p) {}

  static int c;

  Punct operator + (Punct A) {
    Punct result (this->x + A.x, this->y + A.y);
    return result;
  }


  Punct operator += (Punct A) {
    this->x += A.x; this->y += A.y;

    return *this;
  }


  bool operator < (Punct A) const {
    if (this->x == A.x) {
      return this->y < A.y;
    }
    return this->x < A.x;
  }


  bool operator == (Punct A) {
    return !((*this) < A) && !(A < (*this));
  }


  double& operator [](int index) {
    if (index == 0) {
      return this->x;
    } else if (index == 1) {
      return this->y;
    }

    throw 10;
  }


  Punct operator /(Punct A) {
    return Punct(this->x / A.x, this->y / A.y);
  }


  Punct operator *(Punct A) {
    return Punct(x * A.x, y * A.y);
  }


  friend Punct operator *(Punct A, double coef) {
    return Punct(A.x * coef, A.y * coef);
  }


  friend Punct operator *(double coef, Punct A) {
    return Punct(A.x * coef, A.y * coef);
  }


  friend std::ostream& operator <<(std::ostream& o, Punct A) {
    o << A.x << " " << A.y;
    return o;
  }


  Punct& operator ++() {
    this->x += 1; this->y += 1;
    return *this;
  }


  Punct operator ++(int) {
    Punct ret = *this;
    ++(*this);//this->x += 1; this->y += 1;
    return ret;
  }


  static void f() {
    std::cout << c;
  }
};

Punct pg;

void F() {
  pg[3] = 3;
}

int Punct::c = 0;

void Function(int y) {
  static int x;
  x += y;
  std::cout << x;
}

int main() {
  Punct a, b;
  a.c = 10;
  std::cout << b.c;  //  10
  Punct::c = 20;
  std::cout << a.c; // 20

//  try {
//    F();
//  } catch (int e) {
//    printf("E un parametru dat aiurea.\n");
//  } catch (Punct p) {
//    //  Nu ca am ajunge vreodata aici in acest program, dar poti da mai multe catchuri intr-un try-block. Pretty nice.
//  }

  return 0;
}