/**
  *  Worg
  */
#ifndef OOP_BIG_INTEGER_CLASS_H
#define OOP_BIG_INTEGER_CLASS_H

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
    BigInteger operator +(const BigInteger& a);
    BigInteger operator -(const BigInteger& a);
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
            t += a.m_array[i];
        }
        if (i <= b.m_size) {
            t += b.m_array[i];
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


BigInteger BigInteger::operator +(const BigInteger &a) {
    BigInteger result;

    if (this->m_sign == '+' && a.m_sign == '+') {
        result = AddAbsoluteValues(*this, a);
    } else if (this->m_sign == '+' && a.m_sign == '-') {

    }
}


BigInteger BigInteger::operator -(const BigInteger &a) {

}

#endif //OOP_BIG_INTEGER_CLASS_H
