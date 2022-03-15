#include <iostream>
#include <map>
#include <functional>
using namespace std;

/////////--9.2. Factory (lambda)--/////////
/*class Food{
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
        virtual Food* operator()() = 0;
    };

    class PizzaCreator: public FoodCreator{
    public:
        virtual Food* operator()(){
            return new Pizza();
        }
    };

    class SaladCreator: public FoodCreator{
    public:
        virtual Food* operator()(){
            return new Salad();
        }
    };

    class SandwichCreator: public FoodCreator{
    public:
        virtual Food* operator()(){
            return new Sandwich();
        }
    };
    //////////////////////////<ret(parm)>
    map <string, std::function<Food*()>> map;

public:
    FoodFactory(){
        map.insert({"Pizza", [](){return new Pizza();}});
        map.insert({"Salad", [](){return new Salad();}});
        map.insert({"Sandwich", [](){return new Sandwich();}});
    }

    Food* getFood(string s){
        std::function<Food*()> f = map[s];
        if (f != nullptr){
            return f();
        } return nullptr;
    }
    ~FoodFactory(){
        for (auto it = map.begin(); it != map.end(); it++){
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
}*/



#include <iostream>
#include <map>
#include <functional>
using namespace std;

/////////--9.2. Factory (lambda)--/////////
class Food{
protected:
    int calories;
public:
    virtual Food* clone() = 0;
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
    virtual Food* clone(){
        cout << "salad clone" << endl;
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
    virtual Food* clone(){
        cout << "sandwich clone" << endl;
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
    virtual Food* clone(){
        cout << "pizza clone" << endl;
        return new Pizza();
    }

};


class FoodFactory{
    class FoodCreator{
    public:
        virtual Food* operator()() = 0;
    };

    //////////////////////////<ret(parm)>
    map <string, std::function<Food*()>> map;

public:
    FoodFactory(){
//        map.insert({"Pizza", [](Food* ){return new Pizza();}});
        Food* f = new Pizza();
        map.insert({"Pizza", [f](){return f->clone();}});
        f = new Salad();
        map.insert({"Salad", [f](){return f->clone();}});
        f =  new Sandwich();
        map.insert({"Sandwich", [f](){return f->clone();}});
    }

    Food* getFood(string s){
        std::function<Food*()> f = map[s];
        if (f != nullptr){
            return f();
        } return nullptr;
    }
    ~FoodFactory(){
        for (auto it = map.begin(); it != map.end(); it++){
        }
    }
};

int main(){
    FoodFactory f;
//    Food* food = f.getFood("Salad");
    Food* food1 = f.getFood("Pizza");
    Food* food2 = f.getFood("Pizza");
//    food->eat();
    food1->eat();
    food2->eat();
    string s;
    cin >> s;
    Food* food3 = f.getFood(s);
    food3->eat();
//    delete(food);
//    delete(food1);
//    delete(food2);
    return 0;
}
