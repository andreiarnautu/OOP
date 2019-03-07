/**
  *  Worg
  */
#ifndef OOP_VECTOR_CLASS_H
#define OOP_VECTOR_CLASS_H

template <class Type >
class Vector {
private:
  Type* v;
  int size, capacity;

public:
//  Vector<Type >() : size(0), capacity(2) {
//    v = new Type[2];
//    v[0] = v[1] = 0;
//  }
//
//
//  Vector<Type >(const Vector<Type > &v2) : size(v2.size), capacity(v2.capacity), v(new Type[capacity]) {
//    for (int i = 0; i <= this->capacity; i++) {
//      this->v[i] = v2.v[i];
//    }
//  }
//
//
//  ~Vector() {
//    delete[] v;
//  }

  Vector();
  Vector(const Vector<Type > &v);
  ~Vector();


  Vector<Type >& operator =(const Vector<Type >& v2);
  int Size() const;
  void PushBack(Type x);
  void SetSize(int x);
  void Reset();
  Type& operator[](int index);
  Type operator[](int index) const;
};

#endif //OOP_VECTOR_CLASS_H
