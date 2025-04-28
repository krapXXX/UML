#pragma once

#include <string>
#include "Observer.h"
#include "Product.h"

class Customer : public Observer {
private:
    std::string address;
    Product* interestedProduct;

public:
    Customer(Product* product, const std::string& addr);

    void onNotify() override;
    void changeProduct(Product* product);
};
