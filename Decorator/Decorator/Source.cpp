#include <iostream>
#include <string>
using namespace std;

class HumanDecorator abstract
{
protected:
	HumanDecorator* human;
public:
	HumanDecorator(HumanDecorator* h) : human(h) {}
	virtual void Describe() = 0;
	virtual int GetPower() = 0;
	virtual int GetSpeed() = 0;
	virtual int GetHealth() = 0;
	virtual int GetProtection() = 0;
};

class ElfDecorator abstract
{
protected:
	ElfDecorator* elf;
public:
	ElfDecorator(ElfDecorator* e) : elf(e) {}
	virtual void Describe() = 0;
	virtual int GetPower() = 0;
	virtual int GetSpeed() = 0;
	virtual int GetHealth() = 0;
	virtual int GetProtection() = 0;
};


class BasicHuman : public HumanDecorator
{
	int Power = 20;
	int Speed = 20;
	int Health = 150;
	int Protection = 0;
public:
	BasicHuman(HumanDecorator* human) : HumanDecorator(human) {}
	void Describe()
	{
		cout << "Basic human" << endl;
	}
	int GetPower() override
	{
		return Power;
	}
	int GetSpeed() override
	{
		return Speed;
	}
	int GetHealth() override
	{
		return Health;
	}
	int GetProtection() override
	{
		return Protection;
	}
};

class Warrior : public BasicHuman
{
public:
	Warrior(HumanDecorator* human) : BasicHuman(human) {}
	void Describe()
	{
		cout << "Warrior" << endl;
	}
	int GetPower() override
	{
		return human->GetPower() + 20;
	}
	int GetSpeed() override
	{
		return human->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	int GetProtection() override
	{
		return human->GetProtection() + 20;
	}
};

class SwordBearer : public Warrior
{
public:
	SwordBearer(HumanDecorator* human) : Warrior(human) {}
	void Describe()
	{
		cout << "SwordBearer" << endl;
	}
	int GetPower() override
	{
		return human->GetPower() + 40;
	}
	int GetSpeed() override
	{
		return human->GetSpeed() - 10;
	}
	int GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	int GetProtection() override
	{
		return human->GetProtection() + 40;
	}
};

class Archer : public Warrior
{
public:
	Archer(HumanDecorator* human) : Warrior(human) {}
	void Describe()
	{
		cout << "Archer" << endl;
	}
	int GetPower() override
	{
		return human->GetPower() + 20;
	}
	int GetSpeed() override
	{
		return human->GetSpeed() + 20;
	}
	int GetHealth() override
	{
		return human->GetHealth() + 50;
	}
	int GetProtection() override
	{
		return human->GetProtection() + 10;
	}
};

class HorseMan : public SwordBearer
{
public:
	HorseMan(HumanDecorator* human) : SwordBearer(human) {}
	void Describe()
	{
		cout << "HorseMan" << endl;
	}
	int GetPower() override
	{
		return human->GetPower() - 10;
	}
	int GetSpeed() override
	{
		return human->GetSpeed() + 40;
	}
	int GetHealth() override
	{
		return human->GetHealth() + 200;
	}
	int GetProtection() override
	{
		return human->GetProtection() + 100;
	}
};

class BasicElf : public ElfDecorator
{
	int Power = 15;
	int Speed = 30;
	int Health = 100;
	int Protection = 0;
public:
	BasicElf(ElfDecorator* elf) : ElfDecorator(elf) {}
	void Describe()
	{
		cout << "Basic elf" << endl;
	}
	int GetPower() override
	{
		return Power;
	}
	int GetSpeed() override
	{
		return Speed;
	}
	int GetHealth() override
	{
		return Health;
	}
	int GetProtection() override
	{
		return Protection;
	}
};

class WarriorElf : public BasicElf
{
public:
	WarriorElf(ElfDecorator* elf) : BasicElf(elf) {}
	void Describe()
	{
		cout << "Warrior elf" << endl;
	}
	int GetPower() override
	{
		return elf->GetPower() + 20;
	}
	int GetSpeed() override
	{
		return elf->GetSpeed() - 10;
	}
	int GetHealth() override
	{
		return elf->GetHealth() + 100;
	}
	int GetProtection() override
	{
		return elf->GetProtection() + 20;
	}
};

class WizardElf : public BasicElf
{
public:
	WizardElf(ElfDecorator* elf) : BasicElf(elf) {}
	void Describe()
	{
		cout << "Wizzard elf" << endl;
	}
	int GetPower() override
	{
		return elf->GetPower() + 10;
	}
	int GetSpeed() override
	{
		return elf->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return elf->GetHealth() -50;
	}
	int GetProtection() override
	{
		return elf->GetProtection() + 10;
	}
};

class Crossbowman : public WarriorElf
{
public:
	Crossbowman(ElfDecorator* elf) : WarriorElf(elf) {}
	void Describe()
	{
		cout << "Crossbowman" << endl;
	}
	int GetPower() override
	{
		return elf->GetPower() + 20;
	}
	int GetSpeed() override
	{
		return elf->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return elf->GetHealth() +50;
	}
	int GetProtection() override
	{
		return elf->GetProtection() - 10;
	}
};

class KindWizard : public WizardElf
{
public:
	KindWizard(ElfDecorator* elf) : WizardElf(elf) {}
	void Describe()
	{
		cout << "Evil Wizard" << endl;
	}
	int GetPower() override
	{
		return elf->GetPower() + 50;
	}
	int GetSpeed() override
	{
		return elf->GetSpeed() + 30;
	}
	int GetHealth() override
	{
		return elf->GetHealth() +100;
	}
	int GetProtection() override
	{
		return elf->GetProtection() +30;
	}
};

class EvilWizard : public WizardElf
{
public:
	EvilWizard(ElfDecorator* elf) : WizardElf(elf) {}
	void Describe()
	{
		cout << "Evil Wizard" << endl;
	}
	int GetPower() override
	{
		return elf->GetPower() + 70;
	}
	int GetSpeed() override
	{
		return elf->GetSpeed() + 20;
	}
	int GetHealth() override
	{
		return elf->GetHealth() +0;
	}
	int GetProtection() override
	{
		return elf->GetProtection() +0;
	}
};


void human(HumanDecorator* h)
{
	h->Describe();
	cout << "Power: " << h->GetPower() << endl;
	cout << "Speed: " << h->GetSpeed() << endl;
	cout << "Health: " << h->GetHealth() << endl;
	cout << "Protection: " << h->GetProtection() << endl;
	cout << endl;
}

void elf(ElfDecorator* e)
{
	e->Describe();
	cout << "Power: " << e->GetPower() << endl;
	cout << "Speed: " << e->GetSpeed() << endl;
	cout << "Health: " << e->GetHealth() << endl;
	cout << "Protection: " << e->GetProtection() << endl;
	cout << endl;
}

int main()
{
	HumanDecorator* h = new BasicHuman(nullptr);
	h = new Warrior(h);
	human(h);

	h = new SwordBearer(h);
	human(h);

	h = new Archer(h);
	h = new HorseMan(h);
	human(h);

	ElfDecorator* e = new BasicElf(nullptr);
	e = new WarriorElf(e);
	elf(e);	
	
	e = new Crossbowman(e);
	elf(e);

	e = new WizardElf(e);
	e = new KindWizard(e);
	elf(e);
	e = new EvilWizard(e);
	elf(e);
	
	system("pause");
}