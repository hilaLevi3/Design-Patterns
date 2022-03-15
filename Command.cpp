#include <iostream>
#include <map>
#include <functional>

using namespace std;
//////////--20.1 Command--/////////
class Command{
public:
    virtual void execute() = 0;
};

class Remote{
    Command* up;
    Command* down;
    Command* power;
public:
    Remote(Command* u, Command* d, Command* on): up(u), down(d), power(on){}
    void upPressed(){
        up->execute();
    }
    void downPressed(){
        down->execute();
    }
    void powerPressed(){
        power->execute();
    }
};

class MachineReceiver{
protected:
    int volume = 0;
    int maxVolume = 100;
    bool on = false;
public:
    int getMaxVol(){
        return maxVolume;
    }

    int getVolume(){
        return volume;
    }

    void volumeUp(){
        volume++;
    }
    void volumeDown(){
        volume--;
    }
    void onOff(){
        on = !on;
    }
    virtual void printInfo() = 0;
};

class Radio: public MachineReceiver{
public:
    void printInfo(){
        cout << "The volume of the radio is: " << volume << ", and the power is turned " << on << endl;
    }
};

class UpCommand: public Command{
    MachineReceiver* mr;
public:
    UpCommand(MachineReceiver* mr):mr(mr){}
    virtual void execute(){
        if(mr->getMaxVol() > mr->getVolume())
            mr->volumeUp();
        else
            cout << "Volume at max" << endl;
    }
};

class DownCommand: public Command{
    MachineReceiver* mr;
public:
    DownCommand(MachineReceiver* mr):mr(mr){}
    virtual void execute(){
        if(mr->getVolume() > 0)
            mr->volumeDown();
        else
            cout << "Volume at min" << endl;
    }
};

class PowerCommand: public Command{
    MachineReceiver* mr;
public:
    PowerCommand(MachineReceiver* mr):mr(mr){}
    virtual void execute(){
        mr->onOff();
    }
};


int main(){
    MachineReceiver* mr = new Radio();
    Remote* r = new Remote(new UpCommand(mr), new DownCommand(mr), new PowerCommand(mr));
    mr->printInfo();
    r->downPressed();
    r->powerPressed();
    for (int i = 0; i < 100; i++){
        r->upPressed();
    }
    mr->printInfo();
    r->upPressed();
    mr->printInfo();

    return 0;
}