#include <iostream>
#include <map>
#include <functional>

//////////--17. Observer--/////////

using namespace std;
class State{
public:
    virtual void eat() = 0;
    virtual void walk() = 0;

};

class Person{
protected:
    State* age;
public:
    Person(State* s):age(s){}
    void walk(){
        age->walk();
    };
    void eat(){
        age->eat();
    }
};

class Baby: public State{
public:
    virtual void eat (){
        cout << "Baby is eating from a bottle" << endl;
    }
    virtual void walk(){
        cout << "Baby is crawling on the floor" << endl;
    }
};

class Teenager: public State{
public:
    virtual void eat (){
        cout << "Teenager is eating fast food" << endl;
    }
    virtual void walk(){
        cout << "Teenager is walking fast" << endl;
    }
};

class Elderly: public State{
public:
    virtual void eat (){
        cout << "Elderly is eating healthy food" << endl;
    }
    virtual void walk(){
        cout << "Teenager is with a walking stick" << endl;
    }
};

int main(){
    Person baby(new Baby());
    Person teen(new Teenager());
    Person elderly(new Elderly());

    baby.eat();
    baby.walk();
    teen.eat();
    teen.walk();
    elderly.eat();
    elderly.walk();
    return 0;
}
