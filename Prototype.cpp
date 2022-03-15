#include <iostream>
#include <map>
using namespace std;

/////////--11. Prototype--/////////
class Docks{ // prototype
protected:
    int size;
    string name;
public:
    Docks(int s, string n): size(s), name(n){}
    virtual Docks* clone() = 0;
    virtual void printInfo(){
        cout << "File name is: " << name << ". File size is: " << size << endl;
    }
    virtual int getSize()const{ return size; }
    virtual string getName() const { return name; }
};

class PDF: public Docks{
public:
    PDF(int s, string n): Docks(s, n+".pdf"){}
    PDF(const PDF& f): Docks(f.getSize(), f.getName()){}
    virtual Docks* clone (){
        return new PDF(*this);
    }
};

class Text: public Docks{
public:
    Text(int s, string n): Docks(s, n + ".txt"){}
    Text(const Text& f): Docks(f.getSize(), f.getName()){}
    virtual Docks* clone(){
        return new Text(*this);
    }
};


int main(){
    Docks* d1 = new Text(40, "helloWorld");
    Docks* d11 = d1->clone();
    Docks* d2 = new PDF(323, "PDF");
    Docks* d22 = d2->clone();

    d11->printInfo();
    d22->printInfo();
    return 0;
}
