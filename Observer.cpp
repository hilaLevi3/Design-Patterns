#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/////////--17. Observer--/////////
class Observable;

class Observer{
public:
    virtual void update(Observable* o, string about) = 0;
};

class Observable{
protected:
    string about;
    vector<Observer*> observers;
public:
    void notify(){
        for (auto it = observers.begin(); it != observers.end(); it++){
            (*it)->update(this, about);
        }
    }
    void addObserver(Observer* o){
        observers.push_back(o);
    }
    void removeObserver(Observer* o){
        auto it = find(observers.begin(), observers.end(), o);
        if (it != observers.end()){
            observers.erase(it);
        }
    }
    virtual string getState() = 0;
};


class UconnScore: public Observable{
    string groupLost;
public:
    void setGroup(string s, bool won){
        groupLost = s;
        if(won){
            about = "won";
        } else {
            about = "loss";
        }
        notify();;
    }
    virtual string getState(){
        return groupLost;
    }
};

class UconnSupporter: public Observer{
public:
    virtual void update(Observable* o, string about){
        UconnScore* u = dynamic_cast<UconnScore*> (o);
        if(u){
            cout << "Uconn update: the group "<< about << " "<<o->getState();
        } else { // stock
            if (about == "up"){
                cout << "your stocks are up" << endl;
            }
            else {
                cout << "nothing interesting" << endl;
            }
        }
    }

    void addObserver() {

    }
};

class StocksFollower: public Observer{
    int stocksBefore = 0;
public:
    virtual void update(Observable* o, string about){
        cout << "The stock are " << about << " to " << o->getState();
    }
};

class Stocks: public Observable{
    int stock = 0;
public:
    void setStocks(int st){
        if(stock < st){
            about = "up";
        } else {
            about = "down";
        }
        stock = st;
        notify();
    }
    virtual string  getState(){
        return to_string(stock);
    }
};


int main(){
    UconnSupporter* us = new UconnSupporter();
    UconnScore u1;
    u1.addObserver(us);
    u1.setGroup("Butler", true); // Uconn update: the group won Butler

    Stocks s;
    s.addObserver(us);
    s.setStocks(3434); //your stocks are up
    return 0;
}
