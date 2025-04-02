#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class AbstractDevice abstract
{
protected:
	string producer;

public:
	string GetProducer()
	{
		return this->producer;
	}
	void SetProducer(string producer)
	{
		this->producer = producer;
	}
	virtual AbstractDevice* Clone() abstract;
};

class LBStructure : public AbstractDevice
{
	string color;
	int weight;
public:
	string GetColor()
	{
		return this->color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	int GetWeight()
	{
		return this->weight;
	}
	void SetWeight(int weight)
	{
		this->weight = weight;
	}
	AbstractDevice* Clone() override
	{
		LBStructure* lb = new LBStructure;
		*lb = *this;
		return lb;
	}
};

class Transmission : public AbstractDevice
{
	string type;
	int gears;
public:
	string GetType()
	{
		return this->type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	int GetGears()
	{
		return this->gears;
	}
	void SetGears(int gears)
	{
		this->gears = gears;
	}
	AbstractDevice* Clone() override
	{
		Transmission* tr = new Transmission;
		*tr = *this;
		return tr;
	}
};

class Chassis : public AbstractDevice
{
	int wheelCount;
	string material;
public:
	int GetWheelCount()
	{
		return this->wheelCount;
	}
	void SetWheelCount(int wheelCount)
	{
		this->wheelCount = wheelCount;
	}
	string GetMaterial()
	{
		return this->material;
	}
	void SetMaterial(string material)
	{
		this->material = material;
	}
	AbstractDevice* Clone() override
	{
		Chassis* ch = new Chassis;
		*ch = *this;
		return ch;
	}
};

class ElEquip : public AbstractDevice
{
	int voltage;
	bool hasGPS;
public:
	int GetVoltage()
	{
		return this->voltage;
	}
	void SetVoltage(int voltage)
	{
		this->voltage = voltage;
	}
	bool GetHasGPS()
	{
		return this->hasGPS;
	}
	void SetHasGPS(bool hasGPS)
	{
		this->hasGPS = hasGPS;
	}
	AbstractDevice* Clone() override
	{
		ElEquip* eq = new ElEquip;
		*eq = *this;
		return eq;
	}
};

class Engine : public AbstractDevice
{
	int horsepower;
	string fuelType;
public:
	int GetHorsepower()
	{
		return this->horsepower;
	}
	void SetHorsepower(int horsepower)
	{
		this->horsepower = horsepower;
	}
	string GetFuelType()
	{
		return this->fuelType;
	}
	void SetFuelType(string fuelType)
	{
		this->fuelType = fuelType;
	}
	AbstractDevice* Clone() override
	{
		Engine* en = new Engine;
		*en = *this;
		return en;
	}
};

class ControlSystem : public AbstractDevice
{
	string softwareVersion;
	bool hasAutopilot;
public:
	string GetSoftwareVersion()
	{
		return this->softwareVersion;
	}
	void SetSoftwareVersion(string softwareVersion)
	{
		this->softwareVersion = softwareVersion;
	}
	bool GetHasAutopilot()
	{
		return this->hasAutopilot;
	}
	void SetHasAutopilot(bool hasAutopilot)
	{
		this->hasAutopilot = hasAutopilot;
	}
	AbstractDevice* Clone() override
	{
		ControlSystem* cs = new ControlSystem;
		*cs = *this;
		return cs;
	}
};


class Prototype abstract
{
public:
	virtual Prototype* Clone() abstract;
};

class Auto : public Prototype
{
	LBStructure* lbStructure;
	Transmission* transmission;
	Chassis* chassis;
	Engine* engine;
	ElEquip* elEquip;
	ControlSystem* controlSystem;
public:
	LBStructure* GetLBStructure()
	{
		return this->lbStructure;
	}
	void SetLBStructure(LBStructure* lbStructure)
	{
		this->lbStructure = lbStructure;
	}
	Transmission* GetTransmission()
	{
		return this->transmission;
	}
	void SetTransmission(Transmission* transmission)
	{
		this->transmission = transmission;
	}
	Chassis* GetChassis()
	{
		return this->chassis;
	}
	void SetChassis(Chassis* chassis)
	{
		this->chassis = chassis;
	}
	Engine* GetEngine()
	{
		return this->engine;
	}
	void SetEngine(Engine* engine)
	{
		this->engine = engine;
	}
	ElEquip* GetElEquip()
	{
		return this->elEquip;
	}
	void SetElEquip(ElEquip* elEquip)
	{
		this->elEquip = elEquip;
	}
	ControlSystem* GetControlSystem()
	{
		return this->controlSystem;
	}
	void SetControlSystem(ControlSystem* controlSystem) { this->controlSystem = controlSystem; }

	Prototype* Clone() override
	{
		Auto* au = new Auto;
		au->lbStructure = this->lbStructure != nullptr ? (LBStructure*)this->lbStructure->Clone() : nullptr;
		au->transmission = this->transmission != nullptr ? (Transmission*)this->transmission->Clone() : nullptr;
		au->chassis = this->chassis != nullptr ? (Chassis*)this->chassis->Clone() : nullptr;
		au->engine = this->engine != nullptr ? (Engine*)this->engine->Clone() : nullptr;
		au->elEquip = this->elEquip != nullptr ? (ElEquip*)this->elEquip->Clone() : nullptr;
		au->controlSystem = this->controlSystem != nullptr ? (ControlSystem*)this->controlSystem->Clone() : nullptr;
		return au;
	}
};

class AutoPrototypes
{
	map<string, Auto*> autoPrototypes;
public:
	AutoPrototypes()
	{
		InitializeAutoPrototypes();
	}

