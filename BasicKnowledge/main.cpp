#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using std::cout;
using std::cin;

void Chapter2();
void Chapter3();
void Chapter4();


int main() {
//    Chapter2();
//    Chapter3();
    Chapter4();
    return 0;
}

void Chapter4(){
    using namespace std;

    //数组
    int array[4] = {1,2,3,5};
    for (int i = 0; i < 4; i ++){
        cout << array[i] << endl;
    }
    int a[5] = {1, 2};//若只对数组的一部分赋值，则其余部分为0
    for (int i = 0; i < 5; i ++){
        cout << a[i] << endl;
    }
    int b[] = {1, 2, 5, 6, 9, 85};
    int count = sizeof(b) / sizeof(int);
    for (int i = 0; i < count; i ++){
        if (i < count - 1){
            cout << b[i] << " - ";
        }else{
            cout << b[i] << endl;
        }
    }
    //字符串
    char str[] = "I love my country";
    cout << str << endl;
    char str1[] = {'I', ' ', 'l', 'o', 'v', 'e', ' ', 'm', 'y', ' ', 'c', 'o', 'u', 'n', 't', 'r', 'y', 0};
    cout << str1 << endl;
    char str2[8] = {'I', ' ', 'l', 'o', 0, 'v', 'e', ' '};
    cout << str2 << endl;
    /*
     * 传统的cin输入以空格为输入分割，若要输入的一个字符串中带有空格，则不能很好地录入，
     * 只能录入空格前的字符串，空格后的字符串会被缓存到输入队列中供后面的输入使用
     * */
//    const int size = 20;
//    char name[size];
//    char desert[size];
//    cout << "Enter your name: " << endl;
//    cin >> name;
//    cout << "Enter your favourite desert:" << endl;
//    cin >> desert;
//    cout << "I have some delicious " << desert << " for you, " << name << endl;

//    char str3[30];
//    cin.getline(str3, 30);//一共两个参数，第一个参数说明要读入的目标字符串，第二个参数说明要读入的长度，以换行Enter为结尾，不保留换行符
//    cout << str3 << endl;
//    char name1[30];
//    char name2[30];
//    cin.getline(name1, 30).getline(name2, 30);
//    cin.get(name1, 30).get();
    /*
     * 这样是由于cin.get函数不接受换行符，因此换行符保留在输入缓冲里，
     * 当下一个输入到来时就会将这个换行符作为第一个输入从而导致错误，因此用一个cin.get在这里接住这个换行符。
     * */
//    cin.get(name2, 30);
//    cout << name1 << name2 << endl;

    //string类
//    string str4 = "I love my country";
//    str4 = {"I am Chinese\n"};//不同的string初始化方式
//    string str5{"I love my country"};
//    cout << str4 << " - " << str4.size() << " - " << str4.length() << endl;
//    cout << str4 + str5 << endl;
//
//    char charr[20];
//    cout << "Length of string in charr before input: "
//         << strlen(charr) << endl;
//    string str6;
//    getline(cin, str6);//一种新的string类型的输入方法
//    cout << str6 << endl;
//
//    string str7 = u8"I am a Chinese, and I love my country";//使用UTF-8编码
//    cout << str7 << endl;

    cout << R"(I am a Chinese, \nand I love my Country)" << endl;//禁止转义
    cout << R"asd((Please tell my who yu are), I love you)asd" << endl;//看书吧，p88有解释，这里主要是为了解决字符串中带括号的情况

    //结构体
    struct inflatable{
        std::string name;
        float volumn;
        double price;
    };
    inflatable obj = {"David", 20, 19.98};
    cout << obj.name << " - " << obj.price << " - " << obj.volumn << endl;


    inflatable objs[2] = {
            {
                "David",
                56,
                15.69
            },{
                "Smith",
                96,
                13.59
            }
    };
    cout << objs[0].name << endl;

    //共用体
    struct widget{
        std::string name;
        int type;
        union {
            /*
             * 共用体，用于一个字段的类型可能是多种的情况下，
             * 例如这个例子中id的类型可能是一个长整形，
             * 也可能是一个字符数组型，这里就可以用到共用体。
             * */
            long id_num;
            char id_str[20];
        };
    };
    widget obj1[2] = {
            {
                "BMW",
                20
            }, {
                "AUTO",
                56
            }
    };
//    for (int i = 0; i < 2; i ++){
//        if (obj1[i].type == 20){
//            obj1[i].id_num = 15464;
//        }else{
//            cin >> obj1[i].id_str;
//        }
//    }
//    cout << obj1[1].id_str << endl;

    //枚举类型
    enum spectrum {
        /*
         * 枚举类型本质上还是整形，从0开始递增
         * */
        red,
        orange,
        yellow,
        green,
        blue,
        violet = 100,
        indigo,
        ultraviolet
    };
    spectrum band;
    int color = blue + 1;
    cout << color << endl;
    cout << blue << " - " << ultraviolet << endl;
    band = spectrum(112);//枚举值由于还是以int型存在的，因此也可以将枚举值赋值成为期不存在的枚举值，只要不超过其最大上限和小于最小下限。
    cout << band << endl;

    //指针
    double doughnut_1 = 15.69;
    int doughnut = 20;
    int *doughnut_p = &doughnut;
    cout << doughnut_p << " - " << &doughnut_1 << " - " << &doughnut << endl;

    int *p_int = (int *)malloc(sizeof(int));
    double *p_double = new double;
    *p_int = 25;
    *p_double = 15.56;
    cout << *p_int << " - " << *p_double << endl;
    delete p_int;
    delete p_double;

    int *p_array = new int[3];
    p_array[0] = 120;
    p_array[1] = 128;
    p_array[2] = 133;
    cout << (*p_array) << " -> " << *(p_array + 1) << " -> " << p_array[2] << endl;
    delete [] p_array;

    int a_array[3] = {155, 122, 145};
    int *a_p = a_array;
    int *a_p_1 = &a_array[0];
    cout << sizeof(a_array) << " -> " << sizeof(a_p) << endl;//对数组和指针使用sizeof函数，前者将得到的是数组的大小，而后者得到的是指针的大小
    cout << a_p[0] << " -> " << *(a_p + 1) << " -> " << *(a_p_1 + 2) << endl;

    //指针与数组
    char animal[20] = "animal";
    /*
     * 就如同cout << "bear"可以被打印出来一样，字符串字面量代表着该字符串的首地址，
     * 因此这样的赋值是可以接受的，而int *a = 25这样的操作是禁止的，因为a并没有被初始化。
     * */
    const char *bear = "bear";
    char *ps;
    ps = animal;
    cout << animal << " - " << ps << endl;
    cin >> animal;
    cout << animal << " - " << ps << endl;
    cout << "animal at " << (int *)animal << endl;
    cout << "ps at " << (int *)ps << endl;

    struct stu {
        std::string name;
    };
    stu oj1, oj2, oj3;
    oj1.name = "Daivd";
    oj2.name = "Smith";
    oj3.name = "Ann";
    stu *p[3] = {&oj1, &oj2, &oj3};
    stu **pStu = p;//两个*号通常都是指向指针数组的指针，一定要记住
    cout << pStu[0]->name << " -> " << pStu[1]->name << " -> " << pStu[2]->name << endl;
    cout << pStu[0] << " -> " << pStu[1] << " -> " << pStu[2] << endl;

    //vector与array
    vector<int> int_v(3);//这就是vector模板类的初始化方式，后面的括号是该vector的容量，可以用变量代替，意味着其大小在程序运行时时可变的。
    std::array<int, 3> int_a = {1, 2, 3};
    for (int i = 0; i < int_v.capacity(); i ++){
        int_v[i] = i;
    }
    for (int i = 0; i < int_a.size(); i ++){
        int_a[i] = i;
    }
    cout << int_v[2] << endl;

};

