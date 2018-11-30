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
inline double suqare(double);//Ҳ����ʹ��������������
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
void Swap(T &a, T &b){
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}

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
    printTest(3, '.');

    //�������أ����ں�������ֻ��֪��һ�����Ǿ��Ǳ�����ֻʹ�������꣨�����������б��в��������ͺ�����˳��������ͬ���������������ķ���ֵû�й�ϵ
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