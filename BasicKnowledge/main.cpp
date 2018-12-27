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
#include "lib/coordin.h"
#include <new>
#include "lib/namespace.h"
#include "classes/stock.h"
#include "Domain/time.h"
#include "Domain/Date.h"
#include <iomanip>
#include "Domain/String.h"
#include "Domain/Stack.h"
#include "Domain/Person.h"
#include "Domain/Manager.h"
#include "abc/abc.h"
#include <valarray>
#include "Domain/Student.h"
#include "ML/Worker.h"
#include "ClassTemplate/Queue.h"
#include "ClassTemplate/StackTemp.h"
#include "friendClass/TV.h"
#include <cstdlib>
#include <exception>
#include <typeinfo>
#include <memory>
#include <iterator>
#include <map>
#include <cstdio>

using std::cout;
using std::cin;

void Chapter2();
void Chapter3();
void Chapter4();
void Chapter5();
void Chapter6();
void Chapter7();
void Chapter8();
void Chapter9();
void Chapter10();
void Chapter11();
void Chapter12();
void Chapter13();
void Chapter14();
void Chapter15();
void Chapter16();
void Chapter17();

const std::string inputPath = R"(F:\CLion-workspace\LICENSE)";
const std::string outputPath = R"(F:\CLion-workspace\OUTPUT\output.txt)";
int main() {
//    Chapter2();
//    Chapter3();
//    Chapter4();
//    Chapter5();
//    Chapter6();
//    Chapter7();
//    Chapter8();
//    Chapter9();
//    Chapter10();
//    Chapter11();
//    Chapter12();
//    Chapter14();
//    Chapter15();
//    Chapter16();
    Chapter17();
    return 0;
}

