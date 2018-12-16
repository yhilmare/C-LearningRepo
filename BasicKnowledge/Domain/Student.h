//
// Created by Administrator on 2018/12/16.
//

#ifndef BASICKNOWLEDGE_STUDENT_H
#define BASICKNOWLEDGE_STUDENT_H

#include <string>
#include <valarray>

class Student: private std::string, private std::valarray<double>{
private:
    std::ostream &array_out(std::ostream &os) const;
public:
    Student(): std::string("Null Student"), valarray(){}
    explicit Student(const std::string &name):std::string(name), valarray(){}
    explicit Student(int n): std::string("Null student"), valarray(n){}
    Student(const std::string &name, int n): std::string(name), valarray(n){}
    Student(const std::string &name, const valarray &array): std::string(name), valarray(array){}
    Student(char *s, double *p, int n): std::string(s), valarray(p, n){}

    ~Student(){}

    double Average();
    double &operator[](int i);
    double operator[](int i) const;
    const std::string &Name() const;

    friend std::ostream &operator<<(std::ostream &os, const Student &s);
    friend std::istream &getline(std::istream &in, Student &s);
    friend std::istream &operator>>(std::istream &in, Student &s);
};


#endif //BASICKNOWLEDGE_STUDENT_H
