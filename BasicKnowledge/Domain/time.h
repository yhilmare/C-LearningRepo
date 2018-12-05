//
// Created by Administrator on 2018/12/5.
//

#ifndef BASICKNOWLEDGE_TIME_H
#define BASICKNOWLEDGE_TIME_H


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
    Time sum(const Time &t) const;
    void show() const;
};


#endif //BASICKNOWLEDGE_TIME_H
