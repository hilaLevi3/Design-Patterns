#include <iostream>
using namespace std;

/////////--6. Facade--/////////
class Character{
public:
    void create(){ cout << "create character" << endl; }
};

class Maze{
public:
    void create(){ cout << "create maze" << endl; }
};

    class Obstacle{
public:
    void create(){ cout << "create Obstacle" << endl; }
};

class Enemy{
public:
    void create(){ cout << "create enemy" << endl; }
};

class Facade{
protected:
    Enemy e;
    Obstacle o;
    Maze m;
    Character c;
public:
    virtual void createGame() = 0;
};

class LowLevel: public Facade{
public:
    LowLevel(): Facade(){}
    virtual void createGame(){
        c.create();
        e.create();
        m.create();
        o.create();
    }
};

class HardLevel: public Facade{
public:
    HardLevel(): Facade(){}
    virtual void createGame(){
        c.create();
        e.create(); e.create(); e.create(); e.create();
        m.create();
        o.create(); o.create(); o.create();
    }
};

int main(){
    LowLevel ll;
    ll.createGame();
    cout << "---------------------------" << endl;
    HardLevel hl;
    hl.createGame();
    return 0;
}