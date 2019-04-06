/**
  *  Worg
  */
#ifndef OOP_BIG_INTEGER_CLASS_H
#define OOP_BIG_INTEGER_CLASS_H

#include <cstdlib>
#include <iostream>
#include "big_positive_integer_class.h"

class BigInteger : public BigPositiveInteger {
private:
    char m_sign;



public:
    //  Constructors
    BigInteger();
    BigInteger(int value);
    BigInteger(const BigInteger& a);

    //  Basic functionality stuff.
    int Size() const override;
    int& operator[](int index) override;
    int operator [](int index) const override;
    void Fix() override;
    bool IsNull() override;
    void ChangeSign();
    friend std::istream& operator >>(std::istream& in, BigInteger &integer);
    friend std::ostream& operator <<(std::ostream& out, BigInteger &integer);
    BigInteger& operator =(int value);
    BigInteger& operator =(const BigInteger& a);


    //  Comparation stuff
    int CompareIntegerParts(const BigPositiveInteger& a) override;
    bool operator ==(const BigInteger & a);
    bool operator < (const BigInteger & a);

    //  Operations with big numbers
private:
    BigInteger AddAbsoluteValues(const BigInteger& a, const BigInteger& b);
    BigInteger SubtractAbsoluteValues(const BigInteger& a, const BigInteger& b);
public:
    BigInteger operator +(BigInteger const& a);
    BigInteger operator -(BigInteger const& a);
    BigInteger operator *(BigInteger const &a);
    BigInteger operator /(BigInteger const& a);
    BigInteger operator %(BigInteger const& a);
    BigInteger Sqrt();
};


BigInteger::BigInteger() {
    m_sign = '+';
}


int BigInteger::Size() const {
    return m_size;
}


int& BigInteger::operator[](int index) {
    return Vector<int >::operator[](index);
}


int BigInteger::operator[](int index) const {
    return Vector<int >::operator[](index);
}


BigInteger::BigInteger(int value) {
    if (value < 0) {
        m_sign = '-'; value *= -1;
    } else {
        m_sign = '+';
    }

    int index = 0;
    do {
        this->operator[](++index) = value % 10;
        value /= 10;
    }while (value > 0);
}


BigInteger::BigInteger(const BigInteger &a) {
    delete [] m_array;

    m_capacity = a.m_capacity;
    m_size = a.m_size;
    m_array = new int[m_capacity];
    m_sign = a.m_sign;

    for (int i = 0; i < m_capacity; i++) {
        m_array[i] = a.m_array[i];
    }
}


void BigInteger::Fix() {
    //  Erase leading zeroes
    while (m_size > 0 && this->operator[](m_size) == 0) {
        m_size--;
    }

    //  Fix the sign if the number is equal to zero.
    if (m_size == 0 || (m_size == 1 && this->operator[](1) == 0)) {
        m_sign = '+';
        this->operator[](1) = 0;
    }
}


bool BigInteger::IsNull() {
    Fix();

    return m_size == 1 && this->operator[](1) == 0;
}


void BigInteger::ChangeSign() {
    if (m_sign == '+') {
        m_sign = '-';
    } else {
        m_sign = '+';
    }
}


void Swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}


std::istream &operator>>(std::istream &in, BigInteger &integer) {
    char c;
    bool found_number = false;

    integer.Vector::Reset(); integer.m_sign = '+';

    while (!in.eof()) {
        in.get(c);

        if (c < '0' || c > '9') {
            if (found_number) {
                break;
            } else if (c == '-') {
                integer.m_sign = '-';
            }
        } else {
            c -= '0';
            integer[++integer.m_size] = c;
            found_number = true;
        }
    }

    //  We want to reverse the order of digits, such that the least significant one is placed first.
    for (int i = 1, j = integer.m_size; i <= j; i++, j--) {
        Swap(integer[i], integer[j]);
    }

    return in;
}


std::ostream &operator<<(std::ostream &out, BigInteger &integer) {
    if (integer.m_sign == '-') {
        out << '-';
    }
    for (int i = integer.m_size; i > 0; i--) {
        out << integer[i];
    }

    //  Corner-case.
    if (integer.m_size == 0) {
        out << '0';
    }

    return out;
}


