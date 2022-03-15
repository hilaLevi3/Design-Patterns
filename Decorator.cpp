#include <iostream>
#include <list>
using namespace std;
/////////--5.1 Decorator--/////////
class FastFood{
protected:
    int price;
public:
    int getPrice(){ return price; }
    virtual void eat() = 0;
    virtual int overAllPrice() = 0;
};

class Pizza: public FastFood{
public:
    Pizza(){ price = 7; }
    virtual void eat(){
        cout << "im eating pizza, the price is: " << price << endl;
    }
    virtual int overAllPrice(){
        return price;
    }
};

class Hamburger: public FastFood{
public:
    Hamburger(){ price = 27; }
    virtual void eat(){
        cout << "im eating hamburger, the price is: " << price << endl;
    }
    virtual int overAllPrice(){
        return price;
    }
};

class Addition: public FastFood{
protected:
    FastFood* ff;
public:
    Addition(FastFood* f){ ff = f; }
    virtual void eat(){ ff->eat(); }
    virtual int overAllPrice(){
        return ff->overAllPrice();
    }
};

class Chips: public Addition{
public:
    Chips(FastFood* f): Addition(f){ price = 15; }
    virtual void eat(){
        Addition::eat();
        cout << "and chips, the additional price is: "<< price << endl;
    }
    virtual int overAllPrice(){
        return Addition::overAllPrice() + price;
    }
};

class Tomatoes: public Addition{
public:
    Tomatoes(FastFood* f): Addition(f){ price = 3; }

    virtual void eat(){
        Addition::eat();
        cout << "and tomatoes, the additional price is: "<< price << endl;
    }
    virtual int overAllPrice(){
        return Addition::overAllPrice() + price;
    }
};

int main(){
    FastFood* f1 = new Chips(new Tomatoes(new Hamburger()));
    f1->eat();
    cout << f1->overAllPrice() << endl;
    cout << "---------------------------" << endl;
    FastFood* f2 = new Tomatoes(new Pizza());
    f2->eat();
    cout << f2->overAllPrice() << endl;
    return 0;
}