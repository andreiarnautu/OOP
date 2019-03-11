/**
  *  Worg
  */
#include <iostream>

long long Check(const long long value) {
  long long divisor_sum = 1;

  for (long long i = 2; i <= value / 2; i++) {
    if (value % i == 0) {
      divisor_sum += i;
    }
  }

  if (divisor_sum == value) {
    return value;
  } else {
    return 0;
  }
}

int main() {
  long long a, b; std::cin >> a >> b;

  long long answer = 0;
  for (long long i = a; i < b; i++) {
    answer += Check(i);
    if (Check(i)) {
      std::cout << "Numar perfect: " << i << '\n';
    }
  }

  std::cout << answer << '\n';
  return 0;
}
