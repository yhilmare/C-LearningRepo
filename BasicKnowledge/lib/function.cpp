//
// Created by Administrator on 2018/12/4.
//
#include <iostream>
#include <cmath>
#include "coordin.h"
#include "namespace.h"
#include <string>

int cat = 20;
int dog = 256;
polar rect_to_polar(rect xypos){
    using namespace std;
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}
void show_polar(polar dapos){
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees" << endl;
}

namespace Jill{
    using namespace std;
    string name = "Smith";
    void func(){
        cout << "This is in Jill::func" << endl;
    }
}

namespace ilmare{
    using Jill::name;
    void func_1(){
        cout << "This is func_1" << endl;
    }
    void fetch(std::string name2){
        cout << "This is in ilmare::fetch " + ilmare::name + " " + name2 << endl;
    }
    namespace ilmare_c{
        void func(){
            cout << "This is in ilmare::ilmare_c::func" << endl;
        }
    }
}
void Chapter9_func(){
    std::cout << "This is extern function" << std::endl;
    std::cout << ilmare::name << std::endl;
}

