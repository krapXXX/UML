#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component abstract
{
protected:
	string name;
public:
	Component(string name)
	{
		this->name = name;
	}

	virtual  void Add(Component* c) abstract;
	virtual  void Remove(Component* c) abstract;
	virtual  void Print(int depth) abstract;
};

class Composite : public Component
{
	vector<Component*> components;

public:
	Composite(string name) :Component(name) {}

	void Add(Component* component) override
	{
		components.push_back(component);
	}
	void Remove(Component* component) override
	{
		auto iter = find(components.begin(), components.end(), component);
		components.erase(iter);
	}
	void Print(int depth) override
	{
		string s(depth, '-');
		cout << s + name << endl;
		for (Component* component : components)
		{
			component->Print(depth+2);
		}
	}
};

class Leaf : public Component
{
public:
	Leaf(string name): Component(name){	}

	void Add(Component*obj) override
	{
		cout << "Cannot add to the room\n";
	}
	void Remove(Component*obj) override
	{
		cout << "Cannot remove from the room\n";
	}
	void Print(int depth) override
	{
		string s(depth, '-');
		cout << s + name << endl;
	}
};

int main()
{
	Component* room1 = new Composite("Reception");
	room1->Add(new Leaf("In light tones"));
	Component* table1_1 = new Composite("Coffee table");
	table1_1->Add(new Leaf("10-20 magazines like 'Computer World'"));
	room1->Add(table1_1);
	room1->Add(new Leaf("Soft sofa"));
	Component* table1_2 = new Composite("Secretary table");
	Component* table1_2_1 = new Composite("Computer");
	table1_2_1->Add(new Leaf("Has to have large HDD"));
	table1_2->Add(table1_2_1);
	table1_2->Add(new Leaf("Office equip"));
	room1->Add(table1_2);
	room1->Add(new Leaf("Cooler with warm/cold water"));

	Component* room2 = new Composite("Class1");
	room2->Add(new Leaf("10 tables"));
	room2->Add(new Leaf("Blackboard"));
	Component* table2_1 = new Composite("Teacher’s desk");
	table2_1->Add(new Leaf("Computer"));
	room2->Add(table2_1);
	room2->Add(new Leaf("Posters of Great Mathematicians"));

	Component* room3 = new Composite("Class2");
	Component* table3_1 = new Composite("20 tables");
	table3_1->Add(new Leaf("Black tables"));
	table3_1->Add(new Leaf("Tables in the circle"));
	room3->Add(table3_1);
	room3->Add(new Leaf("Blackboard"));
	room3->Add(new Leaf("Soft sofa"));

	Component* room4 = new Composite("Computer class");
	Component* table4_1 = new Composite("10 computer tables");
	Component* table4_1_1 = new Composite("PC on every table");
	table4_1_1->Add(new Leaf("Processor: 2.2 GHz"));
	table4_1_1->Add(new Leaf("Hard drive: 80 GB"));
	table4_1_1->Add(new Leaf("RAM: 1024 MB"));
	table4_1->Add(table4_1_1);
	table4_1->Add(new Leaf("Power outlet near each desk"));
	room4->Add(table4_1);
	Component* board4_1 = new Composite("Blackboard");
	board4_1->Add(new Leaf("Colored markers"));
	room4->Add(board4_1);




	room1->Print(1);
	cout << "\n\n";

	room2->Print(1);
	cout << "\n\n";

	room3->Print(1);
	cout << "\n\n";

	room4->Print(1);
	cout << "\n\n";

	/*room5->Print(1);
	cout << "\n\n";*/


	system("pause");
}


