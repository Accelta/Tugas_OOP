#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <mutex>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::list<Observer*> observers;
    std::mutex mtx;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify();
};

#endif
