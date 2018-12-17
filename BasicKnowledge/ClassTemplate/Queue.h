//
// Created by Administrator on 2018/12/17.
//

#ifndef BASICKNOWLEDGE_QUEUE_H
#define BASICKNOWLEDGE_QUEUE_H

#include <iostream>
template <class T>
class Queue {
private:
    struct Node{
        T content;
        Node *pnext;
    };
    Node *pHead;
    Node *cursor;
    static const int QUEUE_LIMIT = 60;
public:
    Queue(){
        pHead = new Node[1];
        pHead->pnext = NULL;
        cursor = pHead;
        cursor->pnext = NULL;
    }
    bool en_queue(const T &con);
    T de_quese();
    ~Queue();
};
template <class T>
bool Queue<T>::en_queue(const T &con) {
    for (cursor = pHead; cursor->pnext; cursor = cursor->pnext);
    Node *p = new Node[1];
    p->content = con;
    cursor->pnext = p;
    cursor = p;
    cursor->pnext = NULL;
}

template <class T>
T Queue<T>::de_quese() {
    if (pHead->pnext == NULL){
        return T();
    }
    Node *tmp = pHead->pnext;
    T return_obj = tmp->content;
    pHead->pnext = tmp->pnext;
    tmp->pnext = NULL;
    delete []tmp;
    return return_obj;
}

template <class T>
Queue<T>::~Queue() {
    Node *next;
    for (Node *p = pHead; p; p = next){
        next = p->pnext;
        delete []p;
    }
}
#endif //BASICKNOWLEDGE_QUEUE_H
