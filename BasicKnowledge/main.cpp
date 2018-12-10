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
    Chapter12();
    return 0;
}

void Chapter12(){
    using namespace std;

    {
        /*
         * ��һ�ڽ��˿������캯�����������캯�������ڶ��󱻿�����ʱ����õģ���ôһ������ͨ�������¼�������»ᱻ������ʹ��Stock��������
         * 1. ��������ֵ������Ϊ�����Ĳ���ʱ����ʱ���뺯����������ʵ�������һ���������ʱ��������
         * 2. ��������ֵ����ʱ����ʱ�����󽫰��Լ���ֵ���Ƶ�һ���Ĵ����з��أ�Ҳ�Ƕ��󿽱�����
         * 3. ʹ�ø�ֵ�����ʱ�������C++����Щ���⣬��Ϊ�����������и�ֵ�������������ָ��ָ������ˣ�����C++����ȷ�Ƕ��󿽱�����������˵������һ����ֵ���㣺
         *    Stock obj1 = Stock();Stock obj2;obj2 = obj1;�����ʹ���������������Ҫע����ǣ���ʱ�����ǽ�obj2��ָ��ָ����obj1���ڴ棬���ǽ�obj1������������
         *    ��������obj2�У���Ȼobj1��obj2��������ͬ�����Ƕ��ߵĵ�ַ��ȫ��ͬ�����Ÿ�ֵ�������еı������Ὣobj1��ֵ���Ƹ�obj2���еĻḴ��obj1��ֵ��һ����ʱ����
         *    Ȼ���ڵ��ø�ֵ�������=����ͨ�����������������غ���������ʱ�����ֵ����obj2��������һ��ʵ�֣���Ҫ���ж���Ŀ�����
         *
         * ֻҪһ��������new���������ڴ����Ҫ�Զ��忽�����캯�������ظ�ֵ��=���������
         * 1. �������캯������Ҫ�����еĳ�Ա���������������ָ�벻�ܽ�������ֵ��
         * 2. ��ֵ�������������Ҫ��Ϊ��ĳ�Ա�������У�������Ϊ��Ԫ������ͨ��Ա������
         * 3. ��ֵ���������ʱ��Ҫע���������⣺
         *    1. ��Ҫ���ص��ö�������á�
         *    2. ���ܶ���������и�ֵ����������Ҫ�����س���ʼ֮ǰ�ж�this�Ƿ������һ���������ĵ�ַ��
         *    3. ��Ҫ�������ڲ�����Ҫ��ָ���ڴ��ͷŵ���
         * */
        Stock t = Stock("Microsoft");//ʹ�ù��캯��
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
     * ��̬�ĳ�Ա������Ҫ����static�ؼ��֣�������ʵ�ֵ�ʱ����ʹ��static
     * ��ʹ�ö�λnew�������������ڴ�ʱע���ڽ�β����ʹ��delete���ͷ��ڴ棬��������ڲ�Ҳ��new�����ڴ���������Ҫ��ʾ���ö��������������
     * */
    
}

Time operator-(double a, const Time &b);
void Chapter11(){
    using namespace std;
    Time t = Time(10, 15);
    /*
     * �����C++�е���������ء��ܼ򵥣����������ж���һ��operator op()�������ؾͿ��ԡ�
     * ���������Ҳ�кܶ����ƣ�
     * 1. ���ص�������Ĳ������б���������һ�����û��Զ�������ͣ��������������Ϊ��Ա����ʱ���赣��������ƣ���Ȼ���㣬������ʹ�ú������������ʱ��Ҫע����һ���ƣ�
     *    �����������������ǲ������ܵ�double operator*(double a, double b);
     * 2. ��������ز���Υ�������ԭ�еĹ������������Ҫ���������������������س�ֻ��һ����������
     * */
    Time t1 = t + Time(20, 45) + Time(25, 6);
    t.show();
    t1.show();
    /*
     * ����ĵ��ñ������ǣ�t.operator-(15.6)�������ʽ��д��15.6-t��ô�ͻ��޷����㣬��Ϊ�����ĵ��õ�ЧΪ��(15.6).operator-(t)����double��û�����ؼ����������Time����
     * ��ʱ���Ҫʹ�ú��������ؼ������㣺Time operator-(double a, const Time &b)������������ʽ�����������û�н��������˽�б��������⣬Ҫ�����������Ҫ�õ���Ԫ������
     * 1. ��Ԫ�����������Ա�����ǿ��Է������˽�б�����
     * 2. ��Ԫ����Ҫ���������У��Һ���ԭ��ǰ��Ҫ����friend�ؼ��֡��ھ���ʵ��ʱע�ⲻҪʹ��::���������������Ϊ��Ԫ����������ĳ�Ա��������ʵ�ֵ�ʱ��Ҫʹ��friend�ؼ��֡�
     * 3. ��Ԫ��������ʹ��Ĭ��������ʽʵ�֣�Ҳ����ʹ����ʽ������ʽʵ�֣�Ҳ����ʹ�÷���������ʽʵ�֣���ʵ�ַ������ͨ�ĳ�Ա������ͬ��
     * */
    //
    Time t2 = t - 15.66;
    t2.show();
    t2 = 15.6 * t;
    t2.show();

    //��Ԫ
    t2 = 15.6 - t;
    t2.show();
    /*
     * ���������<<���������Ȼ������<<�������������һ�������Ե����⣺������cout << t2�����ĵ��üȿ��Խ��ͳɵ���cout.operator<<(t2)
     * Ҳ���Խ��ͳɵ�����Time�е���Ԫ�������ߵ����˵�������������غ�������Ȼ����߲���ͬʱ���ڣ������������ͻ����֮���Ի�ѡ�������ȫ����Ϊ���ߵ�����������ϵ��ã����������cout��
     * <<��������ұ߲�������Ҫ���ǵ�ͨ���Կ϶���һ��������java��object�Ķ��󣬵�������Ԫ����������ͨ��<<���������������ұ߲���һ���ᱻ��ȷָ��ΪTime�������ڵ���ʱ�ͻ�����ƥ��
     * ����ƥ��ȸߵġ�
     * */
    cout << t2 << t1 << "Hello, world" << endl;
    //һ������
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
     * C++�е�ǿ������ת��������Ҫ�����Ա�ж���operator long/double/int/...() const;
     * ������ǰ�����explicit����Ҫǿ��ת�����С�
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

    //ͷ�ļ���Ҳ���Զ���һ��������������������Ҫ����ÿ��ʹ�õĳ����ļ��ж�����һ�Σ������ͷ�ļ���ֱ�Ӷ��������������Ƽ��ġ�
    inline_function();
    {/*
     * ����һ���������ֱ�������ж��壬��ô�������Ĭ�Ͼ��������Ķ�������ʾд��inline�ؼ��֡�
     * ��һ���棺�෽��Ҳ���Բ������ж��壬����ͷ�ļ��ж��壬���Ǵ�ʱҪ��ʽд��inline�ؼ��֡�
     * ����෽��������private����public�����Բ���������ʽ���壬������������¾Ͳ�����ͷ�ļ��ж��壬��Ϊ����ܻ��������ض������
     * */
        Stock t = Stock("Microsoft");//ʹ�ù��캯��
        t.show();
        cout << "======================" << endl;
        Stock *p = new Stock();
        delete p;
        cout << "======================" << endl;
        /*
         * ���ֽ����б������¸�ֵ����Ϊһ�������һ����ʱ�����������ʱ��������ܿ챻���ٴӶ���������������
         * �����Ķ����ʼ����ʽ���Լ򵥵���Ϊ�ǶԹ��캯���ĵ��ã�ͨ�������б�������������ֵ��õĹ��캯����
         * ʹ��const�ؼ������εĶ���Ӧ�ñ��޸ģ�������ֶ�����õķ���Ҳ�����޸Ķ���
         * ���仰˵const������õķ���������const�ؼ������Σ����ַ����в��ܶԶ�������ݽ����޸�
         * */
        const Stock t1 = {"FaceBook"};
        t1.show();
        /*
         * ��������������е�һ����Ҫ�ؼ��֣�this������ؼ���������ָ����һ��ָ�룬ע����ָ�룬���ָ��
         * ָ��ö�����׵�ַ��Ҳ����ʹ��*this�����������������á�
         * */
        Stock t2 = t1.topval(t);
        t2.show();
    }
    /*
     * ������������Ҫʹ��һЩ�������޶���������ĳ��ȵȵȣ����ǲ���ʹ����ͨ�ĳ�Ա������������£���Ϊ��ͨ�ĳ�Ա����
     * ����û��ʵ����֮ǰ��û��ֵ�ģ���ʹ��������ʱ������ֵconst int size = 15;������ҲҪ����ʵ����֮����ܹ���ֵ��
     * �������鳤�������Ĳ�����Ҫ��ʵ������ʱ��͸���������������ķ�����������
     * 1. ʹ����������ö�١�
     * 2. ʹ�þ�̬const�����������ֱ����������������������������ڼ䣬��һ��Ҫ��const�ؼ��֣�
     * */

    //�������ռ���Ҳ�������ɵ�ʹ����
    {
        ilmare::Person person = ilmare::Person("David", 15, male);
        person.show();
        ilmare::p.show();
    }
}

extern int cat;//ʹ���ⲿ������������function.cpp�У�
/*
 * ���������function.cpp��Ҳ�����ˣ������������ﻹ��Ҫ����һ��ͬ�����ڲ��������ͱ������static�ؼ��֣����򽫻���������
 * ���������ԭ�����ڣ������ʹ��static�ؼ��֣���ôdog��������Ϊȫ�־�̬������������function.cpp���Ѿ�����һ����Ϊdog��ȫ��
 * ��̬��������ͻ�������ͻ�����Ա���ʹ��static�ؼ��֣���ʽ��ָ��dogΪ�ڲ������ſ��ԡ�
 * ָ��Ҳ������Ϊ�ⲿ���ӱ�����
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
     * ��̬������֪ʶ�㣺
     * 1. ��̬���ⲿ�����Եı�����ͨ���ں����ⲻ��������ʹ��static�ؼ��֣����ֱ����������ڳ����ļ��ڲ��ɼ�����������Ŀ�ж��ǿɼ��ģ��ⲿ�����ļ�ʹ��ʱ��Ҫʹ��extern�ؼ��֣�
     * 2. ��̬���ڲ������Եı�����ͨ���ں�����������ʹ��staitc�ؼ��֣����ֱ��������ڳ����ļ��ڲ��ɼ���
     * 3. ��̬���������Եı�����ͨ���ں����ڲ���������������ʹ��staitc�ؼ��֣����ֱ���ֻ�������ĺ����������ڲ��ɼ��������������������������ڼ䣬�뺯��������ĵ����޹ء�
     *    ����ں����������õ�ʱ�����ڱ��溯��״̬��
     * 4. const�ؼ��ֵ�֪ʶ�㣺�����һ����̬����ǰ�����const�ؼ��֣���ô�����Զ�����������static�ؼ��֡������Ļ��ͻᱻ����Ϊһ����̬�ڲ������������ı������Ա�.h��ͷ�ļ�ʹ��
     *    ��Ϊ���ֱ��������ⲿ�����Եģ���˵�ͷ�ļ�����������ļ�include��ʱ�򣬲����������ض��壬���ڲ�������������Щ������include���ͷ�ļ��ĳ����ļ��ڲ��ǿɼ��ģ�������const
     *    �ؼ���������Щ�������ɸ��ġ�
     * */
    int cat= 256;
    /*
     * �ֲ�����������������ͬ�����ⲿ����������ʹ��::�����������ʾָ��ʹ���ⲿ�����򱾵ؾֲ�����������ͬpython�е�global�ؼ���
     * ���Ҫʹ���������Եľ�̬���������ⲿ��������ôֻ��Ҫ���ڲ���̬����ʹ��static�ؼ���������ֵ���ɣ������Զ������ⲿ������һ����Ҫ����static�ؼ��֣���ȱʧ����������ض������
     * */
    cout << "Inner variable is " << cat << ", extern variable is " << ::cat << endl;

    /*
     * ʹ���������Եľ�̬���������־�̬���������ں����л��ߴ��������ֱ����������������������������ڼ䣬�뺯�������������޹ء���Ȼ���ֱ����ں�����������ⲿ�޷����ʵ���
     * ���Ǻ����������ڲ�ȴ��һֱ�ɼ��ģ������ı��������ڱ��溯����״̬����Ϊ��ʹ����������������ı���Ҳ���ᱻ�ͷţ��´κ�������ʱ��Ȼ����ʹ��������������ڲ���״̬�����ᷢ���ı䡣
     * */
    for (int i = 0; i < 3; i ++){
        count();
    }
    /*
     * ����c++�ڲ����ⲿ���ӱ������ܽ᣺
     * 1. �ڲ����ӱ������ں����ⲿ��static�ؼ������εı�����ʹ��const�ؼ������εı���Ҳ���Զ�Ϊ�����static�ؼ������α���ڲ����ӱ��������ֱ�����ǰһ��������ʽ����ǲ����޸ĵģ���
     *    ���ֱ��������ڳ����ļ��ڲ��ɼ���������һ��ͷ�ļ��ж������������ڲ����ӱ���������һ�������ļ���ʹ��#include������Ҳ�ɼ���
     * 2. �ⲿ���ӱ����������������ڲ����ɼ��ı�������ʹ��static�ؼ��֣����Ҫ�������ֱ���Ϊ���ɱ䣬��ô������ǰ�����extern const��֮����Ҫ�������ؼ�������Ϊ�����ֻ��һ��const
     *    ��ô���������Զ��������������Ϊstatic���ڲ����ӱ����������1������˵�ģ���˻��������extern��ʽ˵������һ���ⲿ���ӱ���������Ҫ˵��������.h��β��ͷ�ļ��в�Ӧ�ð���
     *    �ⲿ�����Եı�������Ϊһ��ͷ�ļ����ܻᱻ��������ļ�#include������������ⲿ���ӵı�������ôÿһ��#include���ᶨ��һ���ⲿ�����Եı����������������������ظ�����Ӷ����´���
     * 3. �ڲ������Եı�����ͬһ�������ļ���ֻ������һ�Σ����������������еĲ�ͬ�����ļ�֮��ȴ����������Ρ�
     * 4. �ⲿ�����Եı���������������ֻ������һ�Ρ�
     * 5. ÿһ��#includeͷ�ļ����൱�ڰ�ͷ�ļ��е�����ȫ����������ִ����һ�Σ�����ǧ������ͷ�ļ��ж����ⲿ���ӱ������������ͷ�ļ�ֻ��#includeһ�Σ�����һ������������ظ����塣
     * */
    cout << cats << endl;//��ͷ�ļ��а�����const int cats = 555;

    //�������ڲ��ⲿ�����Ժͱ�������ͬ�ģ�ͬ��Ҳ����ʹ��extern��static�ؼ���
    Chapter9_func();

    //new�����
    /*
     * ʹ��#include�����µ�new�ʹ�ͳ��new�����������ڣ��µ�new����ָ���ڴ����ľ����ַ��
     * �����������ʹ�ô�ͳ��new�ؼ��ֻ��ڳ���Ķѡ�heap���п���һƬ�ڴ棬����������ĳ���Ա�޷���֪������ʹ�����µ�new���������Ҫʹ��#include<new>����Ϳ���ָ��һƬ�ڴ�
     * ������������ƶ���һ��512�ֽڵ�buffer���ʹ�ͳ��new�ؼ��ֲ�ͬ���µ�new������Ҫ����ʹ�ã�new (buffer) double[10]��Ҳ������Ҫ��ʾָ���ڴ�ľ���λ�á�
     * ��Ҫ�ر�˵�����ǣ�ʹ���µ�new����������ڴ治��Ҫ�ͷţ����Ҵ����Ŀ�ʼ��ַ���������еĵ�ַ��Ҳ����˵���ѭ�������Ҳ��������м����ַƫ�����Ļ�����������ڴ�ͻḲ��ԭ�еġ�
     * ��Ҫ�����������ܹ�������������ڴ渲�ǵ�ԭ�е�new (buffer + size * sizeof(double)) double[size]��������һ����ַƫ������
     * ֮���Բ���Ҫ�ͷŵ�ԭ���������ڴ���ڴ��buffer�����ʹ����ڳ������еĶ��У���delete�����ֻ��heap�е��ڴ���Ȩ�޲���������޷�delete��
     * */
    int size = 5;
    char buffer[512];//����һ��512�ֽڵĻ��壬�µ��ڴ潫�������濪��
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
    delete [] pd_1;//ʹ����new������ڴ治��Ҫ�ͷţ�Ҳ�޷����ͷţ�����bufferҲ��ʹ��new�ؼ�������ġ�

    //���ƿռ�
    /*
     * �����ռ��п��԰�����
    ilmare::fetch("David");���ռ䣬���԰����ֶΣ����������������������ռ���Զ�����ͷ�ļ��С��������������ͷ�ļ��оͲ��ܰ����ֶε���������Ϊͷ�ļ����ܻᱻ����ļ�include
     * �����Ļ��ͻ�ִ�ж�������ռ䶨�壬ÿһ�������ռ䶨�嶼�ᶨ��һ���ֶΣ����ͬһ�ֶεĶ�ζ��壬����������������ͷ�ļ��е������ռ����ֻ��������ԭ�͵�������Ȼ����
     * ��һ���ļ��ж������ռ��еĺ�������ʵ�ʵĶ��塣
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

inline double square(double);//Ҳ����ʹ��������������
inline double square(const double x){//ʹ��inline�ؼ���ʵ����������
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

template <typename T>//template <class T>������������C98�ж���
void Swap(T &a, T &b);
template <class T>//����ģ�����أ�����ģ�����غ���ͨ������һ����Ҳ��Ҫ���������겻ͬ��
void Swap(T *a, T *b, int n);
struct job{
    std::string name;
    double salary;
    int floor;
};
template <> void Swap<job>(job &, job &);
/*
 * ��������ͨ�������壻��ͨģ�庯�����壻��ʽ���廯����������ʽ��
 * */
void func(int a, int b);
template <class T>
void func(T a, T b);
template <> void func<int>(int a, int b);

void Chapter8(){
    using namespace std;
    cout << square(20) << endl;//�����������Լӿ�����ִ��ʱ�䣬���ǻ����ӳ�����ڴ濪��

    int rat = 100;
    int &rodent = rat;
    rodent = 150;
    cout << "The address of rat = " << &rat << ", The address of rodent = " << &rodent << endl;

    //C++�е����ñ�����ԭʼ���������������ֲ�ͬ���ѣ�ʵ����������ͬһ����������������һ��Ҳ��Ӱ�쵽��һ��
    int rats = 150;
    int bunnies = 200;
    int &rodents = rats;
    cout << "rats address = " << &rats << ", rodents address = " << &rodents << endl;
    rodents = bunnies;//����rodents��rats�����ã����ִ����һ����൱��ִ��rats=bunnies
    cout << "rats = " << rats << ", bunnies = " << bunnies << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats << ", bunnies address = " << &bunnies << ", rodents address = " << &rodents << endl;
    //���ñ���һ����ʼ������ô���ͳ�Ϊ�Ǹ��ڴ���������б��������ñ���
    int rat_1 = 10;
    int  *p = &rat_1;
    int &rodent_1 = *p;
    int bunnies_1 = 25;
    p = &bunnies_1;
    cout << "rodent_1 = " << rodent_1 << endl;

    /*
     * ���ñ���ʹ���ں����������ݵ�ʱ��Ҫ����С�ģ���Ϊʹ�������ñ��������Ĳ����ں����в�����ʵ���Ͼ��ǵ��ú���������Ǹ�������
     * Ҳ����˵�����ڲ������ñ������޸Ļ�Ӱ�쵽���ú����еı�����
     * �ں�����ʹ�����ñ�����Ϊ��������������Ҫ���ƣ�
     * 1. �����ڵ��ú���ʱһ��Ҫ��������������Ǳ��ʽ������������func(x + 3)��func(3)��
     * 2. ��δ������������Ҫ�ϸ���Ϻ����������Ĳ������ͣ��޷�������ʽ����ת����
     * ��������ں��������ñ���ǰʹ����const�ؼ��֣���ô�ͻᷢ���ܶ�ı䣺
     * 1. ����������������б���ʹ���˴���const���ε����ñ�������ô�ں����оͲ��ܶ�����������иı�ֵ�Ĳ��������縳ֵ��
     * 2. �����Ĵ���const���ε����ñ������Խ������͵���ʽת������������Ϊconst double &a����ʵ�ʵ���ʱ���Դ���һ��int�ͱ�����
     * 3. ���ִ���const���������ñ��������Խ��ձ��ʽ���롣
     * 4. �ڶ����������ʵ��ʵ�����Ǻ����ڵ���ʱ������һ����ʱ���������ڴ���const�ı����������޸ģ������һ���������ģ������ʹ��������ʱ����Ҳ���������κ����⡣
     * */
    int a = 20;
    int b = 25;
    //�����ĵ����ǽ�ֹ�ģ���Ϊ�����ñ�����ֵ����һ�����ʽ��������һ�������������ñ���û��ʹ��const�ؼ�������
    //swap(a + 20, b);
    int x = 10;
    cout << cube(x) << endl;//������const�ؼ������Σ����֧�ֳ��������ʽ��ֵ���һ�֧����ʽ����ת��
    cout << cube(x + 10) << endl;

    //����Ҳ���Է���һ�����������ã�
    double param_double = 25.6;
    /*
     * �����ﷵ�ص���param_double���������ã���˵�Ȼ���Զ�����и�ֵ����������������ﷵ�ص���һ��ֵ����ô�����﷨���Ǵ����
     * ԭ�����ڣ�������ص���ֵ����ô����һ�������������ǲ��ܹ�����ֵ�����ģ�ָ��Ҳ����ˣ�������������ص���һ�����ã���ô������þͿ��Ա����¸�ֵ��
     * �������ں��������ص���param_double�����ã���˶�������õĸ�����Ȼ�ͷ�ӳ����param_double�������ϡ�
     * �����Ҫ��ֹ���ֲ�������Ҫ�ں�������ֵǰ�����const�ؼ��֣��������޷������ˡ�
     * ��󣺷���������Ҫע�ⲻ�ܷ��غ����е���ʱ���������ã���Ϊ���ֱ�������������ֻ�Ǻ���ִ�е��������ڣ���һ�����ֵ���صĺ����л�û�����⣨��Ϊ��������·���ֵ�Ǳ�������ĳ���Ĵ����ģ�
     * ���������÷��أ���ô������������ʱ�������ڴ汻�ͷţ��������þͻ�ʧЧ������취��������
     * 1. ��������Ĳ����б��������ò�������ô���ز����б��е����ñ�����
     * 2. ���һ��Ҫ���غ����е���ʱ��������ôһ��Ҫʹ��new�ؼ�������̬�����ڴ档
     * ��һ�����ñ�����ֵ��һ����ͨ���������Ƿǳ���Ч�ģ�����ֱ�Ӹ�ֵ������������м�����
     * */
    modify(param_double) = 56.9;//
    cout << param_double << endl;

    //Ĭ�ϲ�����������Ĭ�ϲ�����Ҫ�������ں��������б���Ҳ࣬���ܳ���Ĭ�ϲ����ͷ�Ĭ�ϲ���������е����
    printTest(3);

    //�������أ����ں�������ֻ��֪��һ�����Ǿ��Ǳ�����ֻʹ�������꣨�����������б��в��������ͺ�����˳��������ͬ���������������ķ���ֵû�й�ϵ
    print("I love you", 5);
    print(4);

    /*
     * ��ʹ�ú���ģ��ʱ�������ĺ���ģ�岢��������һ������ʵ����ͨ���ڵ���ʱ�Ż����ʹ���߶���ķ�������ȥ����ģ������һ������ʵ������ʾ���廯���庯������Ϊ���ƿ�����ģ�壬
     * ������ͬ������������ģ�庯������������ʾ���廯�����ĵ������ȼ�����ģ�庯��������ڵ���ʱ������ƥ����ʾ���廯����ĺ�����
     * ͨ������ʹ��ʱ�Ÿ���ʹ���ߴ���ķ������ͺͺ���ģ����ʵ������������ʽ����Ϊ����ʽʵ��������ʹ��template void<typename>(paramA, paramB)�����ĺ���������ʽ���ǡ���ʽʵ������
     * ������ʽ����ʽ���廯�ǳ����ƣ����ǲ�ͬ����ȱ������ʾ���廯��template�ؼ��ֺ����<>
     * ��Ҫ�ĸ��
     * 1. ��ʽ���廯
     * 2. ��ʾʵ����
     * 3. ��ʽʵ����
     * ��Ҫ˵����
     * 1. ����ģ�����ʹ��template <class T>������������C98�ж��壬Ҳ����ʹ��template <typename T>����������
     * 2. ����ģ�����أ�����ģ�����غ���ͨ������һ����Ҳ��Ҫ���������겻ͬ��
     * 3. ��ʽ���廯���庯�����Ǻ���ģ�壩�����ֲ�ģ�庯������������������⣨������Դ���ṹ���еĵ����������ͨ����ʹ���е���һ�����������������ʹ����ͨ��ʽ�������
     *    ������ͨģ�巽ʽ�������������ʽ���廯�ķ�ʽ���������ô�ڵ���ʱͨ����ѭ�����ȼ����ȱ����ȣ���ͨ�����ĵ������ȼ� > ��ʾ���廯����ĺ������ȼ� > ��ͨģ�庯�������ȼ�
     * 4. ��׷��һ�㣺�ڵ���ʱ��Ȼ����ֱ��ʹ�ú��������ñ�������ѡ����ʵĺ����汾������Ҳ������ʽ��ָ����func()�����ĵ��þ����ñ�������ѡ�����汾��func<>()�����ĵ���
     *    ����ȷָ���ں���ģ����ѡ��ѡ��Χ������ʾ���廯�İ汾����func<typename>()����ʾʵ����һ������ģ��
     * */
    int aa = 50;
    int bb = 46;
    Swap(aa, bb);//ģ�庯��
    cout << aa << " " << bb << endl;

    int a_array[5] = {1,2,3,4,5};
    int b_array[5] = {6,7,8,9,10};
    Swap(a_array, b_array, 5);//����ģ������
    for (int i = 0;i < 5; i ++){
        cout << a_array[i] << " ";
    }
    cout << endl;


    job j1 = {"David", 9500.43, 5};
    job j2 = {"Smith", 5400.69, 1};
    Swap(j1, j2);//��ʽ���廯
    cout << j1.name << " -> " << j1.salary << " -> " << j1.floor << endl;
    cout << j2.name << " -> " << j2.salary << " -> " << j2.floor << endl;

    func<>(12, 34);//��ʽָ��ʹ�ú���ģ�壬��ʹ����ͨ��������
    func<double>(12, 34);//��ʽʵ��������һ��double�͵ĺ���

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


template <> void Swap<job>(job &a, job &b){//ͨ��������ôд��
    double t1;
    t1 = b.salary;
    b.salary = a.salary;
    a.salary = t1;
    int t2;
    t2 = b.floor;
    b.floor = a.floor;
    a.floor = t2;
}

template <typename T>//template <class T>������������C98�ж���
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
double cube(const double &param){//ʹ����const�ؼ��֣���ζ��param�ǲ��ɱ��޸ĵģ���Ͷž������ñ����޸�ԭֵ�Ŀ���
    return param * param * param;
}
void simple(int n, ...){//�ɱ����
    using namespace std;
    va_list lst;//��ȡ�ɱ�����б�
    _crt_va_start(lst, n);//��֪�ɱ������ʼλ�ã��������һ���̶�����
    double a = _crt_va_arg(lst, double);//��һ���ɱ����
    double b = _crt_va_arg(lst, double);//�ڶ����ɱ����
    _crt_va_end(lst);//�����Կɱ������ʹ��
    cout << a << " - " << b << endl;
}

int sumArray(int *array, int count){
    int sum = 0;
    for (int i = 0; i < count; i ++){
        array[i] = i + 1;
    }
    return sum;
}

int sumArrayRange(const int *pHead, const int *pEnd){//��������ȡһ���ķ�Χ���в���������ǿ������Ϊcosnt
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
     * ��Ȼ������һ��string���͵�ָ�룬�������ָ��Ҳֻ��ԭ��ָ���һ��������
     * ����ָ�����ڴ��ַҲֻ�ǽ�����ָ���ĵ�ַ�������������������Ҳ�ᱻɾ������ԭ��ָ�벻������κ�Ӱ��
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
    simple(3, 5.6, 2.5);//���ݿɱ����
    /*
     * ��ǰ�����const�ؼ��֣������������ǲ��ɸ��ĵ�,
     * �ұ������й涨����ֹ��const���εı�����ֵ����const���εı�����Ҳ����˵�����������arrayǰ�����const���Σ�
     * �������sumArray�������ý�������ΪsumArray�Ĳ����б��е�arrayǰ��û�м�const���η�
     * */
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << sumArray(array, 20) << endl;//��������ָ��
    for (int a : array){
        cout << a << " -> ";
    }
    cout << endl << sumArrayRange((array + 5), (array + 9)) << endl;

    /*
     * ��δ���ܺõ�ڹ����const��*�Ĺ�ϵ���ص�����const���ڵ�λ�á�
     * ������˵�����const��*����ߣ���*val��const�ģ���val��������
     * ��const��*���ұߣ���val������const�ģ�����*valȴ���ǡ�
     * */
    int a = 20;
    const int *pa = &a;
    int b = 40;
    pa = &b;
    cout << "*pa is " << *pa << endl;
    int * const pa_1 = &a;
    *pa_1 = 55;
    cout << "a is " << a << endl;
    //��ά����
    int matrix[2][3] = {
            {1,2,3},
            {4,5,6}
    };
    cout << sumTwoDimMatrix(matrix, 2) << endl;
    //�����ַ
    int at[5] = {1,2,3,4,5};
    int (*atp)[5] = &at;
    int *atpp = at;
    cout << (*atp)[0] << *(*atp + 2)<< endl;
    //�ں�����ʹ��string
    string str = "I love my country";//string���͵Ĳ����ο�java
    show_string(&str);//����ָ��ʱ����ʵҲ�Ǵ�����һ��ָ��Ŀ���
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
    //�ݹ�
    cout << endl << recurs(100) << endl;

    //����ָ��
    estimate(10, pam);

    double *(*pfunc[3])(const double*, int) = {func1, func2, func3};//����ָ������
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
    double result = (*pf)(lines);//���ֵ��ö��ǿ��Եģ�ֻ����ʱ˵����Ϊʲô������
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

    //�ļ��Ķ�ȡ��д��
    ofstream out;
    out.open(outputPath);
    string fileContent = u8"����һ������";
    out.setf(ios_base::hex, ios_base::basefield);//���ø�ʽ�������Ŀ
    out.setf(ios_base::right, ios_base::adjustfield);
    out.precision(5);//�������㾫��
    out.setf(ios_base::showpoint);//��ʾС����
    out << fileContent;
    out << endl;
    out << "0x" << 128 / 5 << endl;
    out.close();

    char content[1000];
    ifstream input;
    input.open(inputPath);
    if (!input.is_open()){//����Ƿ��Ѿ�����
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
    //C++��Ȼ��������pythonһ����д������
    for (int i = 0; i < 2; i ++)
        cout << "Hello,world" << endl;
    long delay = 2;
    delay *= CLOCKS_PER_SEC;
    clock_t  start = clock();//��python�е�clock()��������
    while (clock() - start <= delay);//�ӳ�
    cout << start << " -> " << clock() << endl;

    //���ڷ�Χ��forѭ����������Java�е���ǿforѭ������C++11�ж���
    double prices[5] = {5.4, 56.3, 5.3, 9.5, 4.3};
    for (double item : prices)
        cout << item << endl;
    for (double &item : prices)//ʹ��&���Ŵ����Ǵ��ݱ������ã�����������ֵ����
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
    //����
    int array[4] = {1,2,3,5};
    for (int i = 0; i < 4; i ++){
        cout << array[i] << endl;
    }
    int a[5] = {1, 2};//��ֻ�������һ���ָ�ֵ�������ಿ��Ϊ0
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
    //�ַ���
    char str[] = "I love my country";
    cout << str << endl;
    char str1[] = {'I', ' ', 'l', 'o', 'v', 'e', ' ', 'm', 'y', ' ', 'c', 'o', 'u', 'n', 't', 'r', 'y', 0};
    cout << str1 << endl;
    char str2[8] = {'I', ' ', 'l', 'o', 0, 'v', 'e', ' '};
    cout << str2 << endl;
    /*
     * ��ͳ��cin�����Կո�Ϊ����ָ��Ҫ�����һ���ַ����д��пո����ܺܺõ�¼�룬
     * ֻ��¼��ո�ǰ���ַ������ո����ַ����ᱻ���浽��������й����������ʹ��
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
//    cin.getline(str3, 30);//һ��������������һ������˵��Ҫ�����Ŀ���ַ������ڶ�������˵��Ҫ����ĳ��ȣ��Ի���EnterΪ��β�����������з�
//    cout << str3 << endl;
//    char name1[30];
//    char name2[30];
//    cin.getline(name1, 30).getline(name2, 30);
//    cin.get(name1, 30).get();
    /*
     * ����������cin.get���������ܻ��з�����˻��з����������뻺���
     * ����һ�����뵽��ʱ�ͻὫ������з���Ϊ��һ������Ӷ����´��������һ��cin.get�������ס������з���
     * */
//    cin.get(name2, 30);
//    cout << name1 << name2 << endl;

    //string��
//    string str4 = "I love my country";
//    str4 = {"I am Chinese\n"};//��ͬ��string��ʼ����ʽ
//    string str5{"I love my country"};
//    cout << str4 << " - " << str4.size() << " - " << str4.length() << endl;
//    cout << str4 + str5 << endl;
//
//    char charr[20];
//    cout << "Length of string in charr before input: "
//         << strlen(charr) << endl;
//    string str6;
//    getline(cin, str6);//һ���µ�string���͵����뷽��
//    cout << str6 << endl;
//
//    string str7 = u8"I am a Chinese, and I love my country";//ʹ��UTF-8����
//    cout << str7 << endl;

    cout << R"(I am a Chinese, \nand I love my Country)" << endl;//��ֹת��
    cout << R"asd((Please tell my who yu are), I love you)asd" << endl;//����ɣ�p88�н��ͣ�������Ҫ��Ϊ�˽���ַ����д����ŵ����

    //�ṹ��
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

    //������
    struct widget{
        std::string name;
        int type;
        union {
            /*
             * �����壬����һ���ֶε����Ϳ����Ƕ��ֵ�����£�
             * �������������id�����Ϳ�����һ�������Σ�
             * Ҳ������һ���ַ������ͣ�����Ϳ����õ������塣
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

    //ö������
    enum spectrum {
        /*
         * ö�����ͱ����ϻ������Σ���0��ʼ����
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
    band = spectrum(112);//ö��ֵ���ڻ�����int�ʹ��ڵģ����Ҳ���Խ�ö��ֵ��ֵ��Ϊ�ڲ����ڵ�ö��ֵ��ֻҪ��������������޺�С����С���ޡ�
    cout << band << endl;

    //ָ��
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
    cout << sizeof(a_array) << " -> " << sizeof(a_p) << endl;//�������ָ��ʹ��sizeof������ǰ�߽��õ���������Ĵ�С�������ߵõ�����ָ��Ĵ�С
    cout << a_p[0] << " -> " << *(a_p + 1) << " -> " << *(a_p_1 + 2) << endl;

    //ָ��������
    char animal[20] = "animal";
    /*
     * ����ͬcout << "bear"���Ա���ӡ����һ�����ַ��������������Ÿ��ַ������׵�ַ��
     * ��������ĸ�ֵ�ǿ��Խ��ܵģ���int *a = 25�����Ĳ����ǽ�ֹ�ģ���Ϊa��û�б���ʼ����
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
    stu **pStu = p;//����*��ͨ������ָ��ָ�������ָ�룬һ��Ҫ��ס
    cout << pStu[0]->name << " -> " << pStu[1]->name << " -> " << pStu[2]->name << endl;
    cout << pStu[0] << " -> " << pStu[1] << " -> " << pStu[2] << endl;

    //vector��array
    vector<int> int_v(3);//�����vectorģ����ĳ�ʼ����ʽ������������Ǹ�vector�������������ñ������棬��ζ�����С�ڳ�������ʱʱ�ɱ�ġ�
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
     * �����µĲ��ִ���
     * */
    using namespace std;//�����ں����ڲ�ʹ������using����ָ�������Ϊ�ú������ڲ���
    cout << "max char is " << CHAR_MAX << ", max int is " << INT_MAX << ", short int is " << SHRT_MIN << endl;

    int enums{5}, ban = {20};//c++11�е�һ�ָ�ֵ������
    cout << enums << " " << ban << endl;

    int a = 91, b = 042, c = 0x1a;//��ͬ���Ƶ����θ�ֵ
    cout << a << " " << b << " " << c << endl;
    cout << hex << b << endl;//����ͨ��������hex��oct��dec��ֵ������������ֵĽ���
    cout << sizeof(long long) << endl;
    a = 2220UL;
    cout << dec << a << " " << sizeof(2220uL) << endl;

    char ch = 77;
    cout << "This input char is " << ch << endl;

    cout.put('2');//��ֻ��һ����ʷԭ�򣬲�������
    cout << '$' << endl;
    cout << "Let them eat g\u00E2teau" << endl;
    cout << sizeof(wchar_t) << endl;
    char16_t ann = u'\u00e2';
    cout << "ann is " << ann << endl;

    const int Month = 12;
    cout << Month << endl;

    float e = 1.0;
    float f = 3.0;
    cout.setf(ios_base::fixed, ios_base::floatfield);//����ǿ�ƹ涨�������Ĵ�ӡλ������ֹ�ѹ���ĸ�������ӡ��E��ʾ�ĸ�����
    cout << e / f << endl;

    int thorn = 3;
    double thorn_d = static_cast<double>(thorn);//ǿ��ת��
    cout << thorn_d << endl;
}
void Chapter2(){
    /*
     * �ڶ��µĲ��ִ���
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