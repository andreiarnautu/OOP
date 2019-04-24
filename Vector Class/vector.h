/**
  *  Worg
  */

#ifndef OOP_VECTOR_H
#define OOP_VECTOR_H

#include <cassert>

template <class T >
class Vector {

private:
    unsigned int m_size;
    unsigned int m_capacity;
    T* m_array;


public:
    //  constructors and destructor
    Vector();
    Vector(unsigned int size);
    Vector(Vector<T > const& v);
    ~Vector();

    //  specific functions
    unsigned int Capacity() const;
    unsigned int Size() const;
    bool Empty() const;

    T& Front();
    T& Back();
    T& Front() const;
    T& Back() const;

    void Reserve(unsigned int capacity);
    void Resize(unsigned int size);

    void PushBack(const T& value);
    void PopBack();

    T& operator [] (unsigned int index);
    T& operator [] (unsigned int index) const;

    Vector<T>& operator = (Vector<T > const&);
    void Clear();

    //  iterator stuff
    typedef T* Iterator;
    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();
};


//  Constructors
template <class T >
Vector<T>::Vector() : m_size(0), m_capacity(1), m_array(new T[m_capacity]) {

}


template <class T >
Vector <T >::Vector(unsigned int size) : m_size(size), m_capacity(2 * m_size), m_array(new T[m_capacity]) {

}


template <class T >
Vector<T >::Vector(Vector<T > const& v) : m_size(v.m_size), m_capacity(v.m_capacity), m_array(new T[m_capacity]) {
    for (int i = 0; i < m_size; i++) {
        m_array[i] = v.m_array[i];
    }
}


//  Destructor
template <class T >
Vector<T>::~Vector() {
    delete [] m_array;
}


template <class T >
unsigned int Vector<T>::Capacity() const {
    return m_capacity;
}


template <class T >
unsigned int Vector<T>::Size() const {
    return m_size;
}


template <class T >
bool Vector<T>::Empty() const {
    return m_size == 0;
}


template <class T >
T& Vector<T>::Front() {
    assert(m_size != 0);
    return m_array[0];
}


template <class T >
T& Vector<T>::Back() {
    assert(m_size != 0);
    return m_array[m_size - 1];
}


template <class T >
T& Vector<T>::Front() const {
    assert(m_size != 0);
    return m_array[0];
}


template <class T >
T& Vector<T>::Back() const {
    assert(m_size != 0);
    return m_array[m_size - 1];
}


template <class T >
void Vector<T>::Reserve(unsigned int capacity) {
    T *new_array = new T[capacity];

    for (int i = 0; i < static_cast<int>(m_size); i++) {
        new_array[i] = m_array[i];
    }

    m_capacity = capacity;
    delete [] m_array;
    m_array = new_array;
}


template <class T >
void Vector<T>::Resize(unsigned int size) {
    Reserve(size * 2);
    m_size = size;
}


template <class T >
void Vector<T>::PushBack(const T& value) {
    if (m_size >= m_capacity) {
        Reserve(2 * m_size);
    }
    m_array[m_size++] = value;
}


template <class T >
T& Vector<T>::operator [] (unsigned int index) {
    return m_array[index];
}


template <class T >
T& Vector<T>::operator [] (unsigned int index) const {
    return m_array[index];
}


template <class T >
Vector<T>& Vector<T>::operator = (Vector<T > const& v) {
    if (this == &v) {
        return *this;
    }

    delete[] m_array;

    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_array = new T[m_capacity];

    for (int i = 0; i < m_size; i++) {
        m_array[i] = v.m_array[i];
    }

    return *this;
}


template <class T >
void Vector<T>::Clear() {
    m_size = 0;
    m_capacity = 1;
    delete [] m_array;

    m_array = new T[m_capacity];
}


template <class T >
typename Vector<T>::Iterator Vector<T >::begin() {
    return m_array;
}


template <class T >
typename Vector<T>::Iterator Vector<T >::end() {
    return m_array + m_size;
}


template <class T >
typename Vector<T>::Iterator Vector<T >::rbegin() {
    return m_array + m_size - 1;
}


template <class T >
typename Vector<T>::Iterator Vector<T >::rend() {
    return m_array - 1;
}

#endif //OOP_VECTOR_H
