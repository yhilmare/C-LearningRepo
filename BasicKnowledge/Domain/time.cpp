//
// Created by Administrator on 2018/12/5.
//

#include "time.h"
#include <iostream>

Time::Time() {
    hours = minutes = 0;
}
Time::Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
}
void Time::addMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::addHr(int h) {
    hours += h;
}
void Time::reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours; + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::show() const {
    using std::cout;
    cout << hours << " hours, " << minutes << " minutes" << std::endl;
}
Time Time::operator-(double num) const {
    Time t = Time(15, 14);
    return t;
}



