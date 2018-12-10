//
// Created by Administrator on 2018/12/7.
//

#ifndef BASICKNOWLEDGE_STRING_H
#define BASICKNOWLEDGE_STRING_H

#include <iostream>

class String {
private:
    char *p;
    int len;
    static int num_strings;
    static const int CIN_LIMIT = 60;
public:
    String();//默认构造函数
    String(char *str);//使用字符串实例化String
    String(const String &obj);//拷贝构造函数
    ~String();//析构函数
    String operator+(const String &obj);
    String &operator=(const String &obj);
    char &operator[](int index) const;
    int get_length() const{
        return len;
    }

    friend bool operator<(const String &p1, const String &p2);
    friend bool operator>(const String &p1, const String &p2);
    friend bool operator==(const String &p1, const String &p2);
    friend std::ostream &operator<<(std::ostream &os, const String &obj);
    friend std::istream &operator>>(std::istream &is, String &obj);

    static int how_many();
};

#endif //BASICKNOWLEDGE_STRING_H
