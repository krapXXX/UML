#pragma once

#include <vector>
#include "Observer.h"

class Subject {
protected:
    std::vector<Observer*> subscribers;
public:
    virtual void subscribe(Observer* observer);
    virtual void unsubscribe(Observer* observer);
    virtual void alert();
    virtual ~Subject() = default;
};
