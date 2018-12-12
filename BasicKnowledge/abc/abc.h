//
// Created by Administrator on 2018/12/12.
//

#ifndef BASICKNOWLEDGE_ABC_H
#define BASICKNOWLEDGE_ABC_H


#include <string>

namespace abc_example{
    using namespace std;
    class Person {
    protected:
        enum gender{
            male,
            female
        };
    private:
        string name;
        int age;
        gender gen;
        int height;
    public:
        Person(const string &name, int age, gender gen, int height);
        virtual void show_type() const  = 0;
        virtual void show_level() = 0;
        virtual void show_name() const;
        virtual void func() const;
    };
    class Doctor: public Person{
    private:
        int level;
        int salary;
    public:
        Doctor(const string &name, int age, int height, int level, int salary, gender gen = male);
        virtual void show_name() const;
        virtual void show_type() const;
        virtual void show_level();
        virtual void func(string p) const;
    };
}



#endif //BASICKNOWLEDGE_ABC_H
