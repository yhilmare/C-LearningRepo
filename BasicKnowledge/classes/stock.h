//
// Created by Administrator on 2018/12/5.
//

#ifndef BASICKNOWLEDGE_STOCK_H
#define BASICKNOWLEDGE_STOCK_H

#include <string>
#include <iostream>
class Stock{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){//隐式内联函数，在每个引入了stock.h的程序文件中都会定义一次该方法，可以说是隐式去掉了inline关键字
        total_val = shares * share_val;
    }
    void pri_func();

public:
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};


#endif //BASICKNOWLEDGE_STOCK_H