void Chapter17(){
    using namespace std;
    cerr << "somthing bad" << endl;
    clog << "this is a log" << endl;
}
template <class T> void showItem(T);
template <class T> bool sortItem(T item_1, T item_2);
void Chapter16(){
    using namespace std;
    {
        /*
         * string类型：没什么可学的
         * */
        string str = "我是一个中国人";
        cout << str.find("wq", 0) << endl;
        cout << "length is " << str.length() << ", capacity is " <<str.capacity() << endl;
        cout << str.c_str() << endl;//返回一个C语言风格的字符串

        cout << sizeof(char32_t) << endl;
    }
    {
        /*
         * 智能指针其实也是一个模板对象，它用来模拟指针的行为，它优于传统指针的一点是：智能指针可以提供自动内存释放，这样就不用担心内存泄露的问题
         * 比如在一个函数中使用智能指针申请内存，而该函数由于某种原因引发异常，传统的指针将会引发内存泄露而智能指针将不会。智能指针的行为和传统指针
         * 非常相似，C++中有三种实现：auto_ptr, shared_ptr, unique_ptr这三种智能指针中第一种auto_ptr已经被标识为过时的。这三种智能指针的区别主要在于
         * 指针的赋值上。通常情况下传统指针可以进行赋值操作，也就是两个指针指向同一块内存，这并没有什么问题。然而智能指针提供了自动的内存delete操作，
         * 这就会引发问题。因此三种智能指针的区别主要在于指针赋值和使用new或new[]方式申请内存上：
         * 1. auto_ptr：这种智能指针最不安全，当程序中将一个aupo_ptr指针赋值给另一个auto_ptr指针时，另一个auto_ptr指针对内存的指向将失效，也就是说另一个
         *    auto_ptr对象中维护的指针将指向NULL，这可能会导致非常严重的运行时异常（如果在auto_ptr丧失对相应内存的指向时仍然使用这个指针时）。另外，auto_ptr
         *    只能处理使用new运算符申请的内存，也就是说使用new[]申请的内存auto_ptr是无法管理的。
         * 2. unique_ptr：这是C++11中新增的，它和auto_ptr十分相似，唯一的区别仍然在于指针赋值时，unique_ptr完全不允许指针赋值，出现这样的操作时unique_ptr
         *    会引发错误，当然编译时错误要比运行时错误好得多。但是跟auto_ptr不同的是，如果使用了new[]运算符申请内存，那么unique_ptr是唯一的选择，因为下面介绍的
         *    shared_ptr同样不能处理new[]申请的内存。
         * 3. shared_ptr：这也是C++11中新定义的智能指针，他跟auto_ptr和unique_ptr不同的是，这种智能指针可以处理指针赋值的操作，shared_ptr处理指针赋值操作
         *    的内部原理是基于引用计数原则，这和java中的垃圾回收机制比较相似，但是shared_ptr和auto_ptr相同，只能处理使用new运算符申请的内存，对于new[]申请的内存
         *    无能为力。
         * */
        unique_ptr<string> ptr = unique_ptr<string>(new string("Hello,world"));
        cout << (*ptr) << "'s length is " << ptr->length() << endl;
        cout << sizeof(ptr) << endl;

        typedef shared_ptr<string> smart_ptr;//如果将shared_ptr换成unique_ptr或auto_ptr则都会引发错误，区别是前者是编译时错误，后者是运行时错误
        smart_ptr list[5] = {
                smart_ptr(new string("Hello,world")),
                smart_ptr(new string("I am a Chinese")),
                smart_ptr(new string("I love my country")),
                smart_ptr(new string("Xi'an is a beautiful city")),
                smart_ptr(new string("I com from Hanzhong"))
        };
        smart_ptr p1 = list[2];
        for (int i = 0; i < 5; i ++){
            cout << *list[i] << endl;
        }
    }
    {
        /*
         * STL主要讲了vector的相关知识，没有什么新的东西
         *
         * */
       vector<int> v = {1,2,3,4,5,6,7,8,9};
       v.push_back(10);//相当于append
       for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter ++){//迭代器
           cout << *iter << " ";
       }
       cout << endl;
    }
    {
        /*
         * 泛型编程：
         * 1. 迭代器：注意一下C++自定义的几个迭代器就好了。
         * 2. 容器：注意使用就好了，没有特别的地方，配合迭代器使用。
         * */
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        ostream_iterator<int, char> iter(cout, ",");
        copy(v.begin(), v.end(), iter);
        cout << endl;
        copy(v.rbegin(), v.rend(), iter);
        cout << endl;
        for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it){
            cout << *it << " ";
        }
        cout << endl;
        for_each(v.begin(), v.end(), showItem<int>);
        sort(v.begin(), v.end(), sortItem<int>);
        cout << endl;
        copy(v.begin(), v.end(), iter);
        cout << endl;

        map<const int, string> m;
        pair<const int, string> pa(5, "David");
        m.insert(pa);
        for(map<const int, string>::iterator it = m.begin(); it != m.end(); it ++){
            cout << (*it).first << " - " << (*it).second;
        }
        cout << endl << m.size() << endl;
    }
    {
        /*
         * 函数对象其实就是普通的对象，他只是通过重载operator()运算符来模拟函数的调用
         * */
    }
}
template <class T> bool sortItem(T item_1, T item_2){
    if (item_1 >= item_2){
        return true;
    }
    return false;
}
template <class T> void showItem(T iter){
    cout << iter << ", ";
}
double hmean(double a, double b);
void exceptionfunc();
void except_func();
void my_quit();
void Chapter15(){
    using namespace std;

    {
        /*
         * 友元类和友元成员函数知识点较为简单：
         * 1. 友元类指的是一个类B中将另一个类A声明为友元类（friend class A），则类A中的所有方法都能访问B类中的私有和保护成员变量和函数。
         *    友元类的声明可以在类的任何位置（可以使私有的，保护的或者公有的）
         * 2. 友元成员函数指的是一个类A中的某一个方法声明为另一个类B的友元成员函数，那么A中的此方法可以访问B的所有保护和私有成员变量和函数。
         *    1. A的定义和声明必须先于B（因为在B中声明A的某个方法为友元方法时需要知道A的定义细节）。
         *    2. A的前面必须有B的类提前声明（class B;），这是因为A中被作为B类友元的成员函数通常需要有一个B的对象引用，所以要使用提前声明
         *    3. A中被声明为友元的成员函数不能被实现成隐式内联，要么使用inline关键字显式内联实现在B类定义的后面，要么在单独文件中实现，这是因为
         *       A类中的友元成员函数通常需要使用B中的成员函数或者变量，这就需要完整的B类定义，所以友元成员函数的实现应该晚于B类声明。
         * */
        TV<int> tv = TV<int>();
        Remote re = Remote();
        re.friendfunc(tv);

        Remote_1 r = Remote_1();
        r.func(tv);
    }
    /*
     * 内部嵌套类和内部嵌套结构体是一样的。只不过结构体的所有成员变量都相当于类的共有变量而已，嵌套类的重点在于作用域：包含嵌套类的类可以使用嵌套类
     * 所有类型的成员，从嵌套类包含类派生出的类可以使用除private的其他两个类型的成员，最后通过对象只能使用嵌套类的公有成员（一句话，嵌套类的访问控制方式
     * 和类继承相似）
     * */

    //异常
    {
        /*
         * c++中的异常和java中的异常非常类似，只是没有java中异常设计的那么良好，总结出了以下五个知识点：
         * 1. 异常中抛出了什么就在catch中捕获什么，例如throw "Bad Exception"抛出了一个字符串或者说是字符指针，那么在相应的catch中就要catch(const char *s)
         * 2. 异常处理中要注意栈解退的问题，通常抛出的异常会逐层上抛，直到有一个catch将其接住。否则将会引发程序崩溃。栈解退过程中自动变量都将被释放，但是通过new
         *    申请的内存则不会，需要注意这一点。
         * 3. 可以使用catch(...)或者catch(exception &e)来捕获任何种类的异常。
         * 4. 可以通过继承exception类来定义自己的异常，在这里需要重载what方法。当然c++中有一些已经定义好的异常可以直接用。
         * 5. 可以通过设置set_terminite或者set_unexpected方法来重新定义未捕获异常和意外异常的默认处理方式（默认是直接abort终结程序）。
         * */
        try{
            hmean(10, -10);
        }catch(const char *s){
            cout << s << endl;
        }
        try{
            exceptionfunc();
        }catch(const char *s){
            cout << s << endl;
        }
        try{
            except_func();
        }catch(...){//捕获任何类型的异常

        }
        set_terminate(my_quit);//指定未捕获异常的处理函数
        hmean(5, -5);
    }

    /*
     * RTTI
     * 所谓RTTI指的是运行时类型转换，要记住三个操作：
     * 1. dynamic_cast<>():该操作提供动态类型转换，可以转换指针：A *p = dynamic_cast<A *>(p1)，也可以用来转换引用:A &a = dynamic_cast<A &>(b),
     *    需要注意的是：如果转换不成功（通常是将子类指针或引用指向基类对象地址或对象本身），那么指针转换会返回一个空指针，而引用转换则会抛出异常bad_cast
     * 2. typeid和typeinfo：使用这个需要导入头文件#include<typeinfo>，typeid是一个函数，接收类或对象，返回一个typeinfo对象，该对象用于标识传入
     *    typeid函数参数的类型。通常typeinfo对象有很多种实现，但都有name方法。
     * */

}
void my_quit(){
    cout << "somthing happen" << endl;
    exit(5);
}
void except_func(){
    throw "Ede";
}

void exceptionfunc(){
    try{
        hmean(10, -10);
    }catch(const char *s){
        cout << s << endl;
        throw;//重新抛出异常
    }
}

