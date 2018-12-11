//
// Created by Administrator on 2018/12/11.
//

#ifndef BASICKNOWLEDGE_MANAGER_H
#define BASICKNOWLEDGE_MANAGER_H

#include "Person.h"
using namespace std;

class Manager: public Person{
private:
    int salary;
public:
    string name;
    Manager(const string &name, p_gender gen, int age, int salary);
    void get_salary();
    void func();
    virtual void func_1(string name);
};


#endif //BASICKNOWLEDGE_MANAGER_H
