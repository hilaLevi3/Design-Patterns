#include <iostream>
#include <utility>
#include <map>
using namespace std;

/////////--9.2. Factory (lambda)--/////////
class Food{
protected:
    int calories;
public:
    virtual int eat() = 0;
};

class Salad:public Food{
public:
    Salad(){
        calories = 200;
    }
    virtual int eat(){
        cout << "I ate salad, with "<< calories << " calories." << endl;
    }
};

class Sandwich: public Food{
public:
    Sandwich(){
        calories = 250;
    }
    virtual int eat(){
        cout << "I ate sandwich, with "<< calories << " calories." << endl;
    }
};

class Pizza: public Food{
public:
    Pizza(){
        calories = 500;
    }
    virtual int eat(){
        cout << "I ate pizza, with "<< calories << " calories." << endl;
    }
};


class FoodFactory{
    class FoodCreator{
    public:
        virtual Food* create() = 0;
        virtual ~FoodCreator(){}
    };

    class PizzaCreator: public FoodCreator{
    public:
        virtual Food* create(){
            return new Pizza();
        }
    };

    class SaladCreator: public FoodCreator{
    public:
        virtual Food* create(){
            return new Salad();
        }
    };

    class SandwichCreator: public FoodCreator{
    public:
        virtual Food* create(){
            return new Sandwich();
        }
    };

    map <string, FoodCreator*> map;

public:
    FoodFactory(){
        FoodCreator* f = new PizzaCreator();
        map.insert(pair<string, FoodCreator*>("Pizza", f));
        f = new SaladCreator();
        map.insert(pair<string, FoodCreator*>("Salad", f));
        f = new SandwichCreator();
        map.insert(pair<string, FoodCreator*>("Sandwich", f));
    }

    Food* getFood(string s){
        FoodCreator* f = map[s];
        if (f != nullptr){
            return f->create();
        } return nullptr;
    }
    ~FoodFactory(){
        for (auto it = map.begin(); it != map.end(); it++){
            delete(it->second);
        }
    }
};

int main(){
    FoodFactory f;
    Food* food = f.getFood("Salad");
    Food* food1 = f.getFood("Pizza");
    Food* food2 = f.getFood("Pizza");
    food->eat();
    food1->eat();
    food2->eat();
    string s;
    cin >> s;
    Food* food3 = f.getFood(s);
    food3->eat();
    delete(food);
    delete(food1);
    delete(food2);
    return 0;
}