double hmean(double a, double b) {
    if (a == -b){
        throw "bad hmean() arguments: a = -b not allowed";
//        abort();//强制关闭程序，且后果不明确，不建议使用
    }
    return 2.0 * a * b / (a + b);
}
class cust{
private:
    string name;
    int age;
public:
    cust():name("unknown"), age(-1){}
    cust(const string &s, int age):name(s), age(age){}

    void getname(){
        cout << "name is " << name << endl;
    }
    void getage(){
        cout << "age is " << age << endl;
    }
};

void Chapter14() {
    using namespace std;

    valarray<double> a = valarray<double>(8, 20);
    for (double item : a) {
        cout << item << " ";
    }
    cout << endl;

    {
        /*
         * 私有继承是实现has-a的一部分，它和公有继承不同，公有继承是实现is-a的一部分，这二者的区别主要体现在：
         * 1. 私有继承中基类的public部分在子类中被声明为private，也就是说父类的publick的部分只能在子类内部访问，而无法通过子类对象访问。
         *    而在公有继承中，父类的public部分在子类中依然是public的，可以通过子类对象访问。
         * 2. 私有继承无法进行隐式类型转换，在私有继承中无法直接将基类指针或引用指向子类对象的地址或对象，必须通过强制类型转换才可以。
         * 不推荐使用私有继承来实现has-a关系，相较于包含，私有继承功能很弱（例如一个类中要包含三个string，那么私有继承将无法处理，总不能私有继承
         * 三个string类吧，这也不符合语法规定）。
         *
         * 保护继承和私有继承相似，都是实现has-a关系的。但是也是有区别的：
         * 1. 私有继承中基类的公有成员和保护成员都将在子类中变成私有成员，保护继承下基类中的保护成员和公有成员将变成
         *    子类的保护成员。这一点差异在子类又派生子类时很有用，子类派生的子类将无法看见私有继承下基类的公有成员，
         *    但是却能看见保护继承下基类的公有成员，这正是保护继承和私有继承在基类公有和保护成员上处理不同导致的。
         * 保护继承和私有继承其实没什么用，事实上在java中直接删除了保护继承和私有继承，只保留公有继承。
         * */
        valarray<double> val = {98.5, 96.4, 91.5, 85.4, 87.6, 89.4, 88.1, 90.5, 95.4};
        Student s = Student("David", val);
        cout << s << endl;
        s[5] = 14;
        cout << s[5] << endl;

        cout << s.Average() << endl;
    }
    {
        /*
         * 多继承中需要考虑的问题更多：若子类拥有多个基类，这些基类都继承自同一个更高级别的父类，那么最底层的子类中就会存在多个最高级的父类对象；若一个子类中拥有
         * 多个基类，假设要通过这个子类对象调用一个方法，而这个方法在其多个基类中都有定义，那么就会引发二义性（这点和python不同，C++不会触发类树搜索）。
         * 为了解决这些问题，在使用多继承时需要注意以下几点：
         * 1. 若一个类的多个基类都是继承自同一个父类，那么要使用虚基类（所有处于中间层级的类都要虚继承）。
         * 2. 使用虚基类时要注意使用新的构造函数语法：最低层级的子类要负责最高层级父类的构造。
         * 3. 多继承中处于最底层的子类，如果要调用其的一个方法，而这个方法在其不止一个父类中定义过，那么要在该子类中重新定义，否则会引发二义性。
         * */
        SingerWaiter sw = SingerWaiter("David", 5);
//        sw.Set();
//        sw.show();
    }
    {
        /*
         * 类模板和函数模板有相似的地方，跟Java中的泛型在概念上也十分类似，但是在C++的类中使用类模板还是要注意一些地方：
         * 1. C++中类使用模板的情况下使用域解析操作符::时必须将类泛型类型带上，举例如下：
         *    template <class T>
         *    class A{
         *    public:
         *        void getname(){
         *            cout << "在类内部不需要使用类的泛型" << endl;
         *        }
         *        void getage();
         *    };
         *    template <class T>
         *    void A<T>::getage(){
         *        cout << "但是在类的外部就需要使用类的泛型了" << endl;
         *    }
         * 2. 类模板中的成员函数（友元函数不是成员函数，例外）定义不能在普通的cpp文件中，最简单的方法是将所有的定义都放在头文件中。
         * 3. 类模板中可以传入指针模板，也就是Class<char *> p = Class<char *>()。在这种情况下一般在类中使用一个二重指针（本例中是char **）
         *    来管理，这样做的理由是二重指针是指向指针数组首地址的指针，可以用来管理指针。具体例子见代码：
         * 4. 模板还可以用来传递参数：template <class C, int n>，后面的int n称为表达式参数，可以是整型，枚举，指针或者引用（注意不能是double，但可以是
         *    double *或者double &），在使用中表达式参数被当做常量来用，不能修改其值。（感觉并没有什么用）
         * 5. 类模板的具体化：
         *    1. 显式实例化。
         *    2. 隐式实例化。
         *    3. 显示具体化（又包含了部分显示具体化）。
         * 6. 成员函数的模板：这一点个人觉得不要使用，如果函数中还有模板需要使用，那么最好在类定义的开头就将所有的模板都写出来，不要在成员函数声明时再使用模板
         * 7. 友元函数的模板：
         *    1. 模板类的非模板友元函数：这种友元函数跟类模板没有任何关系，最多使用了模板类：
         *       friend void show(Class a);
         *       //xxx.cpp
         *       void show(Class<int> a){
         *           ...
         *       }
         *       void show(Class<double> a){
         *           ...
         *       }
         *       ...
         *    2. 模板类的约束模板友元函数：这种类型的友元是被模板类约束的，通常情况下需要分三步才能完整的声明和定义这种被约束的模板友元函数：
         *       template <class T> void show(T &);//第一步先声明友元函数原型
         *       template <class T>
         *       class A{
         *       public:
         *           friend void show<>(A<T> &);//在类的内部声明这个友元函数
         *           //friend void show<A<T>>(A<T> &);//这种写法也可以
         *       }
         *
         *       template <class T>
         *       void show(A<T> &t){//最后实现该友元函数，需要注意的是：这个友元函数的实现必须在头文件中定义，不能挪到其他的文件中
         *           ...
         *       }
         *   3. 模板类的非约束模板友元函数：这种类型的友元函数跟模板类成员函数声明到定义都是一致的，唯一的区别就是友元函数不使用::域解析运算符
         * */
        Queue<cust> q = Queue<cust>();
        cust c = cust("David", 35);
        cust c2 = cust("Smith", 28);
        q.en_queue(c);
        q.en_queue(c2);
        cust c1 = q.de_quese();
        cust c3 = q.de_quese();
        c1.getname();
        c1.getage();

        c3.getname();
        c3.getage();
        {
            Queue<char *> q = Queue<char *>();
            char *tmp = new char[40];
            strcpy(tmp, "Hello");
            q.en_queue(tmp);

            delete[]tmp;
        }

        StackTemp<int> ss = StackTemp<int>(10);
        ss.getname(25.4);
        show(ss);
        show_1(ss);
        show_2(ss);
        ss.show_3(StackTemp<int>(20));

        ss.show();
    }
}


