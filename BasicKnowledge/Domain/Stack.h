//
// Created by Administrator on 2018/12/10.
//

#ifndef BASICKNOWLEDGE_STACK_H
#define BASICKNOWLEDGE_STACK_H

#include <string>
class customer{
private:
    std::string name;
    int age;
public:
    friend std::ostream &operator<<(std::ostream &os, const customer &s);
};
inline std::ostream &operator<<(std::ostream &os, const customer &s){
//    os << "\{" << s.name << ", " << s.age << "\}";
    return os;
}

typedef customer Item;

class Stack {
private:
    struct Node{
        Item item;
        Node *p_next;
    };
    Node *p_first;
    Node *p_current;
    int stack_size;
    int index;
public:
    Stack();//默认构造函数，作为一个栈，不应该提供默认构造函数之外的构造函数
    ~Stack();//析构函数，释放全部链表
    int get_size();
    bool push(Item &item);
    Item pop();

    friend std::ostream &operator<<(std::ostream &os, const Stack &s);
};


#endif //BASICKNOWLEDGE_STACK_H
