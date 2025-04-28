#include "Product.h"
#include "Customer.h"

int main() {
    Product* iphone = new Product("iPhone 15 Ultra");
    Product* pixel = new Product("Google Pixel 9 Pro");

    Observer* customer1 = new Customer(iphone, "742 Evergreen Terrace");
    Observer* customer2 = new Customer(iphone, "1313 Mockingbird Lane");
    Observer* customer3 = new Customer(iphone, "21 Jump Street");
    Observer* customer4 = new Customer(pixel, "12 Grimmauld Place");
    Observer* customer5 = new Customer(pixel, "4 Privet Drive");

    iphone->subscribe(customer1);
    iphone->subscribe(customer2);
    iphone->subscribe(customer3);

    pixel->subscribe(customer4);
    pixel->subscribe(customer5);

    pixel->setAvailable(true);
    pixel->alert();

    iphone->setAvailable(true);
    iphone->alert();

    delete iphone;
    delete pixel;

    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;
    delete customer5;

    return 0;
}
