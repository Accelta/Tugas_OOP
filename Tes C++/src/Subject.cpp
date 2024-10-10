#include "Subject.h"
#include <mutex>
#include <list>

using namespace std;

void Subject::addObserver(Observer* observer) {
    lock_guard<mutex> lock(mtx);
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    lock_guard<mutex> lock(mtx);
    observers.remove(observer);
}

void Subject::notify() {
    lock_guard<mutex> lock(mtx);
    for (Observer* observer : observers) {
        observer->update();
    }
}
