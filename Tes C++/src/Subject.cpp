#include "Subject.h"

void Subject::addObserver(Observer* observer) {
    std::lock_guard<std::mutex> lock(mtx);
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    std::lock_guard<std::mutex> lock(mtx);
    observers.remove(observer);
}

void Subject::notify() {
    std::lock_guard<std::mutex> lock(mtx);
    for (Observer* observer : observers) {
        observer->update();
    }
}
