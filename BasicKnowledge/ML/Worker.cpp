//
// Created by Administrator on 2018/12/17.
//

#include "Worker.h"
#include <iostream>
using namespace std;

Worker::~Worker() {}

void Worker::Data() const {
    cout << "Name" << fullname << endl;
    cout << "job ID " << id << endl;
}

void Worker::Get() {
    getline(cin, fullname);
    cout << "Enter job ID:" << endl;
    cin >> id;
    while(cin && cin.get() != '\n');
}

void Waiter::Data() const {
    cout << "panache is " << panache << endl;
}
void Waiter::Get() {
    cout << "Enter waiter's panache rating: " << endl;
    cin >> panache;
    while(cin && cin.get() != '\n');
}

void Waiter::show() const {
    cout << "Category waiter\n";
    Waiter::Data();
    Data();
}

void Waiter::Set() {
    cout << "Enter waiter's name";
    Waiter::Get();
    Get();
}

char *Singer::pv[VTypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
void Singer::Get() {
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < VTypes; i ++){
        cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3){
            cout << endl;
        }
    }
    if (i % 4 != 0){
        cout << '\n';
    }
    cin >> voice;
    while (cin && cin.get() != '\n');
}

void Singer::Set() {
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}
void Singer::show() const {
    Worker::Data();
    Data();
}
void Singer::Data() const {
    cout << "Vocal range: " << pv[voice] << endl;
}

void SingerWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingerWaiter::Get() {
    Singer::Get();
    Waiter::Get();
}

void SingerWaiter::show() {
    cout << "Category: sing waiter: \n";
    Worker::Data();
    Data();
}

void SingerWaiter::Set() {
    cout << "Enter sing waiter's name:\n";
    Worker::Get();
    Get();
}