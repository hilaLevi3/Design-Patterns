#include <iostream>
#include <map>
using namespace std;

/////////--8.1. Proxy (cache)--/////////
class Calculator{
public:
    virtual int add(int a, int b) = 0;
    virtual int sub(int a, int b) = 0;
    virtual int div(int a, int b) = 0;
    virtual int mult(int a, int b) = 0;
};

class RealCalc: public Calculator{
public:
    virtual int add(int a, int b){
        cout << "return from calc" << endl;
        return a + b;
    }
    virtual int sub(int a, int b){
        cout << "return from calc" << endl;
        return a - b;
    }
    virtual int div(int a, int b){
        cout << "return from calc" << endl;
        return a / b;
    }
    virtual int mult(int a, int b) {
        cout << "return from calc" << endl;
        return a * b;
    }
};


class CalcProxy: public Calculator{
    RealCalc realCalc;
    map<string , int> addCache;
    map<string , int> subCache;
    map<string , int> divCache;
    map<string , int> multCache;
public:
    virtual int add(int a, int b){
        string  s = to_string(a)+ to_string(b);
        auto it = addCache.find(s);
        if(it!=addCache.end()){
            cout << "return from cache" << endl;
            return addCache[s];
        }
        int i = realCalc.add(a, b);
        addCache.insert(pair<string, int>(s, i));
        return i;
    }
    virtual int sub(int a, int b){
        string s = to_string(a) + to_string(b);
        if (subCache.find(s) != subCache.end()){
            cout << "return from cache" << endl;
            return subCache[s];
        }
        int i = realCalc.sub(a, b);
        subCache.insert(pair<string, int>(s, i));
        return i;
    }
    virtual int div(int a, int b){
        string s = to_string(a) + to_string(b);
        if(divCache.find(s) != divCache.end()){
            cout << "return from cache" << endl;
            return divCache[s];
        }
        int i = realCalc.div(a, b);
        divCache.insert(pair<string, int>(s, i));
        return i;
    }
    virtual int mult(int a, int b) {
        string s = to_string(a) + to_string(b);
        if(multCache.find(s) != multCache.end()){
            cout << "return from cache" << endl;
            return multCache[s];
        }
        int i = realCalc.mult(a, b);
        multCache.insert(pair<string, int>(s, i));
        return i;
    }
};
int main(){
    Calculator* c = new CalcProxy();
    int a= c->add(4, 6);
    cout << a << endl;
    a = c->add(4, 6);
    cout << a << endl;
    cout << "---------------------------" << endl;
    a = c->mult(4, 6);
    cout << a << endl;
    a = c->mult(4, 6);
    cout << a << endl;
    cout << "---------------------------" << endl;
    a = c->div(4, 6);
    cout << a << endl;
    a = c->div(4, 6);
    cout << a << endl;
    cout << "---------------------------" << endl;
    a = c->sub(4, 6);
    cout << a << endl;
    a = c->sub(4, 6);
    cout << a << endl;
    cout << "---------------------------" << endl;
    return 0;
}


