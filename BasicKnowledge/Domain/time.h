//
// Created by Administrator on 2018/12/5.
//

#ifndef BASICKNOWLEDGE_TIME_H
#define BASICKNOWLEDGE_TIME_H

#include <iostream>
class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int hours, int minutes);
    void addHr(int h);
    void addMin(int m);
    void reset(int h = 0, int m = 0);
    Time operator+(const Time &t) const;
    Time operator-(double num) const;
    void show() const;
    friend Time operator*(double a, const Time &b);
    friend std::ostream &operator<<(std::ostream &os, const Time &t){
        t.show();
        return os;
    }
};

inline Time operator*(double a, const Time &b){
    using std::cout;
    using std::endl;
    cout << "This is in friend" << endl;
    Time result;
    long totalminutes = b.hours * a * 60 + b.minutes * a;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}
#endif //BASICKNOWLEDGE_TIME_H
