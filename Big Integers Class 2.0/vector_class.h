#ifndef OOP_VECTOR_CLASS_H
#define OOP_VECTOR_CLASS_H

#include <iostream>

template<class T >
class Vector {
protected:
    T *m_array;
    int m_size;
    int m_capacity;

public:
    Vector();
    Vector(const Vector<T > & v);
    ~Vector();

    Vector<T > & operator = (const Vector<T > & v2);

    virtual int Size() const;
    void Reset();

    virtual T operator [](int index) const;
    virtual T& operator [](int index);

    //  Iterator stuff
public:
    typedef T* Iterator;

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();
};




//  Basic constructor.
template<class T >
Vector<T >::Vector() {
    m_capacity = 2;
    m_size = 0;
    m_array = new T[2];
    m_array[0] = m_array[1] = 0;
}


//  Constructor with another vector given as a parameter
template<class T >
Vector<T >::Vector(const Vector<T > & v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_array = new T[m_capacity];

    for (int i = 0; i <= m_size; i++) {
        m_array[i] = v.m_array[i];
    }
}


//  Destructor
template<class T >
Vector<T >::~Vector() {
    delete [] m_array;
}


template<class T >
Vector<T > & Vector<T >::operator = (const Vector<T > & v) {
    if (this == &v) {
        return *this;
    }
    delete [] m_array;
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_array = new T[m_capacity];

    for (int i = 1; i <= m_size; i++) {
        m_array[i] = v.m_array[i];
    }

    return *this;
}


//  Get size function
template<class T >
int Vector<T >::Size() const {
    return m_size;
}


template<class T >
void Vector<T >::Reset() {
    delete [] m_array;
    m_array = new T[2];
    m_array[0] = m_array[1] = 0;
    m_size = 0; m_capacity = 2;
}


template<class T >
T Vector<T >::operator [](int index) const {
    if (index > m_size) {
        return 0;
    }
    return m_array[index];
}


template<class T >
T& Vector<T >::operator[](int index) {
    if (index >= m_capacity) {
        T *new_array = new T[index + 5];

        for (int i = 0; i < m_capacity; i++) {
            new_array[i] = m_array[i];
        }
        for (int i = m_capacity; i < index + 5; i++) {
            new_array[i] = 0;
        }
        delete [] m_array;
        m_array = new_array;

        m_capacity = index + 5; m_size = index;
    }

    if (index >= m_size) {
        m_size = index;
    }
    return m_array[index];
}


template<class T>
typename Vector<T >::Iterator Vector<T>::begin() {
    return m_array + 1;
}


template<class T>
typename Vector<T >::Iterator Vector<T>::end() {
    return m_array + m_size + 1;
}


template<class T>
typename Vector<T >::Iterator Vector<T>::rbegin() {
    return m_array + m_size;
}


template<class T>
typename Vector<T >::Iterator Vector<T>::rend() {
    return m_array;
}

#endif //OOP_VECTOR_CLASS_H
