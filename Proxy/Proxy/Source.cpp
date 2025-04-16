#include<windows.h>
#include <iostream>
#include <string>
using namespace std;

class IPayment
{
public:
	virtual void Pay(double amount) abstract;
	virtual void Cash() abstract;
	virtual void Card() abstract;
};

class Payment : public IPayment
{
public:
	Payment()
	{
		cout << "Getting price. Wait...\n";
		Sleep(1500);
	}
	void Pay(double amount)
	{
		cout << "Paying " << amount << " dollars.\n";
	}
	void Cash()
	{
		cout << "Paying by cash.\n";
	}
	void Card()
	{
		cout << "Paying by card.\n";
	}
};

class PaymentProxy : public IPayment
{
	Payment* pay;
public:
	PaymentProxy()
	{
		pay = nullptr;
	}
	~PaymentProxy()
	{
		delete pay;
	}
	void Pay(double amount)
	{
		if (pay == nullptr)
		{
			pay = new Payment();
		}
		pay->Pay(amount);
	}
	void Cash()
	{
		if (pay == nullptr)
		{
			pay = new Payment();
		}
		pay->Cash();
	}
	void Card()
	{
		if (pay == nullptr)
		{
			pay = new Payment();
		}
		pay->Card();
	}
};

void client(IPayment* p)
{
	double amount;
	cout << "Enter amount to pay: ";
	cin >> amount;

	p->Pay(amount);

	string method;
	cout << "Will you pay by cash or card? ";
	cin >> method;
	while (method != "cash" && method != "card")
	{
		cout << "Invalid payment method. Please enter 'cash' or 'card': ";
		cin >> method;
	}
	if (method == "cash")
	{
		p->Cash();
	}
	else if (method == "card")
	{
		p->Card();
	}
	
}

int main()
{
	IPayment* p = new PaymentProxy();
	client(p);
	delete p; 
	system("pause");
	return 0;
}


