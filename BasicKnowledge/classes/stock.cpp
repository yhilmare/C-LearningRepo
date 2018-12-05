//
// Created by Administrator on 2018/12/5.
//
#include <iostream>
#include "stock.h"
#include <string>

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
void Stock::show() {
    std::cout << "Company: " << company
         << " Shares: " << shares << std::endl
         << " Shares Price: $" << share_val
         << " Total Worth: $" << total_val << std::endl;
}