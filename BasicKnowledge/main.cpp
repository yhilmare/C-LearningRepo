#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <ctime>
#include <cctype>
#include <fstream>

using std::cout;
using std::cin;

void Chapter2();
void Chapter3();
void Chapter4();
void Chapter5();
void Chapter6();
void Chapter7();
void Chapter8();

const std::string inputPath = R"(F:\CLion-workspace\LICENSE)";
const std::string outputPath = R"(F:\CLion-workspace\OUTPUT\output.txt)";
int main() {
//    Chapter2();
//    Chapter3();
//    Chapter4();
//    Chapter5();
//    Chapter6();
//    Chapter7();
    Chapter8();
    return 0;
}
inline double suqare(double);//也可以使用这种声明方法
inline double square(const double x){//使用inline关键字实现内联函数
    return x * x;
}
double cube(const double &);
void swap(int &, int &);
double &modify(double &);

void printTest(int count = 11, char s = '*'){
    for (int i = 0; i < count;i ++){
        int space_count = count - i - 1;
        for (int j = 0; j < space_count; j ++){
            cout << " ";
        }
        for (int j = 0; j <= 2 * i + 1; j ++){
            if (j % 2 == 0){
                cout << s;
            }else {
                cout << " ";
            }
        }
        cout << std::endl;
    }
    for (int i = count - 2; i >= 0;i --){
        int space_count = count - i - 1;
        for (int j = 0; j < space_count; j ++){
            cout << " ";
        }
        for (int j = 0; j <= 2 * i + 1; j ++){
            if (j % 2 == 0){
                cout << s;
            }else {
                cout << " ";
            }
        }
        cout << std::endl;
    }
}
void print(char *str, int count);
void print(int count);

template <typename T>//template <class T>这样的声明在C98中定义
void Swap(T &a, T &b){
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}

