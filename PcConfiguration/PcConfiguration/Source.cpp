#include <iostream>
#include <string>
using namespace std;

class Box abstract
{
public:
	virtual string GetName() abstract;
};

class Hdd abstract
{
public:
	virtual string GetName() abstract;
};

class MainBoard abstract
{
public:
	virtual string GetName() abstract;
};

class Processor abstract
{
public:
	virtual string GetName() abstract;
};

class Memory abstract
{
public:
	virtual string GetName() abstract;
};

class Matrix abstract
{
public:
	virtual string GetName() abstract;
};




class SilverBox : public Box
{
public:
	string GetName() override
	{
		return "SilverBox";
	}
};
class BlackBox : public Box
{
public:
	string GetName() override
	{
		return "BlackBox";
	}
};
class PurpleBox : public Box
{
public:
	string GetName() override
	{
		return "PurpleBox";
	}
};


class SamsungHDD: public Hdd
{
public:
	string GetName() override
	{
		return "Samsung hdd";
	}
};
class LGHDD : public Hdd
{
public:
	string GetName() override
	{
		return "LG hdd";
	}
};
class RyzenHDD : public Hdd
{
public:
	string GetName() override
	{
		return "Ryzen hdd";
	}
};

class MSIMainBord: public MainBoard
{
public:
	string GetName() override
	{
		return "MSIMainBord";
	}
};
class AsusMainBord : public MainBoard
{
public:
	string GetName() override
	{
		return "AsusMainBord";
	}
};
class RyzenMainBord : public MainBoard
{
public:
	string GetName() override
	{
		return "RyzenMainBord";
	}
};


class IntelProcessor: public Processor
{
public:
	string GetName() override
	{
		return "IntelProcessor";
	}
};
class AmdProcessor : public Processor
{
public:
	string GetName() override
	{
		return "AmdProcessor";
	}
};
class RyzenProcessor : public Processor
{
public:
	string GetName() override
	{
		return "Amd Ryzen Processor";
	}
};


class Ddr3Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr3Memory";
	}
};
class Ddr2Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr2Memory";
	}
};
class Ddr5Memory: public Memory
{
public:
	string GetName() override
	{
		return "Ddr5Memory";
	}
};

class AsusMatrix: public Matrix
{
public:
	string GetName() override
	{
		return "Asus TUF Gaming B550M-Plus";
	}
};
class AmdMatrix: public Matrix
{
public:
	string GetName() override
	{
		return "AMD Ryzen 5 5500 ";
	}
};
class RyzenMatrix: public Matrix
{
public:
	string GetName() override
	{
		return "TUF Gaming A620M-Plus";
	}
};



class Pc
{
	Box *box;
	Processor *processor;
	MainBoard *mainboard;
	Hdd *hdd;
	Memory *memory;
	Matrix* matrix;
	
public:
	Box* GetBox()
	{
		return box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	MainBoard* GetMainBoard()
	{
		return mainboard;
	}
	void SetMainBoard(MainBoard* mainboard)
	{
		this->mainboard = mainboard;
	}
	Hdd* GetHdd()
	{
		return hdd;
	}
	void SetHdd(Hdd* hdd)
	{
		this->hdd = hdd;
	}
	Memory* GetMemory()
	{
		return memory;
	}
	void SetMemory(Memory* memory)
	{
		this->memory = memory;
	}
	Matrix* GetMatrix()
	{
		return matrix;
	}
	void SetMatrix(Matrix* matrix)
	{
		this->matrix = matrix;
	}
};

class IPcFactory abstract
{
public:
	virtual Box* CreateBox() abstract;
	virtual Processor* CreateProcessor() abstract;
	virtual MainBoard* CreateMainBoard() abstract;
	virtual Hdd* CreateHdd() abstract;
	virtual Memory* CreateMemory() abstract;
	virtual Matrix* CreateMatrix() abstract;
};

class HomePcFactory : public IPcFactory 
{
public:
	Box* CreateBox() override
	{
		return new SilverBox();
	}
	Processor* CreateProcessor() override
	{
		return new IntelProcessor();
	}
	MainBoard* CreateMainBoard() override
	{
		return new MSIMainBord();
	}
	Hdd* CreateHdd() override
	{
		return new SamsungHDD();
	}
	Memory* CreateMemory() override
	{
		return new Ddr3Memory();
	}
	Matrix* CreateMatrix() override
	{
		return new AsusMatrix();
	}
};

class OfficePcFactory: public IPcFactory 
{
public:
	Box* CreateBox() override
	{
		return new BlackBox();
	}
	Processor* CreateProcessor() override
	{
		return new AmdProcessor();
	}
	MainBoard* CreateMainBoard() override
	{
		return new AsusMainBord();
	}
	Hdd* CreateHdd() override
	{
		return new LGHDD();
	}
	Memory* CreateMemory() override
	{
		return new Ddr2Memory();
	}
	Matrix* CreateMatrix() override
	{
		return new AmdMatrix();
	}
};

class GamePcFactory : public IPcFactory
{
public:
	Box* CreateBox() override
	{
		return new PurpleBox();
	}
	Processor* CreateProcessor() override
	{
		return new RyzenProcessor();
	}
	MainBoard* CreateMainBoard() override
	{
		return new RyzenMainBord();
	}
	Hdd* CreateHdd() override
	{
		return new RyzenHDD();
	}
	Memory* CreateMemory() override
	{
		return new Ddr5Memory();
	}
	Matrix* CreateMatrix() override
	{
		return new RyzenMatrix();
	}
};

class PcConfigurator
{
	IPcFactory* PcFactory;
public:
	IPcFactory* GetFactory()
	{
		return PcFactory;
	}
	void SetFactory(IPcFactory* pFactory)
	{
		PcFactory = pFactory;
	}
	void Configure(Pc &pc) 
	{
		pc.SetBox(PcFactory->CreateBox());
		pc.SetMainBoard(PcFactory->CreateMainBoard());
		pc.SetHdd(PcFactory->CreateHdd());
		pc.SetMemory(PcFactory->CreateMemory());
		pc.SetProcessor(PcFactory->CreateProcessor());
		pc.SetMatrix(PcFactory->CreateMatrix());
	}
};

void PrintPcConfiguration(string configName, IPcFactory* PcFactory)
{
	Pc pc;
	PcConfigurator configurator;
	configurator.SetFactory(PcFactory);
	configurator.Configure(pc);
	cout << "======== " + configName + " ========" << endl;
	cout << "Box: " + pc.GetBox()->GetName() << endl;
	cout << "MainBoard: " + pc.GetMainBoard()->GetName() << endl;
	cout << "Processor: " + pc.GetProcessor()->GetName() << endl;
	cout << "HDD: " + pc.GetHdd()->GetName() << endl;
	cout << "Memory: " + pc.GetMemory()->GetName() << endl;
	cout << "Matrix: " + pc.GetMatrix()->GetName() << endl;
	cout << "==============================" << endl;
}

void main()
{		
	IPcFactory* PcFactory = new HomePcFactory();
	PrintPcConfiguration("Home configuration", PcFactory);
	delete PcFactory;
	PcFactory = new OfficePcFactory();
	PrintPcConfiguration("Office configuration", PcFactory);
	delete PcFactory;
	PcFactory = new GamePcFactory();
	PrintPcConfiguration("Game configuration", PcFactory);
	delete PcFactory;

	system("pause");
}
