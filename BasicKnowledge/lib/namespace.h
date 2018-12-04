//
// Created by Administrator on 2018/12/4.
//

#ifndef BASICKNOWLEDGE_NAMESPACE_H
#define BASICKNOWLEDGE_NAMESPACE_H
#include <string>
namespace Jill{
    std::string name1 = "Jill";
    void func();
}
namespace Jill{
    void func(){
        using namespace std;
        cout << "This is in Jill::func" << endl;
    }
}
namespace ilmare{
    using Jill::name1;
    using Jill::func;
    std::string name = "ilmare";
    std::string fetch(std::string name1){
        using namespace std;
        cout << "This is in ilmare::fetch " + name1 + " " + name << endl;
    }
    void func_1();
    namespace ilmare_c{
        void func(){
            using namespace std;
            cout << "This is in ilmare::ilmare_c::func" << endl;
        }
    }
}
#endif //BASICKNOWLEDGE_NAMESPACE_H
