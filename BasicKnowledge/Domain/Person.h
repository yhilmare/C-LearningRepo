//
// Created by Administrator on 2018/12/11.
//

#ifndef BASICKNOWLEDGE_PERSON_H
#define BASICKNOWLEDGE_PERSON_H

#include <string>
using namespace std;
enum p_gender{
    males,
    females
};
class Person {
private:
    p_gender gen;
    int age;
public:
    string name;
    Person(){
        name = string("unkonwn");
        gen = males;
        age = 0;
    }
    Person(const string &name, p_gender gen, int age);
    void get_name() const;
    virtual void func();
    virtual void func_1();

    friend ostream &operator<<(ostream &os, const Person &p);

    static void show();
};


#endif //BASICKNOWLEDGE_PERSON_H
