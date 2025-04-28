#pragma once

#include <string>
#include "Subject.h"

class Product : public Subject {
private:
    std::string productName;
    bool available;

public:
    Product(const std::string& name);

    void setAvailable(bool status);
    bool isAvailable() const;
    std::string getName() const;
};
