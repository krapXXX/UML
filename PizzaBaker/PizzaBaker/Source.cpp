#include <iostream>
#include <string>

using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Достоинства паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

   /*
		* Pizza (продукт) представляет сложный конструируемый объект.
		* ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
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

   // Abstract Builder задает абстрактный интерфейс (класс) для создания частей объекта Product (в нашем случае, Pizza);
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

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

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

// Director(распорядитель) - конструирует объект (Pizza), пользуясь интерфейсом Builder
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

// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
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