//
// Created by Administrator on 2018/12/5.
//
#include <iostream>
#include "stock.h"
#include <string>

/*
 * 非内联形式定义类方法
 * */
int Stock::tmp_val = 0;
void Stock::acquire(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0){
        std::cout << "Number of shares can not be negative"
                  << company << " shares set to 0.\n";
        shares = 0;
    }else{
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price) {
    if (num < 0){
        std::cout << "Number of shares purchased can not be negative"
                  << "Transsaction is aborted. \n";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0){
        cout << "Number of shares can not be negative."
             << "Transaction is aborted.\n";
    }else if (num < shares){
        cout << "You can not sell more than you have !"
             << "Transaction is aborted. \n";
    }else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}
void Stock::show() const {
    std::cout << "Company: " << company
         << " Shares: " << shares << std::endl
         << " Shares Price: $" << share_val
         << " Total Worth: $" << total_val << std::endl;
}

Stock::Stock(const std::string &co, long n) {
    tmp_val += 1;
    std::cout << "Stock(const std::string &co, long n), company is " << company << ", tmp_val is " << tmp_val <<std::endl;
    if (n < 0){
        std::cout << "Number of shares can not be negative; "
                  << company << " shares set to 0.\n";
    }else{
        shares = n;
    };
    share_val = 0.0;
    set_tot();
    p = new char[20];
    strcpy(p, "I am a Chinese");
}

const Stock& Stock::topval(const Stock &s1) const {
    if (s1.total_val > this->total_val){
        return s1;
    }else{
        return *this;
    }
}