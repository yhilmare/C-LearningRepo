//
// Created by Administrator on 2018/12/17.
//

#ifndef BASICKNOWLEDGE_STACKTEMP_H
#define BASICKNOWLEDGE_STACKTEMP_H

#include <iostream>
template <class T>
class StackTemp{
private:
    T *items;
public:
    StackTemp(int size){
        items = new T[size];
    }
    ~StackTemp(){
        delete []items;
    }
};


#endif //BASICKNOWLEDGE_STACKTEMP_H
