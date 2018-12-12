//
// Created by Administrator on 2018/12/12.
//

#include "abc.h"
#include <iostream>

namespace abc_example{
    Person::Person(const std::string &name, int age, abc_example::Person::gender gen, int height) {
        this->name = name;
        this->age= age;
        this->gen = gen;
        this->height = height;
    }
    void Person::show_name() const {
        cout << "This is a person, name is " << name << endl;
    }
    void Person::func() const {
        cout << "This is Person's func()" << endl;
    }
    Doctor::Doctor(const std::string &name, int age, int height, int level,
                   int salary, abc_example::Person::gender gen): Person(name, age, gen, height) {
        this->salary = salary;
        this->level = level;
    }
    void Doctor::show_name() const {
        cout << "This is a Doctor" << endl;
    }
    void Doctor::show_type() const {
        cout << "type is Dcotor" << endl;
    }
    void Doctor::show_level() {
        cout << "Doctor's level is " << level << endl;
    }
    void Doctor::func(string name) const {
        cout << "This is Doctor's func()" << endl;
    }
}