void Chapter13(){
    {
        using namespace std;
        /*
         * C++中类的继承：
         * 1. 子类要负责父类的继承。
         * 2. 父类中的变量子类无法覆盖，这一点和Java是非常类似的：假如说父类如下所示：
         *    class super{
         *    public:
         *         string name = "super";
         *         void get_name(){
         *             cout << name;
         *         }
         *    }
         *    class sub: public super{
         *    public:
         *         string name = "sub";
         *    }
         *    sub s = sub();
         *    s.get_name();
         *    此时将会输出super。其实在python中如果是相同逻辑的代码那么将会输出sub，但是C++和Java中就会输出super，这是因为在sub中的name没有
         *    覆盖super中的name，调用get_name时编译器会首先调用super中的而不是sub里面的。
         * 3. 子类无法使用父类的私有方法和私有变量。
         * 4. C++中拥有三种继承方式：公有继承，保护继承，私有继承。
         * 5. C++中实现类多态的方法有两种：
         *    1. 虚函数（virtual）：这种方法适用于使用指针或者引用指向对象，如果父类和子类中都定义了一个方法func()，现在使用一个父类指针或者引用指向子类
         *       对象，使用这个指针或者引用调用func()方法，那么编译器将根据指针或者引用的类型来决定调用哪一个func()，也就是说这个例子中将会调用父类的func()，
         *       即使指针或引用指向的是子类对象，但是指针或者引用类型是父类，那么调用就还是会调用父类的同名方法。
         *
         *       需要严重注明的是：如果类中包含析构函数，那么析构函数最好也设置为virtual的，因为若使用指针或引用那么析构函数将面临上面同样的问题。
         *       在这一点上类成员变量和类方法的行为相同，但是不能在成员变量前加上virtual关键字，virtual关键字使用来修饰非静态成员函数的。
         *    2. 在派生类中重新定义基类方法。这种方式适用于通过对象而非指针或者引用调用的方法。
         *
         *    无论哪一种方法，在子类重载父类方法时，若在子类方法中要调用父类的方法必须要使用作用与预算符::，如果不使用，则会引发递归调用。
         * 6. 构造函数不应该是虚的，但是析构函数若有子类继承则应该是虚的。
         * 7. C++中的虚函数表，这是虚函数得以发挥作用的关键。
         * 8. 子类若重新定义父类的方法，即使参数不同也会覆盖父类的同名方法，无论是否为虚函数。由此引出了返回值协变和多个同名方法的覆盖问题。
         *    （有一个总结出来的小trick：使用引用或指针时，若使用基类指针指向子类对象，那么父类指针调用的无论是方法还是共有变量都是父类中的，不管
         *      子类有没有覆盖父类的方法，或者重载父类的方法。但是唯一的例外就是子类重载了父类的虚函数，那么这种调用就会使用子类的重载方法。）
         * */
        Person p = Person("Ann", females, 25);
        cout << p << endl;
        p.get_name();


        Manager m = Manager("David", males, 45, 15000);
        m.get_salary();
        m.name = "Smith";
        m.get_name();
        cout << m << endl;

        cout << "=======================" << endl;
        Person *pp;
        pp = &m;
        pp->func();
        m.func_1("David");
        pp->func_1();

    }
    {
        /*
         * 抽象基类
         * 1. 包含有纯虚函数的类被称为抽象类或者抽象基类，这种类不能被实例化，但是可以包含构造函数。
         * 2. 纯虚函数是指在成员函数末尾有=0写法的函数，类似于virtual void func() = 0;这种函数最好不要在抽象基类中实现，因为实现了也没有什么意义。
         * 3. 抽象基类的子类必须负责抽闲积累的构造，并且一定要实现抽闲基类的所有纯虚函数。
         * 4. 抽象基类的继承和普通类
         * 继承所有细节都一致。
         * */
        cout << "===============================" << endl;
        using abc_example::Person;
        using abc_example::Doctor;
        Doctor d = Doctor(string("David"), 25, 185, 1, 15000);
        Person &p_a = d;
        p_a.show_name();
        p_a.show_level();
        p_a.show_type();
        p_a.func();
    }
}

