/**
  *  Worg
  */
#ifndef OOP_BIG_POSITIVE_INTEGER_CLASS_H
#define OOP_BIG_POSITIVE_INTEGER_CLASS_H


#include <iostream>
#include "vector_class.h"

//  Pure abstract class (interface)
class BigPositiveInteger : public Vector<int > {
public:
    virtual void Fix() = 0;
    virtual bool IsNull() = 0;
    virtual int CompareIntegerParts(const BigPositiveInteger &a) = 0;
};

#endif //OOP_BIG_POSITIVE_INTEGER_CLASS_H
