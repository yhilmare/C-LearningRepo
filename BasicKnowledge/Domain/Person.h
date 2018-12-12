//
// Created by Administrator on 2018/12/11.
//

#ifndef BASICKNOWLEDGE_PERSON_H
#define BASICKNOWLEDGE_PERSON_H

#include <string>
#include <cstring>
#include <iostream>
using namespace std;
enum p_gender{
    males,
    females
};
class Person {
protected:
    string test = "Person";
private:
    p_gender gen;
    int age;
    char *p;
public:
    string name;
    string str = "super";
    Person(){
        name = string("unkonwn");
        gen = males;
        age = 0;
        this->p = new char[20];
        strcpy(p, "I love my country");
    }
    Person(const string &name, p_gender gen, int age);
    Person(const Person &p){
        this->name = p.name;
        this->gen = p.gen;
        this->age = p.age;
        this->p = new char[20];
        strcpy(this->p, p.p);
    }
    void get_name() const;
    Person &operator=(const Person &obj){
        if (this == &obj){
            return *this;
        }
        delete []this->p;
        this->p = new char[20];
        strcpy(this->p, obj.p);
        this->name = obj.name;
        this->gen = obj.gen;
        this->age = obj.age;
        return *this;
    }
    virtual void func();
    virtual void func_1();

    friend ostream &operator<<(ostream &os, const Person &p);

    static void show();

    virtual ~Person(){
        cout << "This is Person::~Person(), name is " << name << endl;
        delete []this->p;
    }
};


#endif //BASICKNOWLEDGE_PERSON_H
