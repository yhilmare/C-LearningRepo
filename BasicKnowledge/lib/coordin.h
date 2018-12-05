//
// Created by Administrator on 2018/12/3.
//

#ifndef BASICKNOWLEDGE_COORDIN_H
#define BASICKNOWLEDGE_COORDIN_H

#include <cmath>
#include <iostream>
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
inline void inline_function(){
    std::cout << "This is an inline function" << std::endl;
}
#endif //BASICKNOWLEDGE_COORDIN_H
