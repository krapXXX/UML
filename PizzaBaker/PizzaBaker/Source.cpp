#include <iostream>
#include <string>

using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����������� �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

   /*
		* Pizza (�������) ������������ ������� �������������� ������.
		* ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
		* */
class Pizza
{
	string dough;
	string sauce;
	string topping;
public:
	void SetDough(string dough)
	{
		this->dough = dough;
	}
	string GetDough()
	{
		return this->dough;
	}
	void SetSauce(string sauce)
	{
		this->sauce = sauce;
	}
	string GetSauce()
	{
		return this->sauce;
	}
	void SetTopping(string topping)
	{
		this->topping = topping;
	}
	string GetTopping()
	{
		return this->topping;
	}
	void ShowPizza()
	{
		cout << " Yummy! Pizza with Dough as " + dough + ", Sauce as " + sauce + " and Topping as " + topping +"\n";
	}
};

   // Abstract Builder ������ ����������� ��������� (�����) ��� �������� ������ ������� Product (� ����� ������, Pizza);
   /** "Abstract Builder" */
class PizzaBuilder abstract
{
protected:
	Pizza pizza;
public:
	Pizza GetPizza()
	{
		return pizza;
	}
	virtual void BuildDough() abstract;
	virtual void BuildSauce() abstract;
	virtual void BuildTopping() abstract;
};

// ConcreteBuilder ��������� ��������� ��������:
// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
// - ���������� ����������� ������������� � ������ �� ���;
// - ������������� ��������� ��� ������� � ��������

class HawaiianPizzaBuilder: public PizzaBuilder
{
public:
	void BuildDough() override
	{
		pizza.SetDough("thin");
	}
	void BuildSauce() override
	{
		pizza.SetSauce("mild");
	}
	void BuildTopping() override
	{
		pizza.SetTopping("ham+pineapple");
	}
};

class SpicyPizzaBuilder: public PizzaBuilder
{
public:  
	void BuildDough() override
	{
		pizza.SetDough("thick");
	}
	void BuildSauce() override
	{
		pizza.SetSauce("hot");
	}
	void BuildTopping() override
	{
		pizza.SetTopping("pepperoni+salami");
	}
};

// Director(�������������) - ������������ ������ (Pizza), ��������� ����������� Builder
class Waiter
{
	PizzaBuilder *pizzaBuilder;
public:
	void SetPizzaBuilder(PizzaBuilder* pb)
	{
		pizzaBuilder = pb;
	}
	Pizza GetPizza()
	{
		return pizzaBuilder->GetPizza();
	}
	void ConstructPizza()
	{
		pizzaBuilder->BuildDough();
		pizzaBuilder->BuildSauce();
		pizzaBuilder->BuildTopping();
	}
};

// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
void client(PizzaBuilder * builder)
{
	Waiter waiter;
	waiter.SetPizzaBuilder(builder);
	waiter.ConstructPizza();
	Pizza pizza = waiter.GetPizza();
	pizza.ShowPizza();
}

void main()
{
	PizzaBuilder * builder = new HawaiianPizzaBuilder();
	client(builder);
	delete builder;
	builder = new SpicyPizzaBuilder();
	client(builder);
	delete builder;
	system("pause");
}