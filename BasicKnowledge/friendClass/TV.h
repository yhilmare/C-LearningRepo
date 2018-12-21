//
// Created by Administrator on 2018/12/21.
//

#ifndef BASICKNOWLEDGE_TV_H
#define BASICKNOWLEDGE_TV_H

#include <iostream>

template <class T> class TV;

class Remote_1{
public:
    template <class T> void func(TV<T> &tv);
};

template <class T> class TV {
public:
    friend class Remote;
    template <class V>friend void Remote_1::func(TV<V> &tv);
private:
    void getname();
};

template <class T> void TV<T>::getname() {
    using namespace std;
    cout << "This is TV::getname()" << endl;
}

class Remote{
public:
    template <class T> void friendfunc(TV<T> &tv);
};

template <class T> void Remote_1::func(TV<T> &tv) {
    tv.getname();
}

template <class T> void Remote::friendfunc(TV<T> &tv) {
    tv.getname();
}

#endif //BASICKNOWLEDGE_TV_H
