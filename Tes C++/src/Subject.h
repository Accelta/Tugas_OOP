#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>
#include <mutex>

class Subject {
private:
    std::list<Observer*> observers;
    std::mutex mtx;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify();
};

#endif // SUBJECT_H
