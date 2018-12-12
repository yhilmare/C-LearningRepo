//
// Created by Administrator on 2018/12/11.
//

#include "Manager.h"
#include <iostream>

Manager::Manager(const string &name, p_gender gen, int age, int salary): Person(name, gen, age) {
    this->salary = salary;
}

void Manager::get_salary() {
    cout << "salary is " << salary << endl;
}
void Manager::func() {
    Person::func();
    cout << "This is Manager, this is " << this << endl;
}
void Manager::func_1(string name) {
    cout << "This is Manager::func_1(), this is " << this << endl;
}
void Manager::func_1() {
    cout << "This is Manager::func_1() without name, this is " << this << endl;
}