void Chapter8(){
    using namespace std;
    cout << square(20) << endl;//内联函数可以加快程序的执行时间，但是会增加程序的内存开销

    int rat = 100;
    int &rodent = rat;
    rodent = 150;
    cout << "The address of rat = " << &rat << ", The address of rodent = " << &rodent << endl;

    //C++中的引用变量和原始变量仅仅是是名字不同而已，实际上他们是同一个变量，操作其中一个也会影响到另一个
    int rats = 150;
    int bunnies = 200;
    int &rodents = rats;
    cout << "rats address = " << &rats << ", rodents address = " << &rodents << endl;
    rodents = bunnies;//由于rodents是rats的引用，因此执行这一句就相当于执行rats=bunnies
    cout << "rats = " << rats << ", bunnies = " << bunnies << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats << ", bunnies address = " << &bunnies << ", rodents address = " << &rodents << endl;
    //引用变量一旦初始化，那么它就成为那个内存关联的所有变量的引用变量
    int rat_1 = 10;
    int  *p = &rat_1;
    int &rodent_1 = *p;
    int bunnies_1 = 25;
    p = &bunnies_1;
    cout << "rodent_1 = " << rodent_1 << endl;

    /*
     * 引用变量使用在函数参数传递的时候要更加小心，因为使用了引用变量声明的参数在函数中操作的实际上就是调用函数传入的那个变量，
     * 也就是说函数内部对引用变量的修改会影响到调用函数中的变量。
     * 在函数中使用引用变量作为参数有着两个主要限制：
     * 1. 首先在调用函数时一定要传入变量而不能是表达式或常量，类似于func(x + 3)或func(3)。
     * 2. 其次传入变量的类型要严格符合函数的声明的参数类型，无法进行隐式类型转换。
     * 但是如果在函数的引用变量前使用了const关键字，那么就会发生很多改变：
     * 1. 首先如果函数参数列表中使用了带有const修饰的引用变量，那么在函数中就不能对这个变量进行改变值的操作，例如赋值。
     * 2. 这样的带有const修饰的引用变量可以进行类型的隐式转换，例如声明为const double &a，在实际调用时可以传入一个int型变量。
     * 3. 这种带有const声明的引用变量还可以接收表达式传入。
     * 4. 第二，第三点的实现实际上是函数在调用时创建了一个临时变量，由于带有const的变量不允许修改（正如第一点所表述的），因此使用这种临时变量也不会引起任何问题。
     * */
    int a = 20;
    int b = 25;
    //这样的调用是禁止的，因为给引用变量赋值的是一个表达式，而不是一个变量，且引用变量没有使用const关键字修饰
    //swap(a + 20, b);
    int x = 10;
    cout << cube(x) << endl;//由于有const关键字修饰，因此支持常量，表达式赋值，且还支持隐式类型转换
    cout << cube(x + 10) << endl;

    //函数也可以返回一个变量的引用：
    double param_double = 25.6;
    /*
     * 在这里返回的是param_double变量的引用，因此当然可以对其进行赋值操作。但是如果这里返回的是一个值，那么这种语法将是错误的
     * 原因在于，如果返回的是值，那么这是一个常量，常量是不能够被赋值操作的（指针也是如此）。但是如果返回的是一个引用，那么这个引用就可以被重新赋值，
     * 而且由于函数本身返回的是param_double的引用，因此对这个引用的更改自然就反映到了param_double本身身上。
     * 如果想要禁止这种操作，需要在函数返回值前面加上const关键字，这样就无法更改了。
     * 最后：返回引用需要注意不能返回函数中的临时变量的引用，因为这种变量的生命周期只是函数执行的生命周期，在一般的以值返回的函数中还没有问题（因为这种情况下返回值是被拷贝到某个寄存器的）
     * 若是以引用返回，那么函数结束后，临时变量的内存被释放，这种引用就会失效。解决办法有两个：
     * 1. 如果函数的参数列表中有引用参数，那么返回参数列表中的引用变量。
     * 2. 如果一定要返回函数中的临时变量，那么一定要使用new关键字来动态申请内存。
     * 将一个引用变量赋值给一个普通变量无疑是非常高效的，它将直接赋值，而不会产生中间结果。
     * */
    modify(param_double) = 56.9;//
    cout << param_double << endl;

    //默认参数；函数的默认参数需要都集中在函数参数列表的右侧，不能出现默认参数和非默认参数混合排列的情况
    printTest(3, '.');

    //函数重载：关于函数重载只用知道一条：那就是编译器只使用特征标（即函数参数列表中参数的类型和排列顺序）来区分同名函数，跟函数的返回值没有关系
    print("I love you", 5);
    print(4);

    int aa = 50;
    int bb = 46;
    Swap(aa, bb);
    cout << aa << " " << bb;
}

void print(char *str, int count){
    for (int i = 0; i < count; i ++){
        cout << str << std::endl;
    }
}

void print(int count){
    for (int i = 0; i < count; i ++){
        cout << "Hello,world" << std::endl;
    }
}

double &modify(double &a){
    return a;
}
void swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = tmp;
}
double cube(const double &param){//使用了const关键字，意味着param是不可被修改的，这就杜绝了引用变量修改原值的可能
    return param * param * param;
}
void simple(int n, ...){//可变参数
    using namespace std;
    va_list lst;//获取可变参数列表
    _crt_va_start(lst, n);//告知可变参数起始位置：传入最后一个固定参数
    double a = _crt_va_arg(lst, double);//第一个可变参数
    double b = _crt_va_arg(lst, double);//第二个可变参数
    _crt_va_end(lst);//结束对可变参数的使用
    cout << a << " - " << b << endl;
}

int sumArray(int *array, int count){
    int sum = 0;
    for (int i = 0; i < count; i ++){
        array[i] = i + 1;
    }
    return sum;
}

int sumArrayRange(const int *pHead, const int *pEnd){//从数组中取一定的范围进行操作，并且强制声明为cosnt
    int sum = 0;
    for (const int *p = pHead; p != pEnd; p ++){
        sum += *p;
    }
    return sum;
}

