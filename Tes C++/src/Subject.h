#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>
#include <mutex>

using namespace std;

class Subject {
private:
    list<Observer*> observers;
    mutex mtx;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify();
};

#endif // SUBJECT_H
