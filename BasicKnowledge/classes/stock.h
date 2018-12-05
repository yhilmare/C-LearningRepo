//
// Created by Administrator on 2018/12/5.
//

#ifndef BASICKNOWLEDGE_STOCK_H
#define BASICKNOWLEDGE_STOCK_H

#include <string>
#include <iostream>

class Stock{
private:
    static const int ArraySize = 15;//使用静态const变量
    enum egg{five=12};
    double array[five];
    int *p = NULL;
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){//在类中定义的方法默认都是内联的，
        total_val = shares * share_val;
    }
    void pri_func();//当然也可以将这种内联方法显式定义出来
public:
    Stock(const std::string &co, long n, double pr){//这个构造函数使用隐式内联形式定义
        if (n < 0){
            std::cout << "Number of shares can not be negative; "
                      << company << " shares set to 0.\n";
        }else{
            shares = n;
        };
        share_val = pr;
        set_tot();
        p = new int[20];
    }
    Stock(const std::string &co);//这个函数使用显式内联形式定义
    Stock(const std::string &co, long n);//这个构造函数使用非内联形式定义
    Stock(){}//如果类中定义了其他的构造函数，那么就必须显示定义一个默认构造函数
    ~Stock();//析构函数，这种函数必须声明为public且只能被定义一次，不可重载
    void acquire(const std::string &co, long n, double pr);//也可以使用普通的非内联方式定义
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock& topval(const Stock &s1) const;
};

inline void Stock::pri_func() {//显式定义内联方法，内联方法的定义要求在每个使用它的程序文件中都定义一次，那么在头文件中定义就非常合适了。
    using std::cout;
    using std::endl;
    cout << "This is inline function" << endl;
}
inline Stock::~Stock() {
    using std::cout;
    if (p){
        cout << "Delete *p, ";
        delete [] p;
    }
    cout << "Bye " << company << std::endl;
}
inline Stock::Stock(const std::string &company) {
    this->company = company;
    shares = 0;
    share_val = 0.0;
    set_tot();
    p = new int[20];
}
#endif //BASICKNOWLEDGE_STOCK_H
