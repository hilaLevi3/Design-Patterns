//
// Created by 97255 on 06/02/2022.
//
#include <iostream>
using namespace std;

/////////--3.3 Bridge--/////////
// the remote is controlling the devices. It'll function differently based on different devices
class Machine{
protected:
    int power = 0;
    int maxPower;
    int soundLevel;
public:
    Machine(int max, int sound): maxPower(max), soundLevel(sound){}
    virtual void leftPressed() = 0;
    virtual void rightPressed() = 0;
    void upPressed(){
        soundLevel++;
        cout<<"sound is: " << soundLevel << endl;
    }
    void downPressed(){
        soundLevel--;
        cout<<"sound is: " << soundLevel << endl;
    }
};

class TV: public Machine{
public:
    TV(int max, int sound ): Machine(max, sound){}
    virtual void leftPressed(){
        if (power > 0)
            power--;
        else
            cout<<"min channel!" << endl;
        cout<<"channel is: " << soundLevel << endl;
    }
    virtual void rightPressed(){
        if (power < maxPower)
            power++;
        else
            cout<<"max chanel!" << endl;
        cout<<"channel is: " << soundLevel << endl;
    }
};

class Drill: public Machine{
public:
    Drill(int max, int volume): Machine(max, volume){}
    virtual void leftPressed(){
        if (power > 0)
            power--;
        else
            cout<<"min power!" << endl;
        cout<<"power is: " << power << endl;
    }
    virtual void rightPressed(){
        if (power < maxPower)
            power++;
        else
            cout<<"power chanel!" << endl;
        cout<<"power is: " << power << endl;
    }
};

class Remote {
    Machine *machine;
public:
    Remote(Machine *m) : machine(m) {}

    virtual void rightPressed() { machine->rightPressed(); }

    virtual void leftPressed() { machine->leftPressed(); }

    virtual void upPressed() { machine->upPressed(); }

    virtual void downPressed() { machine->downPressed(); }
};

class TVRemote: public Remote{
    bool isPaused;
public:
    TVRemote(Machine* m): Remote(m){
        isPaused = true;
    }
    void middlePressed(){
        if(isPaused)
            cout << "TV unpaused" << endl;
        else
            cout << "TV paused" << endl;
        isPaused = !isPaused;
    }
};

class DrillRemote: public Remote{
    bool isReversed = false;
public:
    DrillRemote(Machine* m): Remote(m){}
    void reversePressed(){
        if (!isReversed)
            cout << "working in reverse"<<endl;
        else
            cout << "working straight"<<endl;
        isReversed = !isReversed;
    }
};

int main(){
    Remote* r1 = new TVRemote(new TV(3, 15));
    Remote* r2 = new DrillRemote(new Drill(13, 0));
    r1->downPressed();
    r1->downPressed();
    r1->downPressed();
    r2->rightPressed();
    r2->rightPressed();
    r2->rightPressed();
    r2->rightPressed();
    r2->leftPressed();
    r2->leftPressed();
    r2->rightPressed();
    TVRemote* tvRemote1 = dynamic_cast<TVRemote*>(r1);
    tvRemote1->middlePressed();
    tvRemote1->middlePressed();
    tvRemote1->middlePressed();
    return 0;
}
