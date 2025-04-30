#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Dispatch;
class Aircraft
{
protected:
	Dispatch* controller;
	string call;
public:
	Aircraft(const string& call, Dispatch* controller) :call(call), controller(controller) {}

	virtual void send(const string& message) = 0;
	virtual void receive(const string& message) = 0;
	virtual ~Aircraft() = default;
	const string& getCall()
	{
		return call;
	}
};

class Dispatch abstract
{
public:
	virtual void registerAircraft(Aircraft* aircraft) = 0;
	virtual void sendMessage(Aircraft* sender, const string& message) = 0;
	virtual ~Dispatch() = default;
};

class AirportTower :public Dispatch
{
private:
	vector<Aircraft*> aircrafts;
public:
	void registerAircraft(Aircraft* aircraft) override
	{
		aircrafts.push_back(aircraft);
		cout << "Aircraft " << aircraft->getCall() << " registered" << endl;
	}
	void sendMessage(Aircraft* sender, const string& message) override
	{
		cout << "Tower shares message from " << sender->getCall() << ": " << message << endl;
		for (auto aircraft : aircrafts)
		{
			if (aircraft != sender)
			{
				aircraft->receive(message);
			}
		}
	}
	~AirportTower() override
	{
		cout << "Tower shutting down." << endl;
	}
};

class Landing :public Aircraft
{
public:
	Landing(const string& call, Dispatch* controller) :Aircraft(call, controller)
	{
		controller->registerAircraft(this);
	}
	void send(const string& message) override
	{
		cout << "Landing aircraft " << call << " sending: " << message << "\n";
		controller->sendMessage(this, message);
	}

	void receive(const string& message) override
	{
		cout << "Landing aircraft " << call << " received: " << message << "\n";
	}
};

class Departing :public Aircraft
{
public:
	Departing(const string& call, Dispatch* controller) : Aircraft(call, controller)
	{
		controller->registerAircraft(this);
	}

	void send(const string& message) override
	{
		cout << "Departing aircraft " << call << " sending: " << message << "\n";
		controller->sendMessage(this, message);
	}

	void receive(const string& message) override
	{
		cout << "Departing aircraft " << call << " received: " << message << "\n";
	}
};

int main() {
	AirportTower tower;

	Landing flight101("FL101", &tower);
	Departing flight202("FL202", &tower);
	Landing flight303("FL303", &tower);

	cout << "\nCommunication:\n";
	flight101.send("Requesting landing clearance");
	flight202.send("Ready for takeoff");
	flight303.send("On final approach");

	return 0;
}