#include <iostream>
#include <map>
using namespace std;

/////////--15. Interpreter--/////////
class MathExpression{
public:
    virtual void printExp() = 0;
    virtual float evaluate(map<string, float> m) =0;

};

class TerminalExp: public MathExpression{
};

class Variable: public TerminalExp{
    string x;
public:
    Variable(string s):x(s){}
    virtual void printExp(){
        cout << x;
    }
    virtual float evaluate(map<string, float> m){
        return m[x];
    }
};

class Number: public TerminalExp{
    float x;
public:
    Number(float f):x(f){}
    virtual void printExp() {
        cout << x;
    }
    virtual float evaluate(map<string, float> m) {
        return x;
    }
};

class BinaryExp: public MathExpression{
protected:
    MathExpression* a, *b;
public:
    BinaryExp(MathExpression* x, MathExpression* y): a(x), b(y){}
};

class AddExp: public BinaryExp{
public:
    AddExp(MathExpression* a, MathExpression* b): BinaryExp(a, b){}
    virtual void printExp(){
        a->printExp();
        cout  <<  " + ";
        b->printExp();
    }
    virtual float evaluate(map<string, float> m){
        return a->evaluate(m) + b->evaluate(m);
    }
};

class SubExp: public BinaryExp{
public:
    SubExp(MathExpression* a, MathExpression* b): BinaryExp(a, b){}
    virtual void printExp(){
        a->printExp();
        cout << " - ";
        b->printExp();
    }
    virtual float evaluate(map<string, float> m){
        return a->evaluate(m) - b->evaluate(m);
    }
};
int main(){
    Variable v("x");
    Number n(34.3);
    MathExpression* e1 = new AddExp(&v, &n);
    MathExpression* e2 = new SubExp(e1, &v);
    map<string, float> m;
    m.insert({"x", 9});
    e2->printExp();
    cout << "\n" << e2->evaluate(m) << endl;
    return 0;
}