int sumTwoDimMatrix(int p[][3], int row){
    int sum = 0;
    for (int i = 0; i < row; i ++){
        for (int j = 0; j < 3; j ++){
            sum += *(*(p + i) + j);
        }
    }
    return sum;
}

std::string show_string(std::string *str){
    std::string str1 = "I am a Chinese";
    /*
     * 虽然参数是一个string类型的指针，但是这个指针也只是原有指针的一个拷贝。
     * 把它指向别的内存地址也只是将拷贝指向别的地址，当函数结束这个拷贝也会被删除，对原有指针不会造成任何影响
     * */
    str = &str1;
    return str1;
}
void show(std::array<std::string, 4> obj){
    for (int i = 0; i < obj.size(); i ++){
        cout << obj[i] << " ";
    }
}

void modify_array(std::array<std::string, 4> *obj){
    for (int i = 0; i < (*obj).size(); i ++){
        (*obj)[i] += "-er";
    }
}

void show_vec(std::vector<int> obj){
    for (int i = 0; i < obj.size(); i ++){
        cout << obj[i] << " ";
    }
}

int recurs(int count){
    if (count == 1){
        return 1;
    }
    return count + recurs(count - 1);
}

double pam(int);
void estimate(int line, double (* )(int));
double *func1(const double *, int);
double *func2(const double *, int);
double *func3(const double *, int);
void testfuncarray(double *(*[3])(const double *, int));
void testfuncarray2(double *(*((*)[3]))(const double *, int));
void simple(int, ...);
void Chapter7(){
    using namespace std;
    simple(3, 5.6, 2.5);//传递可变参数
    /*
     * 若前面加上const关键字，则这个数组就是不可更改的,
     * 且编译器有规定，禁止将const修饰的变量赋值给非const修饰的变量，也就是说如果下面代码的array前面加上const修饰，
     * 则下面的sumArray函数调用将报错，因为sumArray的参数列表中的array前面没有加const修饰符
     * */
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << sumArray(array, 20) << endl;//传递数组指针
    for (int a : array){
        cout << a << " -> ";
    }
    cout << endl << sumArrayRange((array + 5), (array + 9)) << endl;

    /*
     * 这段代码很好的诠释了const和*的关系，重点在于const所在的位置。
     * 举例来说“如果const在*的左边，则*val是const的，而val本身则不是
     * 若const在*的右边，则val本身是const的，但是*val却不是。
     * */
    int a = 20;
    const int *pa = &a;
    int b = 40;
    pa = &b;
    cout << "*pa is " << *pa << endl;
    int * const pa_1 = &a;
    *pa_1 = 55;
    cout << "a is " << a << endl;
    //二维数组
    int matrix[2][3] = {
            {1,2,3},
            {4,5,6}
    };
    cout << sumTwoDimMatrix(matrix, 2) << endl;
    //数组地址
    int at[5] = {1,2,3,4,5};
    int (*atp)[5] = &at;
    int *atpp = at;
    cout << (*atp)[0] << *(*atp + 2)<< endl;
    //在函数中使用string
    string str = "I love my country";//string类型的操作参考java
    show_string(&str);//传递指针时，其实也是传递了一个指针的拷贝
    cout << str << endl;
    //vector
    vector<int> vec(4);
    for(int i = 0; i < vec.size(); i ++){
        vec[i] = i * i;
    }
    show_vec(vec);
    cout << endl << "array content is " << endl;
    //array
    std::array<std::string, 4> ary = {"spring", "summer", "autumn", "winter"};
    show(ary);
    modify_array(&ary);
    cout << endl;
    show(ary);
    //递归
    cout << endl << recurs(100) << endl;

    //函数指针
    estimate(10, pam);

    double *(*pfunc[3])(const double*, int) = {func1, func2, func3};//函数指针数组
    testfuncarray(pfunc);
    double *(*((*pf)[3]))(const double *, int) = &pfunc;
    double pd[5] = {1.2, 2.5, 3.6, 2.4, 9.58};
    delete [] (*(*pf + 2))(pd, 5);
    delete [] (*pf)[2](pd, 5);
    delete [] (*(pfunc + 2))(pd, 5);

    typedef double *(*(*p_func)[3])(const double*, int) ;

    p_func pointer = &pfunc;

    testfuncarray2(pf);

}
void testfuncarray2(double *(*((*p)[3]))(const double *, int)){
    double pd[5] = {1.2, 2.5, 3.6, 2.4, 9.55};
    for (int i = 0; i < 3; i ++){
        delete [](*(*p + i))(pd, 5);
        cout << "==============" << std::endl;
    }

}
void testfuncarray(double *(*p[3])(const double *, int)){
    double pd[5] = {1.2, 2.5, 3.6, 2.4, 9.55};
    for (int i = 0; i < 3; i ++) {
        delete[] (*(p + i))(pd, 5);
        cout << "==============" << std::endl;
    }
}