void Chapter12(){
    using namespace std;

    {
        /*
         * 这一节讲了拷贝构造函数，拷贝构造函数就是在对象被拷贝的时候调用的，那么一个对象通常在以下几种情况下会被拷贝（使用Stock举例）：
         * 1. 当对象以值传递作为函数的参数时（这时传入函数参数是其实传入的是一个对象的临时拷贝）。
         * 2. 当函数以值返回时（此时，对象将把自己的值复制到一个寄存器中返回，也是对象拷贝）。
         * 3. 使用赋值运算符时（这个在C++中有些特殊，因为其他的语言中赋值运算符往往都是指针指向就行了，但是C++中明确是对象拷贝），举例来说有这样一个赋值运算：
         *    Stock obj1 = Stock();Stock obj2;obj2 = obj1;这样就触发拷贝操作，需要注意的是：此时并不是将obj2的指针指向了obj1的内存，而是将obj1的内容完整的
         *    拷贝到了obj2中，虽然obj1和obj2的内容相同，但是二者的地址完全不同。对着赋值操作：有的编译器会将obj1的值复制给obj2，有的会复制obj1的值到一个临时对象，
         *    然后在调用赋值运算符“=”（通常是这个运算符的重载函数）将临时对象的值赋给obj2。不管哪一种实现，都要进行对象的拷贝。
         *
         * 只要一个类中有new运算申请内存就需要自定义拷贝构造函数和重载赋值“=”运算符：
         * 1. 拷贝构造函数中需要对所有的成员变量作深拷贝，例如指针不能仅仅复制值。
         * 2. 赋值运算符的重载需要作为类的成员函数进行，不能作为友元或者普通成员函数。
         * 3. 赋值运算符重载时需要注意三个问题：
         *    1. 需要返回调用对象的引用。
         *    2. 不能对其自身进行赋值操作，所以要在重载程序开始之前判断this是否等于另一个操作数的地址。
         *    3. 需要将自身内部不需要的指针内存释放掉。
         * */
        Stock t = Stock("Microsoft");//使用构造函数
        t.show();
        cout << "=====================================" << endl;
        Stock *p = new Stock();
        p->show();
        delete p;
        cout << "=====================================" << endl;
        Stock t1 = {"FaceBook"};
        t1.show();
        cout << "============================="
                "========" << endl;
        Stock t2;
        cout << "The address of t2 is " << (int *)&t2    << endl;
        t2 = t1;
        cout << "The address of t2 is " << (int *)&t2 << ", the address of t1 is " << (int *)&t1 << endl;
    }

    /*
     * 1. 静态的成员方法需要加上static关键字，但是在实现的时候不能使用static
     * 2. 在使用定位new运算符申请对象内存时注意在结尾不能使用delete来释放内存，如果对象内部也有new申请内存的情况则需要显示调用对象的析构函数。
     * 3. 如果成员变量中含有const或者引用类型，那么就需要初始化他们，由于这些类型的变量不能够赋值而只能初始化，所以必须在类实例化前初始化他们，要么在
     *    声明的时候就初始化，要么就在函数的构造方法上使用特殊语法来初始化。需要注意的是：const类型的变量可以用常量来初始化，但是引用类型则不行
     * */
    cout << "================================" << endl;
    {
        /*
         * String这个自定义类型主要是为了验证拷贝构造函数以及对=运算符的重载：
         * 1. 拷贝构造函数接收const类型的引用参数，主要提供深拷贝功能。
         * 2. 对“=”运算符的重载必须要使用类成员函数进行，而且有三点要注意。
         * */
        String str = String("Hello,world");
        cout << "str is \""<< str << "\", length is " << str.get_length() << endl;
        String str1;
        str1 = str;
        cout << "str1 is \"" << str1 << "\", length is " << str1.get_length() << ", num_strings is " << String::how_many() << endl;

        String str3 = str1 + " " + str;
        cout << "str3 is \"" << str3 << "\", length is " << str3.get_length() << ", num_strings is " << String::how_many() << endl;
        cout << "str3[5] is '" << str3[5] << "'" << endl;
        str3[5] = 'o';
        cout << "str3 is \"" << str3 << "\", length is " << str3.get_length() << ", num_strings is " << String::how_many() << endl;

        String s1 = "a";
        String s2 = "b";
        cout << "s1 > s2's result is " << (s1 > s2 ? "true" : "false") << endl;
        cout << "s1 < s2's result is " << (s1 < s2 ? "true" : "false") << endl;
        cout << "s1 == s2's result is " << (s1 == s2 ? "true" : "false") << endl;

//        String s3;
//        cin >> s3;
//        cout << s3 << endl;
    }
    cout << "num_strings is " << String::how_many() << endl;

    cout << "================================" << endl;
    {
        Stack st = Stack();
        customer c = customer("David", 15);
        st.push(c);
        customer c2 = customer("Smith", 14);
        st.push(c2);
        customer c3 = customer("Ann", 29);
        st.push(c3);
        cout << st << ", the size of it is " << st.get_size() << endl;
        cout << st.pop() << endl;
        cout << st << endl;
    }
}

