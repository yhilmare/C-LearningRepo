//
// Created by Administrator on 2018/12/4.
//

#ifndef BASICKNOWLEDGE_NAMESPACE_H
#define BASICKNOWLEDGE_NAMESPACE_H

#include <string>
#include <iostream>
namespace Jill{
    using namespace std;
    static int age = 15;
    const double price = 15.22;
    const static string lastName = "Smith";
    void func();
}
enum gender{
    male = 1,
    female
};
namespace ilmare{
    class Person{
    private:
        std::string name;
        int age;
        gender gen;
    public:
        Person(const std::string &name, int age, gender gen);
        Person(){
            this->name = "unknown";
            this->age = 0;
            this->gen = male;
        }
        ~Person();
        void show() const;
    };
    static Person p = Person("Ann", 25, female);
    using Jill::lastName;
    using namespace std;
    void fetch(string name2);
    void func_1();
    namespace ilmare_c{
        void func();
    }
}
inline ilmare::Person::~Person(){
    cout << "The person " << this->name << " has been destoried!!" << endl;
}
inline void ilmare::Person::show() const{
    cout << "The person " << this->name
         << "'s age is " << this->age
         << ", his/her gender is " << this->gen << endl;
}

#endif //BASICKNOWLEDGE_NAMESPACE_H
