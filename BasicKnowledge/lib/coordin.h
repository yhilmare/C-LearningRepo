//
// Created by Administrator on 2018/12/3.
//

#ifndef BASICKNOWLEDGE_COORDIN_H
#define BASICKNOWLEDGE_COORDIN_H

#include <cmath>

struct polar{
    double distance;
    double angle;
};
struct rect{
    double x;
    double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
const int cats = 555;
#endif //BASICKNOWLEDGE_COORDIN_H
