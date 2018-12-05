//
// Created by Administrator on 2018/12/4.
//

#ifndef BASICKNOWLEDGE_NAMESPACE_H
#define BASICKNOWLEDGE_NAMESPACE_H

#include <string>
namespace Jill{
    using namespace std;
    static int age = 15;
    void func();
}

namespace ilmare{
    using namespace std;
    void fetch(string name2);
    void func_1();
    namespace ilmare_c{
        void func();
    }
}
#endif //BASICKNOWLEDGE_NAMESPACE_H
