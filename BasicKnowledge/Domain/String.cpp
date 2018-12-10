//
// Created by Administrator on 2018/12/7.
//

#include "String.h"
#include <iostream>
#include <cstring>

int String::num_strings = 0;
String::String() {
    num_strings ++;
    len = 0;
    p = new char[1];
    p[0] = 0;
}
String::String(char *str) {
    num_strings ++;
    len = strlen(str);
    p = new char[len + 1];
    strcpy(p, str);
}
String::String(const String &obj) {
    num_strings ++;
    len = strlen(obj.p);
    p = new char[len + 1];
    strcpy(p, obj.p);
}
String::~String() {
    num_strings --;
    delete []p;
}
String String::operator+(const String &obj) {
    int tmp_len = strlen(p) + strlen((obj.p));
    char *param = new char[tmp_len + 1];
    for (int i = 0; i < tmp_len; i ++){
        if (i < strlen(p)){
            param[i] = p[i];
        }else{
            param[i] = obj.p[i - strlen(p)];
        }
    }
    param[tmp_len] = 0;
    String result = String(param);
    delete []param;
    return result;
}
String& String::operator=(const String &obj) {
    if (this == &obj){
        return *this;
    }
    delete []p;
    len = strlen(obj.p);
    p = new char[len + 1];
    strcpy(p, obj.p);
    return *this;
}
char& String::operator[](int index) const{
    return p[index];
}
bool operator<(const String &p1, const String &p2){
    return (strcmp(p1.p, p2.p) < 0);
}
bool operator>(const String &p1, const String &p2){
    return (strcmp(p1.p, p2.p) > 0);
}
bool operator==(const String &p1, const String &p2){
    return (strcmp(p1.p, p2.p) == 0);
}

std::ostream &operator<<(std::ostream &os, const String &obj){
    os << obj.p;
    return os;
}
std::istream &operator>>(std::istream &is, String &obj){
    char tmp_str[String::CIN_LIMIT];
    is.get(tmp_str, String::CIN_LIMIT);
    if (is){
        delete []obj.p;
        obj.len = strlen(tmp_str);
        obj.p = new char[obj.len + 1];
        strcpy(obj.p, tmp_str);
    }
    while (is && is.get() != '\n'){
        continue;
    }
    return is;
}

int String::how_many() {
    return num_strings;
}