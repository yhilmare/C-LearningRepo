//
// Created by Administrator on 2018/12/7.
//

#include "String.h"
#include <iostream>


String::String(int p1, double p2, Stock &p3): a(p1), b(p2), t(p3) {
    using namespace std;
    cout << a << " " << b;
}