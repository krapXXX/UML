#include <iostream>
#include <string>

using namespace std;

class TransportMode 
{
protected:
    double price;
    int time;

public:
    TransportMode(double p, int t) : price(p), time(t) {}

    virtual string ModeName() const = 0;

    double CalculatePrice() const 
    {
        return price;
    }

    int EstimateTime() const 
    {
        return time;
    }

    virtual ~TransportMode() = default;
};

class Bicycle : public TransportMode 
{
public:
    Bicycle(double p, int t) : TransportMode(p, t) {}

    string ModeName() const override 
    {
        return "Bicycle";
    }
};

class Shuttle : public TransportMode 
{
public:
    Shuttle(double p, int t) : TransportMode(p, t) {}

    string ModeName() const override 
    {
        return "Shuttle Bus";
    }
};

class Cab : public TransportMode 
{
public:
    Cab(double p, int t) : TransportMode(p, t) {}

    string ModeName() const override 
    {
        return "Cab";
    }
};


class TravelPlanner 
{
private:
    TransportMode* mode = nullptr;

public:
    void ChooseMode(TransportMode* m) 
    {
        mode = m;
    }

    void ShowDetails() const 
    {
        if (mode) 
        {
            cout << mode->ModeName() << " selected.\n";
            cout << "Price: $" << mode->CalculatePrice() << "\n";
            cout << "Time: " << mode->EstimateTime() << " minutes\n\n";
        }
    }
};

int main() 
{
    TravelPlanner planner;

    TransportMode* bike = new Bicycle(0.0, 60);
    TransportMode* bus = new Shuttle(2.0, 35);
    TransportMode* taxi = new Cab(5.5, 20);

    planner.ChooseMode(bike);
    planner.ShowDetails();

    planner.ChooseMode(bus);
    planner.ShowDetails();

    planner.ChooseMode(taxi);
    planner.ShowDetails();

    delete bike;
    delete bus;
    delete taxi;

    return 0;
}
