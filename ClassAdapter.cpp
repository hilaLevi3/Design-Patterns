#include <iostream>
using namespace std;
/////////--1. Class Adapter--/////////
class Task{ // target (what the client knows)
public:
    virtual void doTask() = 0;
};

class Sorter{ // adaptee
public:
    virtual void sort() = 0;
};

class BubbleSorter: public Sorter{ // specific adaptee
public:
    virtual void sort(){
        cout << "Bubble Sorter is working" << endl;
    }
};

class BubbleSorterTask: public  BubbleSorter, public Task{ // adapter (take both of the things)
public:
    virtual void doTask(){
        cout << "doing task: ";
        sort();
    }
};

int main() {
    Task* t1 = new BubbleSorterTask();
    t1->doTask();
    return 0;
}
