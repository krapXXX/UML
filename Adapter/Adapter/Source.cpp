#include <iostream>
using namespace std;

class ITransport abstract
{
public:
	virtual void Drive() abstract;
};

class Auto : public ITransport
{
public:
	void Drive() override
	{
		cout << "The car drive on the road.\n";
	}
};

class Driver
{
public:
	void Travel(ITransport * transport)
	{
		transport->Drive();
	}
};

class IAnimal abstract
{
public:
	virtual void Move() abstract;
};

class Camel : public IAnimal
{
public:
	void Move() override
	{
		cout << "Camel rides on the sands of the desert.\n";
	}
};
class Elephant : public IAnimal
{
public:
	void Move() override
	{
		cout << "Elephant rides on the ground of the tropical forest.\n";
	}
};
class Horse : public IAnimal
{
public:
	void Move() override
	{
		cout << "Horse rides on the ground of the field.\n";
	}
};
class Deer : public IAnimal
{
public:
	void Move() override
	{
		cout << "Deer rides on the ground of the forest.\n";
	}
};

class CamelToTransportAdapter : public ITransport
{
	Camel camel;
public:
	CamelToTransportAdapter(Camel animal)
	{
		camel = animal;
	}
	void Drive()
	{
		camel.Move();
	}
};

class ElephantToTransportAdapter : public ITransport
{
	Elephant elephant;
public:
	ElephantToTransportAdapter(Elephant animal)
	{
		elephant = animal;
	}
	void Drive()
	{
		elephant.Move();
	}
};

class HorseToTransportAdapter : public ITransport
{
	Horse horse;
public:
	HorseToTransportAdapter(Horse animal)
	{
		horse = animal;
	}
	void Drive()
	{
		horse.Move();
	}
};	

class DeerToTransportAdapter : public ITransport
{
	Deer deer;
public:
	DeerToTransportAdapter(Deer animal)
	{
		deer = animal;
	}
	void Drive()
	{
		deer.Move();
	}
};
	

int main()
{
	Driver driver;
	Auto car;
	ITransport * transport = &car;	
	driver.Travel(transport);

	ITransport* transport1;
	ITransport* transport2;
	ITransport* transport3;


	Camel camel;
	Elephant elephant;
	Horse horse;
	Deer deer;

	CamelToTransportAdapter adapter(camel);
	ElephantToTransportAdapter adapter1(elephant);
	HorseToTransportAdapter adapter2(horse);
	DeerToTransportAdapter adapter3(deer);

	transport = &adapter;
	transport1 = &adapter1;
	transport2 = &adapter2;
	transport3 = &adapter3;

	driver.Travel(transport);
	driver.Travel(transport1);
	driver.Travel(transport2);
	driver.Travel(transport3);

	system("pause");
	return 0;
}
	
	