Time operator-(double a, const Time &b);
void Chapter11(){
    using namespace std;
    Time t = Time(10, 15);
    /*
     * 这就是C++中的运算符重载。很简单：就是在其中定义一个operator op()函数重载就可以。
     * 运算符重载也有很多限制：
     * 1. 重载的运算符的操作数中必须至少有一个是用户自定义的类型（当运算符重载作为成员方法时无需担心这个限制，天然满足，但是在使用函数重载运算符时就要注意这一限制）
     *    类似于这样的重载是不被接受的double operator*(double a, double b);
     * 2. 运算符重载不能违反运算符原有的规则，例如减法需要有两个操作数，不能重载成只有一个操作数。
     * */
    Time t1 = t + Time(20, 45) + Time(25, 6);
    t.show();
    t1.show();
    /*
     * 下面的调用本质上是：t.operator-(15.6)，如果把式子写成15.6-t那么就会无法运算，因为这样的调用等效为：(15.6).operator-(t)但是double并没有重载减法运算符到Time类型
     * 这时候就要使用函数来重载减法运算：Time operator-(double a, const Time &b)，但是这种形式的运算符重载没有解决访问类私有变量的问题，要解决这个问题就要用到友元函数：
     * 1. 友元函数不是类成员，但是可以访问类的私有变量。
     * 2. 友元函数要定义在类中，且函数原型前面要加上friend关键字。在具体实现时注意不要使用::域作用运算符，因为友元函数不是类的成员函数，且实现的时候不要使用friend关键字。
     * 3. 友元函数可以使用默认内联形式实现，也可以使用显式内联形式实现，也可以使用非内联的形式实现，在实现方面和普通的成员函数相同。
     * */
    //
    Time t2 = t - 15.66;
    t2.show();
    t2 = 15.6 * t;
    t2.show();

    //友元
    t2 = 15.6 - t;
    t2.show();
    /*
     * 这个重载了<<运算符，虽然重载了<<运算符，但是有一个很明显的问题：类似于cout << t2这样的调用既可以解释成调用cout.operator<<(t2)
     * 也可以解释成调用了Time中的友元函数或者调用了单纯的运算符重载函数（当然这二者不能同时存在，否则会引发冲突）。之所以会选择后者完全是因为后者的特征标更符合调用：可以想见，cout中
     * <<运算符的右边参数由于要考虑到通用性肯定是一个类似于java中object的对象，但是在友元函数或者普通的<<运算符重载中这个右边参数一定会被精确指定为Time，这样在调用时就会优先匹配
     * 参数匹配度高的。
     * */
    cout << t2 << t1 << "Hello, world" << endl;
    //一个例子
    cout << "======================================" << endl;
    using DATE::Date;
    Date d1 = Date();
    cout << d1 << endl;
    Date d2 = Date(d1.get_million_seconds());
    d2.set_date_format(DATE::format_12_hours);
    cout << d2 << endl;
    Date d3 = Date(1978, 12, 15, 12, 45, 15, DATE::format_24_hours);
    cout << d3 << endl << "======================" << endl;
    cout << d3 + d1 << endl;

    /*
     * C++中的强制类型转换，必须要在类成员中定义operator long/double/int/...() const;
     * 若方法前面加上explicit则需要强制转换才行。
     * */
    long tmp = (long)d3;
    Date d4 = 282487515;
    cout << tmp << endl;
    cout << d4 << endl;
}
Time operator-(double a, const Time &b){
    return b - a;
}
void Chapter10(){
    using namespace std;

    //头文件中也可以定义一个内联函数，内联函数要求在每个使用的程序文件中都定义一次，因此在头文件中直接定义内联函数是推荐的。
    inline_function();
    {/*
     * 类中一个方法如果直接在类中定义，那么这个方法默认就是内联的而不用显示写出inline关键字。
     * 另一方面：类方法也可以不在类中定义，而在头文件中定义，但是此时要显式写出inline关键字。
     * 最后，类方法无论是private还是public都可以不以内联方式定义，但是这种情况下就不能在头文件中定义，因为这可能会引发多重定义错误。
     * */
        Stock t = Stock("Microsoft");//使用构造函数
        t.show();
        cout << "======================" << endl;
        Stock *p = new Stock();
        delete p;
        cout << "======================" << endl;
        /*
         * 这种将已有变量重新赋值的行为一定会产生一个临时变量，这个临时变量将会很快被销毁从而调用析构函数。
         * 这样的对象初始化方式可以简单地认为是对构造函数的调用，通过参数列表的特征标来区分调用的构造函数。
         * 使用const关键字修饰的对象不应该被修改，因此这种对象调用的方法也不能修改对象，
         * 换句话说const对象调用的方法必须有const关键字修饰，这种方法中不能对对象的内容进行修改
         * */
        const Stock t1 = {"FaceBook"};
        t1.show();
        /*
         * 在这里，引出了类中的一个重要关键字：this，这个关键字在类中指的是一个指针，注意是指针，这个指针
         * 指向该对象的首地址，也可以使用*this来返回这个对象的引用。
         * */
        Stock t2 = t1.topval(t);
        t2.show();
    }
    /*
     * 在类中往往需要使用一些常量来限定例如数组的长度等等，但是不能使用普通的成员变量来做这件事，因为普通的成员变量
     * 在类没有实例化之前是没有值的（即使在类声明时给出了值const int size = 15;，但这也要在类实例化之后才能够赋值）
     * 但是数组长度这样的参数需要在实例化的时候就给出。解决这个问题的方案有两个：
     * 1. 使用作用域内枚举。
     * 2. 使用静态const变量。（这种变量的生存周期是整个程序运行期间，且一定要加const关键字）
     * */

    //在命名空间里也可以自由的使用类
    {
        ilmare::Person person = ilmare::Person("David", 15, male);
        person.show();
        ilmare::p.show();
    }
}

extern int cat;//使用外部变量（存在于function.cpp中）
/*
 * 这个变量在function.cpp中也定义了，因此如果在这里还需要定义一个同名的内部变量，就必须加上static关键字，否则将会引发错误。
 * 引发错误的原因在于，如果不使用static关键字，那么dog将会声明为全局静态变量，但是在function.cpp中已经存在一个名为dog的全局
 * 静态变量，这就会引发冲突。所以必须使用static关键字，显式地指定dog为内部变量才可以。
 * 指针也可以作为外部链接变量。
 * */
static int dog = 114;
static double mick = 25.45;
void count();
static void Chapter9_func();

