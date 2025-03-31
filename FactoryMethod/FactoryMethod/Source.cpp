#include <iostream>
using namespace std;

class Transport abstract
{
public:
	virtual void deliver() = 0;
};

class Truck : public Transport
{
public:
	Truck()
	{
		cout << "Truck - Created\n";
	}
	void deliver() override
	{
		cout << "Delivering by road.\n";
	}
};

class Ship : public Transport
{
public:
	Ship()
	{
		cout << "Ship - Created\n";
	}
	void deliver() override
	{
		cout << "Delivering by water.\n";
	}
};


class Logistics abstract
{
public:
	virtual Transport* CreateTransport() = 0;
	virtual void PlanDelivery()
	{
		Transport* transport = CreateTransport();
		transport->deliver();
		delete transport;
	}
};

class RoadLogistics : public Logistics
{
public:
	Transport* CreateTransport() override
	{
		return new Truck();
	}
};

class SeaLogistics : public Logistics
{
public:
	Transport* CreateTransport() override
	{
		return new Ship();
	}
};



void main()
{
	Logistics* logistics = new RoadLogistics();
	logistics->PlanDelivery();
	delete logistics;

	logistics = new SeaLogistics();
	logistics->PlanDelivery();
	delete logistics;

	system("pause");
}
