#include <iostream>
#include <list>
using namespace std;

/////////--4.2 composite--/////////
class Employee{
protected:
    string name;
    int age;
public:
    Employee(string n, int a):name(n), age(a){
        //superiors = new list<Employee*>;
    }
    virtual void add(Employee* e) = 0;
    virtual void remove(Employee* e) = 0;
    virtual void operation() = 0;
};

class Manager: public Employee{
    list<Employee*> superiors;
public:
    Manager(string name, int age):Employee(name, age){}
    void add(Employee* e){
        superiors.push_front(e);
    }
    void remove(Employee* e){
        superiors.remove(e);
    }
    virtual void operation(){
        cout << "Manager " << name <<" is working" << endl;
        auto it = superiors.begin();
        for(; it!= superiors.end(); it++){
            (*it)->operation();
        }
    }

    Manager& operator=(const Manager& m){
        name = m.name;
        age = m.age;
        return *this;
    }

    friend ostream& operator << (ostream& o, const Manager&  );
};

ostream& operator << (ostream& o, const Manager& m){
    return o << m.name;
}

class Engineer: public Employee{
public:
    Engineer(string name, int age): Employee(name, age){}
    virtual void add(Employee* e){}
    virtual void remove(Employee* e){}
    virtual void operation(){
        cout << "Engineer " << name << " is working" << endl;
    }
};

class Architect: public Employee{
public:
    Architect(string name, int age): Employee(name, age){}
    virtual void add(Employee* e){}
    virtual void remove(Employee* e){}
    virtual void operation(){
        cout << "Architect " << name << " is working" << endl;
    }
};

int main(){
    Employee* e1 = new Manager("Dani", 50);
    Employee* e2 = new Manager("Dina", 25);
    Employee* e3 = new Manager("Daniel", 47);

    Employee* e4 = new Engineer("Edi", 24);
    Employee* e5 = new Engineer("Eli", 35);
    Employee* e6 = new Engineer("Ella", 33);
    Employee* e7 = new Engineer("Eliana", 29);

    Employee* e8 = new Architect("avi", 23);
    Employee* e9 = new Architect("avia", 28);
    Employee* e10 = new Architect("aviv", 48);

    e1->add(e4);
    e1->add(e8);
    e1->add(e2);

    e2->add(e3);
    e2->add(e5);
    e2->add(e9);

    e3->add(e6);
    e3->add(e7);
    e3->add(e10);

    e2->operation();
    e3->remove(e10);
    cout << "------------------" << endl;
    e2->operation();

    return 0;
}


