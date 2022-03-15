#include <iostream>
#include <list>
using namespace std;

/////////--4.1 composite--/////////
class Object{
    string type;
public:
    virtual void add(const Object& o) = 0;
    virtual void remove(const Object& t) = 0;
    virtual void operation() const = 0;
};

class Box: public Object{
    list<const Object*> boxContent;
public:
    virtual void add(const Object& o){
        boxContent.push_back(&o);
    }
    virtual void remove(const Object& o){
        boxContent.remove(&o);
    }
    virtual void operation()const{
        for (auto it = boxContent.begin(); it!=boxContent.end(); it++){
            (*it)->operation();
        }
    }
};

template <class T> class SpecificObject: public Object{
    T t;
public:
    SpecificObject(const T& nt){
        t = nt;
    }
    virtual void operation() const {
        cout << t << endl;
    }
    virtual void add(const Object& o){}
    virtual void remove(const Object& o){}
};

int main(){
    SpecificObject<int> s1(4);
    SpecificObject<float> s2(4.435);
    SpecificObject<string> s3("hello world");
    Box b1;
    b1.add(s1);
    b1.add(s2);
    b1.add(s3);
    Box b2;
    b2.add(b1);
    b2.operation();
    return 0;
}