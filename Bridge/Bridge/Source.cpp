#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class IPrint abstract
{
public:
	virtual void Print(const string& message) abstract;
};

class PrintToConsole : public IPrint
{
public:
	void Print(const string& message) override
	{
		cout << "Console Output: " << message << "\n\n";
	}
};

class PrintToFile : public IPrint
{
public:
	void Print(const string& message) override
	{
		ofstream outFile("File.txt", ios::trunc); 
		if (outFile.is_open())
		{
			outFile << message << "\n";
			outFile.close();
			cout << "Message written to file.txt successfully.\n\n";
		}
		else
		{
			cout << "Error: Could not open file.txt for writing.\n\n";
		}
	}
};

class Device abstract
{
protected:
	IPrint* printer;
public:
	void SetPrinter(IPrint* p)
	{
		printer = p;
	}
	virtual void ShowInfo() = 0; 
	virtual ~Device() {}
};

class GPU : public Device
{
public:
	void ShowInfo() override
	{
		printer->Print("GPU device: Rendering graphics");
	}
};

class CPU : public Device
{
public:
	void ShowInfo() override
	{
		printer->Print("CPU device: Processing data");
	}
};

class HDD : public Device
{
public:
	void ShowInfo() override
	{
		printer->Print("HDD device: Storing files");
	}
};

void client(Device* device, IPrint* printer)
{
	device->SetPrinter(printer);
	device->ShowInfo();
}

int main()
{
	IPrint* printer = new PrintToConsole();

	Device* gpu = new GPU();
	client(gpu, printer);
	delete gpu;

	Device* cpu = new CPU();
	client(cpu, printer);
	delete cpu;

	delete printer;

	printer = new PrintToFile();
	Device* hdd = new HDD();
	client(hdd, printer);
	delete hdd;

	delete printer;

	system("pause");
	return 0;
}
