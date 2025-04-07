#include <iostream>
#include <vector>
using namespace std;

class Herbivore {
public:
    virtual void eatGrass() = 0;
    virtual int getWeight() const = 0;
    virtual void setWeight(int w) = 0;
    virtual bool isAlive() const = 0;
    virtual void Print() const = 0;
};

class Carnivore {
public:
    virtual void eatHerb(Herbivore* herbivore) = 0;
    virtual int getPower() const = 0;
    virtual void Print() const = 0;
};

class Wildebeest : public Herbivore 
{
    int weight;
    bool alive;
public:
    Wildebeest(int w, bool a)
    {
        weight = w;
        alive = a;
    }

    void eatGrass() override 
    {
        weight += 10; 
    }

    int getWeight() const override 
    {
        return weight; 
    }

    void setWeight(int w) override 
    {
        weight = w;
    }

    bool isAlive() const override 
    {
        if (weight <= 0)
        {
            return false;
        }
        else return true;
    }

    void Print() const override {
        cout << "\tWildebeest:\nweight: " << weight << "\nstate: " << (alive ? "alive" : "dead") << "\n";
    }
};

class Bison : public Herbivore {
    int weight;
    bool alive;
public:
    Bison(int w, bool a)
    {
        weight = w;
        alive = a;
    }

    void eatGrass() override { weight += 10; }

    int getWeight() const override { return weight; }

    void setWeight(int w) override
    {
        weight = w;
    }

    bool isAlive() const override
    {
        if (weight <= 0)
        {
            return false;
        }
        else return true;
    }

    void Print() const override {
        cout << "\tBison:\nweight: " << weight << "\nstate: " << (alive ? "alive" : "dead") << "\n";
    }
};

class Lion : public Carnivore 
{
    int power;
public:
    Lion(int p)
    {
        power = p;
    }

    void eatHerb(Herbivore* herb) override
    {
        if (Wildebeest* w = dynamic_cast<Wildebeest*>(herb)) 
        {
            if (power > w->getWeight() && w->isAlive()) 
            {
                power += 10;
                w->setWeight(0);
            }
            else 
            {
                power -= 10;
            }
        }
    }
    int getPower() const override 
    {
        return power; 
    }

    void Print() const override 
    {
        cout << "\tLion:\npower: " << power << "\n";
    }
};

class Wolf : public Carnivore {
    int power;
public:
    Wolf(int p) : power(p) {}

    void eatHerb(Herbivore* herb) override 
    {
        if (Bison* b = dynamic_cast<Bison*>(herb)) 
        {
            if (power > b->getWeight() && b->isAlive()) 
            {
                power += 10;
                b->setWeight(0);
            }
            else 
            {
                power -= 10;
            }
        }
    }

    int getPower() const override 
    {
        return power; 
    }

    void Print() const override 
    {
        cout << "\tWolf:\npower: " << power << "\n";
    }
};

class Continent {
protected:
    vector<Herbivore*> herbivores;
    vector<Carnivore*> carnivores;
public:
    void addH(Herbivore* h) 
    {
        herbivores.push_back(h); 
    }
    void addC(Carnivore* c) 
    {
        carnivores.push_back(c); 
    }

    const vector<Herbivore*>& getHerbivores() const 
    {
        return herbivores; 
    }
    const vector<Carnivore*>& getCarnivores() const 
    {
        return carnivores; 
    }

    virtual void Print() const = 0;
};

class Africa : public Continent 
{
public:
    void Print() const override 
    {
        cout << "\n--- Africa ---\nHerbivores:\n";
        for (Herbivore* herb : herbivores) 
        {
            if (Wildebeest* w = dynamic_cast<Wildebeest*>(herb)) 
            {
                w->Print();
            }
        }
        cout << "Carnivores:\n";
        for (Carnivore* carn : carnivores) 
        {
            if (Lion* l = dynamic_cast<Lion*>(carn)) 
            {
                l->Print();
            }
        }
    }
};

class America : public Continent 
{
public:
    void Print() const override 
    {
        cout << "\n--- America ---\nHerbivores:\n";
        for (Herbivore* herb : herbivores) 
        {
            if (Bison* b = dynamic_cast<Bison*>(herb)) 
            {
                b->Print();
            }
        }
        cout << "Carnivores:\n";
        for (Carnivore* carn : carnivores) 
        {
            if (Wolf* w = dynamic_cast<Wolf*>(carn)) 
            {
                w->Print();
            }
        }
    }
};

class AnimalWorld {
public:
    void feedHerbivore(Continent& c) 
    {
        for (auto* h : c.getHerbivores()) 
        {
            h->eatGrass();
        }
    }

    void feedCarnivores(Continent& c) 
    {
        for (auto* carn : c.getCarnivores()) 
        {
            for (auto* herb : c.getHerbivores()) 
            {
                carn->eatHerb(herb);
            }
        }
    }

    void PrintAll(Continent& a, Continent& b) {
        cout << "\n=== Animal World Summary ===\n";
        a.Print();
        b.Print();
    }
};

int main() {
    Africa africa;
    America america;
    AnimalWorld animalWorld;

    Wildebeest* wildebeest1 = new Wildebeest(150, true);
    Wildebeest* wildebeest2 = new Wildebeest(160, true);
    Bison* bison1 = new Bison(200, true);
    Bison* bison2 = new Bison(220, true);

    Lion* lion1 = new Lion(180);
    Lion* lion2 = new Lion(90);
    Wolf* wolf1 = new Wolf(270);
    Wolf* wolf2 = new Wolf(75);

    africa.addH(wildebeest1);
    africa.addH(wildebeest2);
    africa.addC(lion1);
    africa.addC(lion2);

    america.addH(bison1);
    america.addH(bison2);
    america.addC(wolf1);
    america.addC(wolf2);

    animalWorld.feedHerbivore(africa);
    animalWorld.feedHerbivore(america);

    animalWorld.feedCarnivores(africa);
    animalWorld.feedCarnivores(america);

    animalWorld.PrintAll(africa, america);

    return 0;
}
