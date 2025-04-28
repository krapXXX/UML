#include "Product.h"
#include <algorithm>
#include <iostream>
using namespace std;
Product::Product(const std::string& name) : productName(name), available(false) {}

void Product::setAvailable(bool status) {
    available = status;
}

bool Product::isAvailable() const {
    return available;
}

std::string Product::getName() const {
    return productName;
}

void Subject::subscribe(Observer* observer) {
    subscribers.push_back(observer);
}

void Subject::unsubscribe(Observer* observer) {
    auto it = find(subscribers.begin(), subscribers.end(), observer);
    if (it != subscribers.end()) 
    {
        subscribers.erase(it);
    }
}

void Subject::alert() {
    for (auto* obs : subscribers) {
        obs->onNotify();
    }
}