	Auto* operator[](string key)
	{
		return autoPrototypes[key];
	}

	void InitializeAutoPrototypes()
	{
		autoPrototypes["Crossover"] = CreateCrossoverConfig();
		autoPrototypes["Lightweight"] = CreateLightweightConfig();
	}

	Auto* CreateCrossoverConfig()
	{
		Auto* config = new Auto();

		LBStructure* lbStructure = new LBStructure();
		lbStructure->SetColor("Black");
		lbStructure->SetWeight(1800); // Example weight
		config->SetLBStructure(lbStructure);

		Transmission* transmission = new Transmission();
		transmission->SetProducer("Aisin");
		transmission->SetType("Automatic");
		transmission->SetGears(8);
		config->SetTransmission(transmission);

		Chassis* chassis = new Chassis();
		chassis->SetProducer("Magna");
		chassis->SetWheelCount(4);
		chassis->SetMaterial("Aluminum");
		config->SetChassis(chassis);

		Engine* engine = new Engine();
		engine->SetProducer("Honda");
		engine->SetHorsepower(250);
		engine->SetFuelType("Gasoline");
		config->SetEngine(engine);

		ElEquip* elEquip = new ElEquip();
		elEquip->SetProducer("Panasonic");
		elEquip->SetVoltage(12);
		elEquip->SetHasGPS(true);
		config->SetElEquip(elEquip);

		ControlSystem* controlSystem = new ControlSystem();
		controlSystem->SetProducer("Continental");
		controlSystem->SetSoftwareVersion("v2.1");
		controlSystem->SetHasAutopilot(true);
		config->SetControlSystem(controlSystem);

		return config;
	}

	Auto* CreateLightweightConfig()
	{
		Auto* config = new Auto();

		LBStructure* lbStructure = new LBStructure();
		lbStructure->SetColor("White");
		lbStructure->SetWeight(1200); // Example weight
		config->SetLBStructure(lbStructure);

		Transmission* transmission = new Transmission();
		transmission->SetProducer("Jatco");
		transmission->SetType("CVT");
		transmission->SetGears(6);
		config->SetTransmission(transmission);

		Chassis* chassis = new Chassis();
		chassis->SetProducer("Denso");
		chassis->SetWheelCount(4);
		chassis->SetMaterial("Steel");
		config->SetChassis(chassis);

		Engine* engine = new Engine();
		engine->SetProducer("Suzuki");
		engine->SetHorsepower(150);
		engine->SetFuelType("Hybrid");
		config->SetEngine(engine);

		ElEquip* elEquip = new ElEquip();
		elEquip->SetProducer("Sony");
		elEquip->SetVoltage(24);
		elEquip->SetHasGPS(false);
		config->SetElEquip(elEquip);

		ControlSystem* controlSystem = new ControlSystem();
		controlSystem->SetProducer("Hitachi");
		controlSystem->SetSoftwareVersion("v1.8");
		controlSystem->SetHasAutopilot(false);
		config->SetControlSystem(controlSystem);

		return config;
	}

};

void PrintAuto(Auto* au)
{
	cout << "Auto Configuration:\n";

	if (au->GetLBStructure() != nullptr)
	{
		cout << "Load-Bearing Structure: Color - " << au->GetLBStructure()->GetColor() << endl;
	}

	if (au->GetChassis() != nullptr)
	{
		cout << "Chassis: Producer - " << au->GetChassis()->GetProducer() << ", Wheel Count - "
			<< au->GetChassis()->GetWheelCount() << ", Material - " << au->GetChassis()->GetMaterial() << endl;
	}

	if (au->GetTransmission() != nullptr)
	{
		cout << "Transmission: Producer - " << au->GetTransmission()->GetProducer()
			<< ", Type - " << au->GetTransmission()->GetType()
			<< ", Gears - " << au->GetTransmission()->GetGears() << endl;
	}

	if (au->GetEngine() != nullptr)
	{
		cout << "Engine: Producer - " << au->GetEngine()->GetProducer()
			<< ", Horsepower - " << au->GetEngine()->GetHorsepower()
			<< ", Fuel Type - " << au->GetEngine()->GetFuelType() << endl;
	}

	if (au->GetElEquip() != nullptr)
	{
		cout << "Electronic Equipment: Producer - " << au->GetElEquip()->GetProducer()
			<< ", Voltage - " << au->GetElEquip()->GetVoltage()
			<< ", GPS - " << (au->GetElEquip()->GetHasGPS() ? "Yes" : "No") << endl;
	}

	if (au->GetControlSystem() != nullptr)
	{
		cout << "Control System: Producer - " << au->GetControlSystem()->GetProducer()
			<< ", Software Version - " << au->GetControlSystem()->GetSoftwareVersion()
			<< ", Autopilot - " << (au->GetControlSystem()->GetHasAutopilot() ? "Yes" : "No") << endl;
	}

	cout << "----------------------------------" << endl;
}

int main()
{
	cout << "Enter config prototype name: ";
	string prototypeName;
	cin >> prototypeName;

	AutoPrototypes au;
	Auto* prototype = au[prototypeName];

	if (prototype != nullptr)
	{
		Auto* au = dynamic_cast<Auto*>(prototype->Clone());
		PrintAuto(au);
	}
	else
	{
		cout << "Error: incorrect config name" << endl;
	}

	system("pause");
	return 0;
}


