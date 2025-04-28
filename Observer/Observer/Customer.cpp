#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(Product* product, const std::string& addr)
    : interestedProduct(product), address(addr) {
}

void Customer::onNotify() {
    if (interestedProduct->isAvailable()) 
    {
        cout << address << ": Received notification - " << interestedProduct->getName()
            << " is now in stock!" << std::endl;
    }
}

void Customer::changeProduct(Product* product) 
{
    interestedProduct = product;
}
