//
// Created by Administrator on 2018/12/4.
//

#ifndef BASICKNOWLEDGE_NAMESPACES_H
#define BASICKNOWLEDGE_NAMESPACES_H

#include <string>
namespace Jill{
    using namespace std;
    string name1 = "Jill";
    void func();
}
namespace Jill{
    using namespace std;
    void func(){
        cout << "This is in Jill::func" << endl;
    }
}
namespace ilmare{
    using Jill::name1;
    using Jill::func;
    std::string name = "ilmare";
    std::string fetch(std::string name1){
        std::cout << "This is in ilmare::fetch " + name1 + " " + name << endl;
    }
    void func_1();
    namespace ilmare_c{
        void func(){
            cout << "This is in ilmare::ilmare_c::func" << endl;
        }
    }
}
#endif //BASICKNOWLEDGE_NAMESPACES_H