void Chapter3(){
    /*
     * 第三章的部分代码
     * */
    using namespace std;//可以在函数内部使用这条using编译指令，作用域为该函数体内部。
    cout << "max char is " << CHAR_MAX << ", max int is " << INT_MAX << ", short int is " << SHRT_MIN << endl;

    int enums{5}, ban = {20};//c++11中的一种赋值方法。
    cout << enums << " " << ban << endl;

    int a = 91, b = 042, c = 0x1a;//不同进制的整形赋值
    cout << a << " " << b << " " << c << endl;
    cout << hex << b << endl;//可以通过·传入hex，oct和dec等值来控制输出数字的进制
    cout << sizeof(long long) << endl;
    a = 2220UL;
    cout << dec << a << " " << sizeof(2220uL) << endl;

    char ch = 77;
    cout << "This input char is " << ch << endl;

    cout.put('2');//这只是一个历史原因，并不常用
    cout << '$' << endl;
    cout << "Let them eat g\u00E2teau" << endl;
    cout << sizeof(wchar_t) << endl;
    char16_t ann = u'\u00e2';
    cout << "ann is " << ann << endl;

    const int Month = 12;
    cout << Month << endl;

    float e = 1.0;
    float f = 3.0;
    cout.setf(ios_base::fixed, ios_base::floatfield);//用于强制规定浮点数的打印位数，防止把过大的浮点数打印成E表示的浮点数
    cout << e / f << endl;

    int thorn = 3;
    double thorn_d = static_cast<double>(thorn);//强制转换
    cout << thorn_d << endl;
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