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
    void set_tot(){//在类中定义的方法默认都是内联的，
        total_val = shares * share_val;
    }
    void pri_func();//当然也可以将这种内联方法显式定义出来

public:
    void acquire(const std::string &co, long n, double pr);//也可以使用普通的非内联方式定义
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

inline void Stock::pri_func() {//显式定义内联方法，内联方法的定义要求在每个使用它的程序文件中都定义一次，那么在头文件中定义就非常合适了。
    using std::cout;
    using std::endl;
    cout << "This is inline function" << endl;
}
#endif //BASICKNOWLEDGE_STOCK_H