void Chapter9(){
    using namespace std;
    rect rplace = {15.4, 20.5};
    polar pplace = rect_to_polar(rplace);
    show_polar(pplace);

    /*
     * 静态变量的知识点：
     * 1. 静态的外部链接性的变量（通常在函数外不声明，不使用static关键字，这种变量不仅仅在程序文件内部可见，在整个项目中都是可见的，外部程序文件使用时需要使用extern关键字）
     * 2. 静态的内部链接性的变量（通常在函数外声明，使用staitc关键字，这种变量仅仅在程序文件内部可见）
     * 3. 静态的无链接性的变量（通常在函数内部或代码块中声明，使用staitc关键字，这种变量只在声明的函数或代码块内部可见，生存周期是整个程序运行期间，与函数或代码块的调用无关。
     *    因此在函数反复调用的时候用于保存函数状态）
     * 4. const关键字的知识点：如果给一个静态变量前面加上const关键字，那么就是自动给它加上了static关键字。这样的话就会被声明为一个静态内部变量，这样的变量可以被.h的头文件使用
     *    因为这种变量不是外部链接性的，因此当头文件被多个程序文件include的时候，不会引发多重定义，而内部链接性又让这些变量在include这个头文件的程序文件内部是可见的，加上了const
     *    关键字又让这些变量不可更改。
     * */
    int cat= 256;
    /*
     * 局部变量的声明会隐藏同名的外部变量，但是使用::运算符可以显示指定使用外部变量或本地局部变量，就如同python中的global关键字
     * 如果要使用无链接性的静态变量隐藏外部变量，那么只需要将内部静态变量使用static关键字声明赋值即可，他会自动隐藏外部变量，一定不要忘记static关键字，若缺失会引起变量重定义错误。
     * */
    cout << "Inner variable is " << cat << ", extern variable is " << ::cat << endl;

    /*
     * 使用无链接性的静态变量：这种静态变量声明在函数中或者代码块里，这种变量的生命周期是整个程序运行期间，与函数的生命周期无关。虽然这种变量在函数或代码块的外部无法访问到。
     * 但是函数或代码块内部却是一直可见的，这样的变量可用于保存函数的状态，因为即使函数调用完毕这样的变量也不会被释放，下次函数调用时依然可以使用这个变量，其内部的状态并不会发生改变。
     * */
    for (int i = 0; i < 3; i ++){
        count();
    }
    /*
     * 关于c++内部和外部链接变量的总结：
     * 1. 内部链接变量是在函数外部由static关键字修饰的变量，使用const关键字修饰的变量也会自动为其加上static关键字修饰变成内部链接变量（这种变量和前一种声明方式相比是不可修改的）。
     *    这种变量仅仅在程序文件内部可见，或者在一个头文件中定义了这样的内部链接变量后，在另一个程序文件中使用#include操作后也可见。
     * 2. 外部链接变量是在整个程序内部都可见的变量。不使用static关键字，如果要声明这种变量为不可变，那么必须在前面加上extern const，之所以要加两个关键字是因为：如果只有一个const
     *    那么编译器会自动将这个变量声明为static的内部链接变量，就像第1点中所说的，因此还必须加上extern显式说明这是一个外部链接变量。且需要说明的是在.h结尾的头文件中不应该包含
     *    外部链接性的变量，因为一个头文件可能会被多个程序文件#include，如果包含了外部链接的变量，那么每一次#include都会定义一次外部链接性的变量，这样会引发变量的重复定义从而导致错误。
     * 3. 内部链接性的变量在同一个程序文件中只能声明一次，但是在整个程序中的不同程序文件之间却可以声明多次。
     * 4. 外部链接性的变量在整个程序中只能声明一次。
     * 5. 每一次#include头文件都相当于把头文件中的内容全部包含近来执行了一次，所以千万不能在头文件中定义外部链接变量，除非这个头文件只被#include一次，否则一定会产生变量重复定义。
     * */
    cout << cats << endl;//在头文件中包含了const int cats = 555;

    //函数的内部外部链接性和变量是相同的，同样也可以使用extern和static关键字
    Chapter9_func();

    //new运算符
    /*
     * 使用#include引入新的new和传统的new最大的区别在于，新的new可以指定内存分配的具体地址。
     * 下面的例子中使用传统的new关键字会在程序的堆“heap”中开辟一片内存，具体放置在哪程序员无法感知，但是使用了新的new运算符（需要使用#include<new>）后就可以指定一片内存
     * 在这个例子中制定了一个512字节的buffer。和传统的new关键字不同，新的new操作需要这样使用：new (buffer) double[10]。也就是需要显示指定内存的具体位置。
     * 需要特别说明的是：使用新的new运算符创建内存不需要释放，而且创建的开始地址就是括号中的地址，也就是说如果循环创建且不在括号中加入地址偏移量的话，新申请的内存就会覆盖原有的。
     * 需要这样操作才能够避免新申请的内存覆盖掉原有的new (buffer + size * sizeof(double)) double[size]，即增加一个地址偏移量。
     * 之所以不需要释放的原因是申请内存的内存池buffer本来就存在于程序运行的堆中，而delete运算符只对heap中的内存有权限操作，因此无法delete。
     * */
    int size = 5;
    char buffer[512];//定义一个512字节的缓冲，新的内存将在这里面开辟
    cout << "buffer's address begin at " << (int *)buffer << endl;
    double *pd = new (buffer) double[size];
    double *pd_1 = new double[size];
    for (int i = 0; i < size; i ++){
        pd[i] = pd_1[i] = (i + 1) * 1000 + 1;
    }
    for (int i = 0; i < size; i ++){
        cout << "\"" << pd[i] << "\"" << " is in " << &pd[i] << ", \"" << pd_1[i] << "\"" << " is in " << &pd_1[i] << std::endl;
    }
    delete [] pd_1;
    cout << "============" << endl;
    pd = new (buffer + size * sizeof(double)) double[size];
    pd_1 = new double[size];
    for (int i = 0; i < size; i ++){
        pd[i] = pd_1[i] = (i + 1) * 1000 + 1;
    }
    for (int i = 0; i < size; i ++){
        cout << "\"" << pd[i] << "\"" << " is in " << &pd[i] << ", \"" << pd_1[i] << "\"" << " is in " << &pd_1[i] << std::endl;
    }
    delete [] pd_1;//使用新new申请的内存不需要释放，也无法被释放，除非buffer也是使用new关键字申请的。

    //名称空间
    /*
     * 命名空间中可以包含命
    ilmare::fetch("David");名空间，可以包含字段，函数的命名。这种命名空间可以定义在头文件中。但是如果定义在头文件中就不能包含字段的命名，因为头文件可能会被多个文件include
     * 这样的话就会执行多次命名空间定义，每一次命名空间定义都会定义一次字段，造成同一字段的多次定义，这会引发错误。因此在头文件中的命名空间最好只包含函数原型的声明，然后在
     * 另一个文件中对命名空间中的函数进行实际的定义。
     * */
    ilmare::func_1();
    Jill::func();
    ilmare::ilmare_c::func();
}

