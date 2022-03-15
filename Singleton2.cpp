#include <iostream>
#include <vector>
using namespace std;

/////////--13.2. Singleton--/////////
class Singleton{
    static Singleton* s;
    int val;
    Singleton(int v){
        val = v;
    }
public:
    Singleton(Singleton& s) = delete;
    void operator = (const Singleton& s) = delete;
    static Singleton *getInstance(){
        if (Singleton::s == nullptr){
            s = new Singleton(5);
        }
        return s;
    }
};

// type      class  ::var
Singleton* Singleton::s = nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}