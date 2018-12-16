//
// Created by Administrator on 2018/12/16.
//

#include "Student.h"
#include <iostream>
using namespace std;
double Student::Average() {
    if (valarray::size() > 0){
        return valarray::sum() / valarray::size();
    }else{
        return 0;
    }
}

double& Student::operator[](int i) {
    return valarray::operator[](i);
}

double Student::operator[](int i) const {
    return valarray::operator[](i);
}

const std::string& Student::Name() const {
    return (const string &)*this;
}

std::ostream &operator<<(std::ostream &os, const Student &s){
    os << (const string &)s;
    s.array_out(os);
    return os;
}

std::istream &getline(std::istream &in, Student &s){
    in >> s;
    return in;
}
std::ostream& Student::array_out(std::ostream &os) const {
    int i;
    int limit = valarray::size();
    if (limit > 0){
        for (i = 0; i < limit; i ++){
            os << valarray::operator[](i) << " ";
            if (i % 5 == 4){
                os << endl;
            }
        }
        if (i % 5 == 0){
            os << endl;
        }
    }else{
        os << "empty array";
    }
    return os;
}
std::istream &operator>>(std::istream &in, Student &s){
    string tmp;
    in >> tmp;
    s = Student(tmp);
    return in;
}
