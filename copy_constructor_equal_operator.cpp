
char& BigInteger::Sign() {
  return sign;
}

int BigInteger::Size() {
  return digits.Size();
}

int BigInteger::operator[](int index) {
  return digits[index];
}

void Swap(int& a, int& b) {
  int c = a;
  a = b; b = c;
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
    Swap(integer.digits[j], integer.digits[k]);
  }

  return i;
}

std::ostream &operator<<(std::ostream &o, BigInteger &integer) {
  for (int i = integer.Size(); i >= 1; i--) {
    o << integer[i];
  }

  //  A number with virtually no size is equal to zero.
  if (integer.Size() == 0) {
    o << "0";
  }

  return o;
}