BigInteger &BigInteger::operator =(int value) {
    Reset();

    if (value < 0) {
        m_sign = '-';
        value *= -1;
    } else {
        m_sign = '+';
    }

    int index = 0;
    do {
        this->operator[](++index) = value % 10;
        value /= 10;
    } while(value > 0);

    return *this;
}



BigInteger &BigInteger::operator =(const BigInteger& a) {
    delete [] m_array;

    m_sign = a.m_sign;
    m_capacity = a.m_capacity;
    m_size = a.m_size;
    m_array = new int[m_capacity];

    for (int i = 0; i < m_capacity; i++) {
        m_array[i] = a.m_array[i];
    }
    return *this;
}


//  Function returns 1 if abs(this) > abs(a); 0 if equal; -1 if abs(this) < abs(a)
int BigInteger::CompareIntegerParts(const BigPositiveInteger &a) {
    if (m_size > a.Size()) {
        return 1;
    } else if (m_size < a.Size()) {
        return -1;
    }

    for (int i = m_size; i > 0; i--) {
        if (this->operator[](i) > a[i]) {
            return 1;
        } else if (this->operator[](i) < a[i]) {
            return -1;
        }
    }

    return 0;
}


bool BigInteger::operator ==(const BigInteger &a) {
    if (m_sign == a.m_sign) {
        return CompareIntegerParts(a) == 0;
    }
    return false;
}


bool BigInteger::operator <(const BigInteger &a) {
    if (m_sign == '-' && a.m_sign == '-') {
        int compare_result = CompareIntegerParts(a);
        return compare_result == 1;
    } else if (m_sign == '-' && a.m_sign == '+') {
        return true;
    } else if (m_sign == '+' && a.m_sign == '-') {
        return false;
    } else {
        int compare_result = CompareIntegerParts(a);
        return compare_result == -1;
    }
}


BigInteger BigInteger::AddAbsoluteValues(const BigInteger& a, const BigInteger& b) {
    BigInteger result;

    for (int i = 1, t = 0; i <= a.m_size || i <= b.m_size || t > 0; i++, t /= 10) {
        if (i <= a.m_size) {
            t += a[i];
        }
        if (i <= b.m_size) {
            t += b[i];
        }

        result[i] = t % 10;
    }
    return result;
}


BigInteger BigInteger::SubtractAbsoluteValues(const BigInteger &a, const BigInteger& b) {
    int t = 0;

    BigInteger result = a; result.m_sign = '+';

    for (int i = 1; i <= result.m_size; i++) {
        if (i <= b.m_size) {
            result[i] -= (b[i] + t);
        } else {
            result[i] -= t;
        }

        if (result[i] < 0) {
            t = 1;
        } else {
            t = 0;
        }

        result[i] += 10 * t;
    }

    result.Fix();
    return result;
}


BigInteger BigInteger::operator +(BigInteger const& a) {
    BigInteger result;

    if (this->m_sign == '+' && a.m_sign == '+') {
        result = AddAbsoluteValues(*this, a);
    } else if (this->m_sign == '+' && a.m_sign == '-') {
        int compare_result = this->CompareIntegerParts(a);

        if (compare_result >= 0) {
            result = SubtractAbsoluteValues(*this, a);
        } else {
            result = SubtractAbsoluteValues(a, *this);
            result.m_sign = '-';
        }
    } else if (this->m_sign == '-' && a.m_sign == '+') {
        int compare_result = this->CompareIntegerParts(a);

        if (compare_result >= 0) {
            result = SubtractAbsoluteValues(*this, a);
            result.m_sign = '-';
        } else {
            result = SubtractAbsoluteValues(a, *this);
        }
    } else {
        result = AddAbsoluteValues(*this, a);
        result.m_sign = '-';
    }

    result.Fix();
    return result;
}