static void Chapter9_func(){
    cout << "This is static function" << std::endl;
}

void count(){
    static int total;
    cout << "Total is " << total << std::endl;
    total += 1;
}

inline double square(double);//也可以使用这种声明方法
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
void Swap(T &a, T &b);
template <class T>//函数模板重载，函数模板重载和普通的重载一样，也需要函数特征标不同，
void Swap(T *a, T *b, int n);
struct job{
    std::string name;
    double salary;
    int floor;
};
template <> void Swap<job>(job &, job &);
/*
 * 以下是普通函数定义；普通模板函数定义；显式具体化定义三种形式。
 * */
void func(int a, int b);
template <class T>
void func(T a, T b);
template <> void func<int>(int a, int b);

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
    printTest(3);

    //函数重载：关于函数重载只用知道一条：那就是编译器只使用特征标（即函数参数列表中参数的类型和排列顺序）来区分同名函数，跟函数的返回值没有关系
    print("I love you", 5);
    print(4);

    /*
     * 在使用函数模板时，声明的函数模板并不会生成一个函数实例，通常在调用时才会根据使用者定义的泛型类型去根据模板生成一个函数实例。显示具体化定义函数就是为了绕开函数模板，
     * 声明该同名函数不属于模板函数。又由于显示具体化函数的调用优先级高于模板函数，因此在调用时会优先匹配显示具体化定义的函数。
     * 通常，在使用时才根据使用者传入的泛型类型和函数模板来实例化函数的形式被称为“隐式实例化”。使用template void<typename>(paramA, paramB)这样的函数调用形式就是“显式实例化”
     * 这种形式和显式具体化非常相似，但是不同的是缺少了显示具体化在template关键字后面的<>
     * 重要的概念：
     * 1. 显式具体化
     * 2. 显示实例化
     * 3. 隐式实例化
     * 重要说明：
     * 1. 函数模板可以使用template <class T>这样的声明在C98中定义，也可以使用template <typename T>这样的声明
     * 2. 函数模板重载，函数模板重载和普通的重载一样，也需要函数特征标不同。
     * 3. 显式具体化定义函数（非函数模板）用于弥补模板函数处理能力不足的问题（例如可以处理结构体中的点运算符）。通常在使用中调用一个函数，若这个函数使用普通方式定义过，
     *    利用普通模板方式定义过，利用显式具体化的方式定义过。那么在调用时通常遵循高优先级优先被调度：普通函数的调用优先级 > 显示具体化定义的函数优先级 > 普通模板函数的优先级
     * 4. 再追加一点：在调用时当然可以直接使用函数名，让编译器来选择合适的函数版本，但是也可以显式地指定：func()这样的调用就是让编译器来选择函数版本，func<>()这样的调用
     *    是明确指定在函数模板中选择（选择范围包括显示具体化的版本），func<typename>()是显示实例化一个函数模板
     * */
    int aa = 50;
    int bb = 46;
    Swap(aa, bb);//模板函数
    cout << aa << " " << bb << endl;

    int a_array[5] = {1,2,3,4,5};
    int b_array[5] = {6,7,8,9,10};
    Swap(a_array, b_array, 5);//函数模板重载
    for (int i = 0;i < 5; i ++){
        cout << a_array[i] << " ";
    }
    cout << endl;


    job j1 = {"David", 9500.43, 5};
    job j2 = {"Smith", 5400.69, 1};
    Swap(j1, j2);//显式具体化
    cout << j1.name << " -> " << j1.salary << " -> " << j1.floor << endl;
    cout << j2.name << " -> " << j2.salary << " -> " << j2.floor << endl;

    func<>(12, 34);//显式指定使用函数模板，不使用普通函数定义
    func<double>(12, 34);//显式实例化生成一个double型的函数

}

template <>
void func<int>(int a, int b){
    cout << "This is in template<> " << a << b << std::endl;
}
void func(int a, int b){
    cout << "This is func " << a << b << std::endl;
}
template <class T>
void func(T a, T b){
    cout << "This is template<class T>" << a << b << std::endl;
}


template <> void Swap<job>(job &a, job &b){//通常都是这么写的
    double t1;
    t1 = b.salary;
    b.salary = a.salary;
    a.salary = t1;
    int t2;
    t2 = b.floor;
    b.floor = a.floor;
    a.floor = t2;
}

template <typename T>//template <class T>这样的声明在C98中定义
void Swap(T &a, T &b){
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}
template <class T>
void Swap(T *a, T *b, int n){
    T temp;
    for (int i = 0; i < n; i ++){
        temp = b[i];
        b[i] = a[i];
        a[i] = temp;
    }
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