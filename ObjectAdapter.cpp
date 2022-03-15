#include <iostream>
using namespace std;

/////////--2. Object Adapter--/////////
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

class SorterTask: public Task{
    Sorter* sorter;
public:
    SorterTask(Sorter* s):sorter(s){}
    virtual void doTask(){
        cout << "doing task: ";
        sorter->sort();
    }
};

class MergeSort: public Sorter{
public:
    virtual void sort(){
        cout << "Merge Sort is working" << endl;
    }
};

int main(){
    Task* t1 = new SorterTask(new MergeSort);
    t1->doTask();
    Task* t2 = new SorterTask(new BubbleSorter);
    t2->doTask();
    return 0;
}


