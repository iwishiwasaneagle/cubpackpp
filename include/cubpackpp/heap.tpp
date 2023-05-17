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
///////////////////////////////////////////////
//File heap.cpp
// History:
//   (date)          (version)
//   19 Aug 1994     V0.1 (first limited distribution)
//   30 Jan 1996     V0.1g(good for old and new ANSI for-scope)
///////////////////////////////////////////////

#include "cubpackpp/heap.h"
#include <iostream>
#include <stdlib.h>
#include "cubpackpp/error.h"

namespace cubpackpp {
//////////////////////////////////////////////

    template<class T, int CAPACITY>
    SubHeap<T, CAPACITY>::SubHeap()
            :Set<T>() {
        ActiveChild = -1;
        LastChild = -1;
    }

////////////////////////////////////////////////
    template<class T, int CAPACITY>
    SubHeap<T, CAPACITY>::~SubHeap() {
        Clear();
    }

///////////////////////////////////////////////
    template<class T, int CAPACITY>
    T *
    SubHeap<T, CAPACITY>::Get() {
        Error(this->Number == 0, "error:get from empty heap");
        if (this->Number == 1) {
            this->Number--;
            return Contents[1];
        };
        T *B = Bottom();
        if (LastChild == CAPACITY && Children[ActiveChild]->Saturated()) {
            ActiveChild--;
            if (ActiveChild < 0) ActiveChild = CAPACITY;
        };
        T *Result = Contents[1];
        int Hole = 1;
        int First = 2;
        int Second = 3;
        while (Second <= this->Number) {
            if ((*B >= *Contents[First])
                && (*B >= *Contents[Second])) {
                goto putinhole;
            } else {
                if (*Contents[First] >= *Contents[Second]) {
                    Contents[Hole] = Contents[First];
                    Hole = First;
                    First = 2 * Hole;
                    Second = First + 1;
                } else {
                    Contents[Hole] = Contents[Second];
                    Hole = Second;
                    First = 2 * Hole;
                    Second = First + 1;
                };
            };
        };
        if (First == this->Number) {
            if (*B >= *Contents[First]) {
                goto putinhole;
            } else {
                Contents[Hole] = Contents[First];
                Hole = First;
            };
        };
        putinhole:
        Contents[Hole] = B;
        if ((CAPACITY + 1) / 2 <= Hole && Hole <= CAPACITY) {
            First = LeftChild(Hole);
            Second = RightChild(Hole);
            if (LastChild >= Second) {
                if (*Contents[Hole] < *Children[Second]->Look()
                    || *Contents[Hole] < *Children[First]->Look()) {
                    if (*Children[First]->Look()
                        > *Children[Second]->Look()) {
                        B = Children[First]->Swap(Contents[Hole]);
                        Contents[Hole] = B;
                    } else {
                        B = Children[Second]->Swap(Contents[Hole]);
                        Contents[Hole] = B;
                    };
                };
            };
            if (LastChild == First) {
                if (*Contents[Hole] < *Children[First]->Look()) {
                    B = Children[First]->Swap(Contents[Hole]);
                    Contents[Hole] = B;
                };
            };
        };
        return Result;
    }

///////////////////////////////////////////////////
    template<class T, int CAPACITY>
    T *
    SubHeap<T, CAPACITY>::Look() {
        Error(this->Number == 0, "Looking at empty heap");
        return Contents[1];
    }
///////////////////////////////////////////////////

    template<class T, int CAPACITY>
    T *
    SubHeap<T, CAPACITY>::Swap(T *B) {
        T *Result = Contents[1];
        int Hole = 1;
        int First = 2;
        int Second = 3;
        while (Second <= this->Number) {
            if ((*B > *Contents[First])
                && (*B > *Contents[Second])) {
                goto putinhole;
            } else {
                if (*Contents[First] > *Contents[Second]) {
                    Contents[Hole] = Contents[First];
                    Hole = First;
                    First = 2 * Hole;
                    Second = First + 1;
                } else {
                    Contents[Hole] = Contents[Second];
                    Hole = Second;
                    First = 2 * Hole;
                    Second = First + 1;
                };
            };
        };
        if (First == this->Number - 1) {
            if (*B > *Contents[First]) {
                goto putinhole;
            } else {
                Contents[Hole] = Contents[First];
                Hole = this->Number - 1;
            };
        };
        putinhole:
        Contents[Hole] = B;
        if ((CAPACITY + 1) / 2 <= Hole && Hole <= CAPACITY) {
            First = LeftChild(Hole);
            Second = RightChild(Hole);
            if (LastChild >= Second) {
                if (*Contents[Hole] < *Children[Second]->Look()
                    || *Contents[Hole] < *Children[First]->Look()) {
                    if (*Children[First]->Look()
                        > *Children[Second]->Look()) {
                        B = Children[First]->Swap(Contents[Hole]);
                        Contents[Hole] = B;
                    } else {
                        B = Children[Second]->Swap(Contents[Hole]);
                        Contents[Hole] = B;
                    };
                };
            };
            if (LastChild == First) {
                if (*Contents[Hole] < *Children[First]->Look()) {
                    B = Children[First]->Swap(Contents[Hole]);
                    Contents[Hole] = B;
                };
            };
        };
        return Result;
    }

///////////////////////////////////////////////////
    template<class T, int CAPACITY>
    Boolean
    SubHeap<T, CAPACITY>::Saturated()
    const {
        if (this->Number != CAPACITY) return False;
        if (LastChild < 0) return True;
        if (LastChild != CAPACITY) return False;
        Boolean Return = True;
        for (int i = 0; i < CAPACITY + 1; i++) {
            Return = (Boolean) (Return & Children[i]->Saturated());
        };
        return Return;
    }

////////////////////////////////////////////////////
    template<class T, int CAPACITY>
    T *
    SubHeap<T, CAPACITY>::Bottom() {
        Error(this->Number == 0, "error:Bottom of empty subheap");
        if (ActiveChild >= 0) {
            T *Return = Children[ActiveChild]->Bottom();
            if (Children[ActiveChild]->Size() == 0) {
                delete Children[ActiveChild];
                ActiveChild--;
                LastChild--;
            };
            return Return;
        } else {
            T *Return = Contents[this->Number];
            this->Number--;
            return Return;
        };
    }
////////////////////////////////////////////////////