BigInteger BigInteger::operator -(BigInteger const& a) {
    BigInteger result;

    if (this->m_sign == '+' && a.m_sign == '+') {
        int compare_result = this->CompareIntegerParts(a);

        if (compare_result >= 0) {
            result = SubtractAbsoluteValues(*this, a);
        } else {
            result = SubtractAbsoluteValues(a, *this);
            result.m_sign = '-';
        }
    } else if (this->m_sign == '+' && a.m_sign == '-') {
        result = AddAbsoluteValues(*this, a);
    } else if (this->m_sign == '-' && a.m_sign == '+') {
        result = AddAbsoluteValues(*this, a);
        result.m_sign = '-';
    } else {
        int compare_result = this->CompareIntegerParts(a);

        if (compare_result >= 0) {
            result = SubtractAbsoluteValues(*this, a);
            result.m_sign = '-';
        } else {
            result = SubtractAbsoluteValues(a, *this);
        }
    }

    result.Fix();
    return result;
}


BigInteger BigInteger::operator *(BigInteger const& a) {
    BigInteger result;

    for (int i = 1; i <= this->m_size; i++) {
        for (int j = 1; j <= a.m_size; j++) {
            result[i + j - 1] += this->operator[](i) * a[j];
        }
    }

    int t = 0;
    for (int i = 1; i <= result.m_size; i++) {
        result[i] += t;
        t = result[i] / 10;
        result[i] %= 10;
    }
    if (t != 0) {
        result[result.m_size + 1] = t;
    }

    //  Compute the sign of the result.
    if (this->m_sign == '-' && a.m_sign == '+') {
        result.m_sign = '-';
    } else if (this->m_sign == '+' && a.m_sign == '-') {
        result.m_sign = '-';
    }

    result.Fix();
    return result;
}


BigInteger BigInteger::operator /(BigInteger const &a) {
    //  Let's suppose this = b * c + r;

    BigInteger b(a);  //  For easier implementation (workaround for const &a)
    if (b.IsNull()) {
        std::cout << "Error: Division by zero(0).\n";
        exit(0);
    }

    BigInteger c, r;
    BigInteger ten(10);

    for (int i = m_size; i > 0; i--) {
        r = r * ten;
        r[1] = this->operator[](i);
        r.Fix();

        while (b.CompareIntegerParts(r) < 1) {  //  while (b <= r)
            c[i]++;
            r = SubtractAbsoluteValues(r, b);
        }
    }

    //  Compute the sign of the result.
    if (this->m_sign == '-' && a.m_sign == '+') {
        c.m_sign = '-';
    } else if (this->m_sign == '+' && a.m_sign == '-') {
        c.m_sign = '-';
    }

    c.Fix();
    return c;
}


BigInteger BigInteger::operator%(BigInteger const &a) {
    //  Let's suppose this = b * c + r;

    BigInteger b(a);  //  For easier implementation (workaround for const &a)
    if (b.IsNull()) {
        std::cout << "Error: Division by zero(0).\n";
        exit(0);
    }

    BigInteger c, r;
    BigInteger ten(10);

    for (int i = m_size; i > 0; i--) {
        r = r * ten;
        r[1] = this->operator[](i);
        r.Fix();

        while (b.CompareIntegerParts(r) < 1) {  //  while (b <= r)
            c[i]++;
            r = SubtractAbsoluteValues(r, b);
        }
    }

    //  Compute the sign of the result.
    if (this->m_sign == '-') {
        r.m_sign = '-';
    }

    r.Fix();
    return r;
}


BigInteger BigInteger::Sqrt() {
    if (this->m_sign == '-') {
        std::cout << "Sqrt of a negative number? C'mon, you can do better than that...\n";
        exit(0);
    }

    BigInteger a(*this);

    BigInteger x0(a), aux(1), x1;
    x1 = x0 + aux;
    x1 = x1 / 2;

    while (x0.CompareIntegerParts(x1)) {  //  while x0 > x1
        x0 = x1;
        BigInteger two(2);

        //  x1 = (x1 + a/x1) / 2;
        aux = a / x1;
        x1 = x1 + aux;
        x1 = x1 / two;
    }

    return x0;
}

#endif //OOP_BIG_INTEGER_CLASS_H
