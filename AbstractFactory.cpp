#include <iostream>
#include <map>
using namespace std;

/////////--10. Abstract Factory--/////////
class Cup{
    int price;
public:
    Cup():price(10){}
    virtual void drink() = 0;
};

class FlowerCup: public Cup{
public:
    virtual void drink(){
        cout << "drinking from a flowered cup"<< endl;
    }
};

class DotsCup: public Cup{
public:
    virtual void drink(){
        cout << "drinking from a doted cup"<< endl;
    }
};

class PlainCup: public Cup{
    virtual void drink(){
        cout << "drinking from a p cup"<< endl;
    }
};

class Plate{
    int price;
public:
    Plate():price(12){}
    virtual void eat ()= 0;
};

class FlowerPlate: public Plate{
public:
    virtual void eat(){
        cout << "eating from a flowered plate"<< endl;
    }
};

class DotsPlate: public Plate{
public:
    virtual void eat(){
        cout << "eating from a doted plate"<< endl;
    }
};

class PlainPlate: public Plate{
    virtual void eat(){
        cout << "eating from a plain plate"<< endl;
    }
};

class Bowl{
    int price;
public:
    Bowl():price(15){}
    virtual void eat() = 0;
};

class FlowerBowl: public Bowl{
public:
    virtual void eat(){
        cout << "eating from a flowered bowl"<< endl;
    }
};

class DotsBowl: public Bowl{
public:
    virtual void eat(){
        cout << "bowl from a doted bowl"<< endl;
    }
};

class PlainBowl: public Bowl{
    virtual void eat(){
        cout << "eating from a p bowl"<< endl;
    }
};

class Restaurant{
public:
    virtual Cup* cupServed() = 0;
    virtual Plate* plateServed() = 0;
    virtual Bowl* bowlServed() = 0;
};

class FlowerServed: public Restaurant{
public:
    virtual Cup* cupServed(){
        return new FlowerCup();
    }
    virtual Plate* plateServed(){
        return new FlowerPlate();
    }
    virtual Bowl* bowlServed(){
        return new FlowerBowl();
    }
};

class PlainServed: public Restaurant{
public:
    virtual Cup* cupServed(){
        return new FlowerCup();
    }
    virtual Plate* plateServed(){
        return new PlainPlate();
    }
    virtual Bowl* bowlServed(){
        return new PlainBowl();
    }
};

class DotsServed: public Restaurant{
public:
    virtual Cup* cupServed(){
        return new DotsCup();
    }
    virtual Plate* plateServed(){
        return new DotsPlate();
    }
    virtual Bowl* bowlServed(){
        return new DotsBowl();
    }
};



int main(){
    Restaurant* rf = new FlowerServed();
    rf->bowlServed()->eat();
    rf->cupServed()->drink();
    rf->plateServed()->eat();
    cout << "------------------------------" << endl;
    DotsServed dt;
    dt.plateServed()->eat();
    dt.cupServed()->drink();
    dt.bowlServed()->eat();
    return 0;
}