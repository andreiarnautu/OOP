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