double *func2(const double *p, int count){
    double *presult = new double[count];
    for (int i = 0; i < count; i ++){
        presult[i] = *(p + i);
        cout << "This is func2: " << *(p + i) << std::endl;
    }
    return presult;
}

double *func3(const double *p, int count){
    double *presult = new double[count];
    for (int i = 0; i < count; i ++){
        presult[i] = *(p + i);
        cout << "This is func3: " << *(p + i) << std::endl;
    }
    return presult;
}

double *func1(const double *p, int count){
    double *presult = new double[count];
    for (int i = 0; i < count; i ++){
        presult[i] = *(p + i);
        cout << "This is func1: " << *(p + i) << std::endl;
    }
    return presult;
}

double pam(int n){
    if (n == 0){
        return n;
    }
    return n + pam(n - 1);
}

void estimate(int lines, double (*pf)(int)){
    double result = (*pf)(lines);//两种调用都是可以的，只是暂时说不清为什么都可以
    double res = pf(lines);
    cout << "The Result of estimation is " << result << " - " << res << std::endl;
    return;
}

void Chapter6(){
    using namespace std;
    char val = 'a';
    if (isalnum(val)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    //文件的读取和写入
    ofstream out;
    out.open(outputPath);
    string fileContent = u8"我是一个好人";
    out.setf(ios_base::hex, ios_base::basefield);//设置格式化输出项目
    out.setf(ios_base::right, ios_base::adjustfield);
    out.precision(5);//设置运算精度
    out.setf(ios_base::showpoint);//显示小数点
    out << fileContent;
    out << endl;
    out << "0x" << 128 / 5 << endl;
    out.close();

    char content[1000];
    ifstream input;
    input.open(inputPath);
    if (!input.is_open()){//检查是否已经被打开
        exit(EXIT_FAILURE);
    }
    while (input){
        input.getline(content, 1000);
        cout << content << endl;
    }
    input.close();

}
void Chapter5(){
    using namespace std;
    //C++竟然还可以像python一样不写花括号
    for (int i = 0; i < 2; i ++)
        cout << "Hello,world" << endl;
    long delay = 2;
    delay *= CLOCKS_PER_SEC;
    clock_t  start = clock();//与python中的clock()函数相似
    while (clock() - start <= delay);//延迟
    cout << start << " -> " << clock() << endl;

    //基于范围的for循环，类似于Java中的增强for循环，在C++11中定义
    double prices[5] = {5.4, 56.3, 5.3, 9.5, 4.3};
    for (double item : prices)
        cout << item << endl;
    for (double &item : prices)//使用&符号代表是传递变量引用，而不仅仅是值传递
        item *= 10;
    for (double item : prices)
        cout << item << endl;

    char val[20];
    cout << "Enter the char: " << endl;
    cin.get(val, 20).get();
    cin.clear();
    while (strcmp(val, "quit")){
        cout << val << endl;
        cin.get(val, 20).get();
    }

    const int matrix[4][5] = {
        {
            1,2,3,4,5
        },{
            2,3,4,5,6
        },{
            3,4,5,6,7
        },{
            4,5,6,7,8
        }
    };
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 5; j ++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
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
}

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