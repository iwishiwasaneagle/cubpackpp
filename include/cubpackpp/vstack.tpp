/////////////////////////////////////////////////////////
//                                                     //
//    Cubpack++                                        //
//                                                     //
//        A Package For Automatic Cubature             //
//                                                     //
//        Authors : Ronald Cools                       //
//                  Dirk Laurie                        //
//                  Luc Pluym                          //
//                                                     //
/////////////////////////////////////////////////////////
/////////////////////////////////////////////
//File vstack.cpp
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
/////////////////////////////////////////////
#include "cubpackpp/vstack.h"
#include <stdlib.h>
#include "cubpackpp/error.h"
#include <iostream>
#include <string.h>

namespace cubpackpp {
    template<class T>
    VectorStack<T>::VectorStack()
            :Vector<T>() {
    }

///////////////////////////////////////////////////
    template<class T>
    VectorStack<T>::VectorStack(const VectorStack<T> &v)
            :Vector<T>(v) {
    }

///////////////////////////////////////////////////
    template<class T>
    VectorStack<T> &
    VectorStack<T>::operator=(const VectorStack<T> &v) {
        if (this->TheSize == 0) {
            this->TheSize = v.TheSize;
            this->Contents = new T[this->TheSize];
            Error(!this->Contents, "Vectorassign:allocation failed");
        };
        Error((this->TheSize != v.TheSize), "lengths of arrays incompatible");
        for (unsigned int i = 0; i < this->TheSize; i++) {
            this->Contents[i] = v.Contents[i];
        };
        return *this;
    }

////////////////////////////////////////////////////
    template<class T>
    void
    VectorStack<T>::operator+=(const T &t) {
        T *New = new T[this->TheSize + 1];
        for (unsigned int i = 0; i < this->TheSize; i++) {
            New[i + 1] = this->Contents[i];
        };
        if (this->TheSize != 0) {
            delete[]  this->Contents;
        };
        this->Contents = New;
        this->Contents[0] = t;
        this->TheSize++;
    }
///////////////////////////////////////////////////
} // cubpackpp
