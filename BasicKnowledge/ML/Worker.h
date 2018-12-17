//
// Created by Administrator on 2018/12/17.
//

#ifndef BASICKNOWLEDGE_WORKER_H
#define BASICKNOWLEDGE_WORKER_H

#include <string>
class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker():fullname("NULL"), id(-1){}
    Worker(const std::string &s, long n):fullname(s), id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void show() = 0;
};

class Waiter: virtual public Worker{
private:
    int panache;
protected:
    void Data() const;
    void Get();

public:
    Waiter(): Worker(), panache(0){}
    Waiter(const std::string &s, long n, int p = 0): Worker(s, n), panache(p){}
    Waiter(const Worker &w, int p = 0):Worker(w), panache(p){}
    void Set();
    void show() const;
};

class Singer: virtual public Worker{
protected:
    enum{
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    enum{
        VTypes = 7
    };
    void Data() const;
    void Get();

private:
    static char *pv[VTypes];
    int voice;
public:
    Singer():Worker(){}
    Singer(const std::string &s, long n, int p = other):Worker(s, n), voice(p){}
    Singer(const Worker &w, int v = other): Worker(w), voice(v){}
    void Set();
    void show() const;
};

class SingerWaiter: public Singer, public Waiter{
protected:
    void Data() const;
    void Get();

public:
    SingerWaiter(){}
    SingerWaiter(const std::string &name, long n, int p = 0, int v = other):
    Worker(name, n), Waiter(name, n, p), Singer(name, n, v){}

    void show();
    void Set();
};


#endif //BASICKNOWLEDGE_WORKER_H
