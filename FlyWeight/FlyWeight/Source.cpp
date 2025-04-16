#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class WeaponType {
protected:
	string picture;
	int speed;
	int power;

public:
	WeaponType(string pic, int spd, int pwr)
	{
		picture = pic;
		speed = spd;
		power = pwr;
	}

	virtual void Show(int x, int y) const {
		cout << "Showing " << picture << " at (" << x << "," << y << ") ";
		cout << "Speed: " << speed << ", Power: " << power << endl;
	}

	virtual ~WeaponType() {}
};

class LightInfantry : public WeaponType {
public:
	LightInfantry() : WeaponType("LightInfantry.png", 20, 10) {}
};

class TransportVehicles : public WeaponType {
public:
	TransportVehicles() : WeaponType("TransportVehicles.png", 70, 0) {}
};

class HeavyGroundCombat : public WeaponType {
public:
	HeavyGroundCombat() : WeaponType("HeavyGroundCombat.png", 50, 150) {}
};

class LightGroundCombat : public WeaponType {
public:
	LightGroundCombat() : WeaponType("LightGroundCombat.png", 50, 30) {}
};

class AviationTechnology : public WeaponType {
public:
	AviationTechnology() : WeaponType("AviationTechnology.png", 300, 100) {}
};

class WeaponFactory {
private:
	map<string, WeaponType*> weaponTypes;

public:
	WeaponType* GetWeaponType(const string& type)
	{
		if (weaponTypes.find(type) == weaponTypes.end())
		{
			if (type == "LightInfantry") weaponTypes[type] = new LightInfantry();
			else if (type == "TransportVehicles") weaponTypes[type] = new TransportVehicles();
			else if (type == "HeavyGroundCombat") weaponTypes[type] = new HeavyGroundCombat();
			else if (type == "LightGroundCombat") weaponTypes[type] = new LightGroundCombat();
			else if (type == "AviationTechnology") weaponTypes[type] = new AviationTechnology();
		}
		return weaponTypes[type];
	}

};

class Weapon
{
private:
	int x, y;
	WeaponType* type;

public:
	Weapon(int x, int y, WeaponType* type) : x(x), y(y), type(type) {}

	void Show() const
	{
		type->Show(x, y);
	}
};

class MilitaryFactory
{
private:
	vector<Weapon*> weapons;

public:
	void CreateWeapon(int x, int y, const string& type, WeaponFactory& factory)
	{
		WeaponType* weaponType = factory.GetWeaponType(type);
		weapons.push_back(new Weapon(x, y, weaponType));
	}

	void ShowAll() const
	{
		for (const auto& w : weapons)
		{
			w->Show();
		}
	}

	~MilitaryFactory()
	{
		for (auto& w : weapons)
		{
			delete w;
		}
	}
};

int main()
{
	WeaponFactory* weaponFactory = new WeaponFactory();

	WeaponType* infantry = weaponFactory->GetWeaponType("LightInfantry");
	if (infantry != nullptr)
	{
		infantry->Show(0, 0);
	}

	WeaponType* transport = weaponFactory->GetWeaponType("TransportVehicles");
	if (transport != nullptr)
	{
		transport->Show(0, 0);
	}

	WeaponType* heavy = weaponFactory->GetWeaponType("HeavyGroundCombat");
	if (heavy != nullptr)
	{
		heavy->Show(0, 0);
	}

	WeaponType* light = weaponFactory->GetWeaponType("LightGroundCombat");
	if (light != nullptr)
	{
		light->Show(0, 0);
	}

	WeaponType* aviation = weaponFactory->GetWeaponType("AviationTechnology");
	if (aviation != nullptr)
	{
		aviation->Show(0, 0);
	}

	delete weaponFactory;
	system("pause");
	return 0;
}
