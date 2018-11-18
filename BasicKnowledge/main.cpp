#include <iostream>
#include <cmath>
#include <climits>

using std::cout;
using std::cin;

void Chapter2();
void Chapter3();

int main() {
//    Chapter2();
    Chapter3();
    return 0;
}

void Chapter3(){
    /*
     * 第三章的部分代码
     * */
    using namespace std;//可以在函数内部使用这条using编译指令，作用域为该函数体内部。
    cout << "max char is " << CHAR_MAX << ", max int is " << INT_MAX << ", short int is " << SHRT_MIN << endl;

    int enums{5}, ban = {20};//c++11中的一种赋值方法。
    cout << enums << " " << ban << endl;
}
void Chapter2(){
    /*
     * 第二章的部分代码
     * */
    int count=15;
    for (int i = 0; i < count; i ++){
        for (int j = 0; j < i; j ++){
            cout << "*";
        }
        cout << std::endl;
    }
    cout << "Hello,world" << std::endl;
    cout << "It is a fine day today "
         << "I love my country" << std::endl;
//    int a,b;
//    cin >> a
//        >> b;
//    cout << sqrt(6.25) << a << b << std::endl;
    return;
}