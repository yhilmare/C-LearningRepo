//
// Created by Administrator on 2018/12/11.
//

#ifndef BASICKNOWLEDGE_MANAGER_H
#define BASICKNOWLEDGE_MANAGER_H

#include "Person.h"
using namespace std;

class Manager: public Person{
protected:
    string test = "Manager";
private:
    int salary;
    char *label;
public:
    string name;
    string str = "sub";
    Manager(){
        this->label = new char[20];
    }
    Manager(const Manager &m): Person(m){
        this->label = new char[20];
    }
    Manager &operator=(const Manager &m){
        if (this == &m){
            return *this;
        }
        Person::operator=(m);
        delete []this->label;
        this->label = new char[20];
        strcpy(this->label, m.label);
        this->salary = m.salary;
        return *this;
    }
    Manager(const string &name, p_gender gen, int age, int salary);
    void get_salary();
    void func();
    virtual void func_1(string name);
    virtual void func_1();

    virtual ~Manager(){
        delete [] this->label;
    }
};


#endif //BASICKNOWLEDGE_MANAGER_H
