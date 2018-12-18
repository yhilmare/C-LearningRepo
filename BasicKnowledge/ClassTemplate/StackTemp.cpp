//
// Created by Administrator on 2018/12/17.
//
#include "StackTemp.h"

void show(const StackTemp<int> &t){
    using namespace std;
    cout << "This is friend StackTemp<int> &" << endl;
}

void show(const StackTemp<char *> &t){
    using namespace std;
    cout << "show(const StackTemp<char *> &" << endl;
}

void StackTemp<char *>::show() {
    using namespace std;
    cout << "This is StackTemp<char*>::show()" << endl;
}
