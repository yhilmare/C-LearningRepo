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
    string name;
    p_gender gen;
    int age;
public:
    Person(const string &name, p_gender gen, int age);
    void get_name() const;

    friend ostream &operator<<(ostream &os, const Person &p);
};


#endif //BASICKNOWLEDGE_PERSON_H