    template<class T, int CAPACITY>
    void
    SubHeap<T, CAPACITY>::operator+=(T *t) {
        T *NewT;
        int Hole;
        if (ActiveChild >= 0) {
            if (Children[ActiveChild]->Saturated()) {
                ActiveChild++;
                ActiveChild %= (CAPACITY + 1);
                if (ActiveChild > LastChild) {
                    LastChild = ActiveChild;
                    Children[ActiveChild] = new SubHeap<T, CAPACITY>;
                    Error(!Children[ActiveChild], "heap:allocation failed");
                };
            };
            *Children[ActiveChild] += t;
            if (*Children[ActiveChild]->Look() > *Contents[FatherOfChild(ActiveChild)]) {
                NewT = Children[ActiveChild]->Swap(Contents[FatherOfChild(ActiveChild)]);
                Hole = FatherOfChild(ActiveChild);
            } else {
                return;
            };
        } else {
            if (this->Number == CAPACITY) {
                ActiveChild = LastChild = 0;
                Children[ActiveChild] = new SubHeap<T, CAPACITY>;
                Error(!Children[ActiveChild], "heap:allocation failed");
                *Children[ActiveChild] += t;
                if (*t > *Contents[FatherOfChild(ActiveChild)]) {
                    NewT = Children[ActiveChild]->Swap(Contents[FatherOfChild(ActiveChild)]);
                    Hole = FatherOfChild(ActiveChild);
                } else {
                    return;
                };
            } else {
                this->Number++;
                NewT = t;
                Hole = this->Number;
            };
        };
        int Father = Hole / 2;
        while (Father > 0) {
            if (*Contents[Father] > *NewT) {
                break;
            } else {
                Contents[Hole] = Contents[Father];
                Hole = Father;
                Father = Hole / 2;
            };
        };
        Contents[Hole] = NewT;
    }

////////////////////////////////////////////////////
    template<class T, int CAPACITY>
    void
    SubHeap<T, CAPACITY>::Clear() {
        int i;
        for (i = 0; i <= LastChild; i++) {
            Children[i]->Clear();
            delete Children[i];
        };
        for (i = 1; i <= this->Number; i++) {
            delete Contents[i];
        };
        ActiveChild = -1;
        LastChild = -1;
        this->Number = 0;
    }

////////////////////////////////////////////////////
    template<class T, int CAPACITY>
    void
    SubHeap<T, CAPACITY>::Print()
    const {
        int i;
        for (i = 1; i <= this->Number; i++) {
            ::std::cout << i << " ";
            ::std::cout << Contents[i]->AbsoluteError() << ::std::endl;
        };
        ::std::cout << "---------------------------------\n";
        for (i = 0; i <= LastChild; i++) {
            ::std::cout << "Child" << i << ::std::endl;
            Children[i]->Print();
        };
    }

///////////////////////////////////////////////////
    template<class T, int CAPACITY>
    int
    SubHeap<T, CAPACITY>::FatherOfChild(int i)
    const {
        return i / 2 + (CAPACITY + 1) / 2;
    }

///////////////////////////////////////////////////
    template<class T, int CAPACITY>
    int
    SubHeap<T, CAPACITY>::LeftChild(int i)
    const {
        return 2 * (i - (CAPACITY + 1) / 2);
    }

//////////////////////////////////////////////////
    template<class T, int CAPACITY>
    int
    SubHeap<T, CAPACITY>::RightChild(int i)
    const {
        return LeftChild(i) + 1;
    }
////////////////////////////////////////////////////

///HEAP

////////////////////////////////////////////////////
    template<class T>
    Heap<T>::Heap()
            :Set<T>() {
    }

////////////////////////////////////////////////
    template<class T>
    T *
    Heap<T>::Look() {
        return TheSubHeap.Look();
    }
///////////////////////////////////////////////////

    template<class T>
    T *
    Heap<T>::Get() {
        Error(this->Number == 0, "error:get from empty heap");
        this->Number--;
        return TheSubHeap.Get();
    }

///////////////////////////////////////////////////
    template<class T>
    void
    Heap<T>::operator+=(T *t) {
        this->Number++;
        TheSubHeap += t;
    }

////////////////////////////////////////////////////
    template<class T>
    void
    Heap<T>::Clear() {
        this->Number = 0;
        TheSubHeap.Clear();
    }

////////////////////////////////////////////////////
    template<class T>
    void
    Heap<T>::operator+=(Heap<T> &h) {
        int n = h.Number;
        for (int i = 0; i < n; i++) {
            T *R = h.Get();
            operator+=(R);
            delete R;
        };
    }

///////////////////////////////////////////////////
    template<class T>
    void
    Heap<T>::Print()
    const {
        ::std::cout << "Heap" << ::std::endl;
        ::std::cout << "this->Number Of Elements " << this->Number << ::std::endl;
        TheSubHeap.Print();
    }

//////////////////////////////////////////////////
    template<class T>
    Heap<T>::~Heap() {
        Clear();
    }
//////////////////////////////////////////////////
} // cubpackpp
