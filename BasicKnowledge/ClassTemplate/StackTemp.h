//
// Created by Administrator on 2018/12/17.
//

#ifndef BASICKNOWLEDGE_STACKTEMP_H
#define BASICKNOWLEDGE_STACKTEMP_H

#include <iostream>

template <class T>
void show_1(T &);

template <class T>
class StackTemp{
private:
    T *items;
public:
    StackTemp(int size){
        items = new T[size];
    }
    ~StackTemp(){
        delete []items;
    }
    template<class V>
    void getname(V v);

    friend void show(const StackTemp<T> &s);

    friend void show_1<>(StackTemp<T> &);

    template<class V>
    friend void show_2(V &v);

    void show_3(const StackTemp<T> &);
    void show();
};

template <class T>
void StackTemp<T>::show() {
    using namespace std;
    cout << "This is StackTemp<T>::show()" << endl;
}

template <class T>
void StackTemp<T>::show_3(const StackTemp<T> &t) {
    using namespace std;
    cout << "This is StackTemp<T>::show_3(StackTemp<T> &)" << endl;
}
template <class V>
void show_2(V &v){
    using namespace std;
    cout << "This is show_2()" << endl;
}

template <class T>
void show_1(StackTemp<T> &t){
    using namespace std;
    cout << "This is show_1" << endl;
}

template <class T>
template <class V>
void StackTemp<T>::getname(V v) {
    using namespace std;
    cout << "This other" << endl;
}

template<>//显式具体化
class StackTemp<char *>{
private:
    char **items;
public:
    StackTemp(int size){
        items = new char *[size];
    }
    ~StackTemp(){
        delete []items;
    }
    template <class V>
    void getname(char *t, V &v);
    friend void show(const StackTemp &t);

    void show();
};

template <class V>
void StackTemp<char *>::getname(char *s, V &v) {
    using namespace std;
    cout << "Hello,world" << endl;
}
#endif //BASICKNOWLEDGE_STACKTEMP_H
