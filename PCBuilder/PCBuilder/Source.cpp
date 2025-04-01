#include <iostream>
#include <string>

using namespace std;

class PC
{
	string CPU;
	string RAM;
	string SSD;
	string GPU;
	string MainBoard;
public:
	void SetCPU(string CPU)
	{
		this->CPU = CPU;
	}
	void SetRAM(string RAM)
	{
		this->RAM = RAM;
	}
	void SetSSD(string SSD)
	{
		this->SSD = SSD;
	}
	void SetGPU(string GPU)
	{
		this->GPU = GPU;
	}
	void SetMainBoard(string MainBoard)
	{
		this->MainBoard = MainBoard;
	}
	void GetCPU(string CPU)
	{
		this->CPU = CPU;
	}
	void GetRAM(string RAM)
	{
		this->RAM = RAM;
	}
	void GetSSD(string SSD)
	{
		this->SSD = SSD;
	}
	void GetGPU(string GPU)
	{
		this->GPU = GPU;
	}
	void GetMainBoard(string MainBoard)
	{
		this->MainBoard = MainBoard;
	}
	void ShowPC()
	{
		cout << "CPU: " << CPU << endl;
		cout << "RAM: " << RAM << endl;
		cout << "SSD: " << SSD << endl;
		cout << "GPU: " << GPU << endl;
		cout << "MainBoard: " << MainBoard << endl;
	}
};

class PCBuilder abstract
{
protected:
	PC pc;
public:
	PC GetPC()
	{
		return pc;
	}
	virtual void BuildCPU() abstract;
	virtual void BuildRAM() abstract;
	virtual void BuildSSD() abstract;
	virtual void BuildGPU() abstract;
	virtual void BuildMainBoard() abstract;
};

class HomePCBuilder : public PCBuilder
{
public:
	void BuildCPU() override
	{
		pc.SetCPU("AMD Ryzen 3 4600");
	}
	void BuildRAM() override
	{
		pc.SetRAM("8 GB");
	}
	void BuildSSD() override
	{
		pc.SetSSD("512 GB");
	}
	void BuildGPU() override
	{
		pc.SetGPU("NVIDIA GeForce RTX 3060");
	}
	void BuildMainBoard() override
	{
		pc.SetMainBoard("AMD A320");
	}
};

class GamePCBuilder : public PCBuilder
{
public:
	void BuildCPU() override
	{
		pc.SetCPU("AMD Ryzen 5 5600");
	}
	void BuildRAM() override
	{
		pc.SetRAM("16 GB");
	}
	void BuildSSD() override
	{
		pc.SetSSD("1 TB");
	}
	void BuildGPU() override
	{
		pc.SetGPU("NVIDIA GeForce RTX 3070");
	}
	void BuildMainBoard() override
	{
		pc.SetMainBoard("AMD B450");
	}
};


class Director
{
	PCBuilder* pcBuilder;
public:
	void SetPСBuilder(PCBuilder* pb)
	{
		pcBuilder = pb;
	}
	PC GetPC()
	{
		return pcBuilder->GetPC();
	}
	void ConstructPC()
	{
		pcBuilder->BuildCPU();
		pcBuilder->BuildRAM();
		pcBuilder->BuildSSD();
		pcBuilder->BuildGPU();
		pcBuilder->BuildMainBoard();
	}
};

void director(PCBuilder* builder)
{
	Director director;
	director.SetPСBuilder(builder);
	director.ConstructPC();
	PC pc = director.GetPC();
	pc.ShowPC();
}

void main()
{
	PCBuilder* builder = new HomePCBuilder();
	director(builder);
	delete builder;
	builder = new GamePCBuilder();
	director(builder);
	delete builder;
	system("pause");
}