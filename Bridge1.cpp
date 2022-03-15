//
// Created by 97255 on 06/02/2022.
//
#include <iostream>

using namespace std;
/////////--3.1 Bridge--/////////
class HouseImp{
public:
    virtual void paintDoor() = 0;
    virtual void paintRoof() = 0;
    virtual void paintWindow() = 0;
    virtual void buildWall() = 0;
};

class BrickHouse: public HouseImp{
    virtual void paintDoor(){
        cout << "painting the door in a brick house" << endl;
    };
    virtual void paintRoof(){
        cout << "painting the roof in a brick house" << endl;
    };
    virtual void paintWindow(){
        cout << "painting the window in a brick house" << endl;
    }
    virtual void buildWall(){
        cout << "building the wall in a brick house" << endl;
    }
};

class WoodHouse: public HouseImp{
    virtual void paintDoor(){
        cout << "painting the door in a wood house" << endl;
    };
    virtual void paintRoof(){
        cout << "painting the roof in a wood house" << endl;
    };
    virtual void paintWindow(){
        cout << "painting the window in a wood house" << endl;
    }
    virtual void buildWall(){
        cout << "building the wall in a wood house" << endl;
    }
};

class House{ // abstraction
protected:
    HouseImp* h;
public:
    House(HouseImp* _h): h(_h){}
    virtual void paint() = 0;
    virtual void build() = 0;
};

class BigHouse: public House{ // specific abstraction
public:
    BigHouse(HouseImp* _h): House(_h){}
    virtual void paint() {
        cout << "painting big house:" << endl;
        h->paintRoof();
        h->paintWindow();
        h->paintDoor();
    }

    virtual void build(){
        cout << "building big house:" << endl;
        h->buildWall();
    }
};

class RoundHouse: public House{ // specific abstraction
public:
    RoundHouse(HouseImp* _h): House(_h){}
    virtual void paint() {
        cout << "painting round house:" << endl;
        h->paintRoof();
        h->paintDoor();
        h->paintWindow();
    }

    virtual void build(){
        cout << "building round house:" << endl;
        h->buildWall();
    }
};

int main(){
    House* h1 = new BigHouse(new BrickHouse());
    House* h2 = new RoundHouse(new BrickHouse());
    House* h3 = new RoundHouse(new WoodHouse());
    h1->build();
    h1->paint();
    h2->build();
    h2->paint();
    h3->build();
    h3->paint();
    return 0;
}