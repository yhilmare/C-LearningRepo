//
// Created by Administrator on 2018/12/17.
//
#include "StackTemp.h"

void show(const StackTemp<int> &t){
    using namespace std;
    cout << "This is friend show()" << endl;
}

void show(const StackTemp<char *> &t){
    using namespace std;
    cout << "This is friend show()" << endl;
}
