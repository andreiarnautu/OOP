#include "vector_class.h"

template<class Type >
Vector<Type >::Vector() {
  capacity = 2;
  size = 0;
  v = new Type[2];
  v[0] = v[1] = 0;
}

template<class Type >
Vector<Type >::Vector(const Vector<Type > &a) {
  size = a.size;
  capacity = a.capacity;

  v = new Type[capacity];
  for (int i = 0; i <= size; i++) {
    v[i] = a.v[i];
  }
}

template<class Type >
Vector<Type >::~Vector() {
  delete[ ] v;
}

template <class Type>
int Vector<Type >::Size() const {
  return size;
}


template <class Type>
Vector<Type >& Vector<Type >::operator =(const Vector<Type > &v2) {
  if (this == &v2) return *this;
  this->size = v2.size; this->capacity = v2.capacity;

  delete[] v;

  this->v = new int[this->capacity];
  for (int i = 1; i <= this->size; i++) {
    this->v[i] = v2.v[i];
  }

  return *this;
}

//  The implementation of the PushBack() method is similar to std::vector's implementation.
//  Since the operation is pretty expensive time-wise, we want to decrease the number of times the function is gonna
//  be called. In order to do that, we'll double its size when needed and the number of function calls will become
//  logarithmic instead of linear.
template <class Type>
void Vector<Type >::PushBack(Type x) {
  if (size + 1 == capacity) {
    int *new_v = new Type[2 * capacity];

    for (int i = 0; i < capacity; i++) {
      new_v[i] = v[i];
    }
    delete[] v;
    v = new_v;
    capacity *= 2;
  }

  ++size;
  v[size] = x;
}


//  Function that re-sizes the vector.
template <class Type>
void Vector<Type >::SetSize(int x) {
  int *new_v = new Type[x + 1];

  for (int i = 1; i <= x; i++) {
    new_v[i] = 0;
  }
  for (int i = 1; i <= size && i <= x; i++) {
    new_v[i] = v[i];
  }

  delete[] v;

  v = new_v;
  size = x; capacity = x + 1;
}


//  Function that resets the vector to its initial state.
template <class Type>
void Vector<Type >::Reset() {
  delete[] v;
  v = new Type[2];
  size = 0; capacity = 2;
}


template <class Type>
Type& Vector<Type >::operator[](int index) {
  if (index >= capacity) {
    int *new_v = new Type[(index + 1) * 2];
    for (int i = 0; i <= index; i++) {
      new_v[i] = this->v[i];
    }
    delete[] v;
    v = new_v;

    this->capacity = (index + 1) * 2; this->size = index;
  }

  if (index >= size) {
    size = index;
  }
  return v[index];
}

template <class Type>
Type Vector<Type >::operator[](int index) const {
  if (index > size) {
    return 0;
  }
  return v[index];
}