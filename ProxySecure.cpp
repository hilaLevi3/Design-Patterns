#include <iostream>
#include <map>
using namespace std;

/////////--8.2. Proxy (security)--/////////
class Client{
protected:
    int id;
public:
    int getId() const {
        return id;
    }
};
class ClientA: public Client{
public:
    ClientA(){
        id = 0;
    }
};

class ClientB: public Client{
public:
    ClientB(){
        id = 1;
    }
};

class ClientC: public Client{
public:
    ClientC(){
        id = 2;
    }
};

class ClientD: public Client{
public:
    ClientD(){
        id = 3;
    }
};

class SecureData{
public:
    virtual
    string getNotSecureData(Client* c) = 0;

    virtual
    string getSomeSecureData(Client* c) = 0;

    virtual
    string getMostSecureData(Client* c) = 0;
};

class RealData:public SecureData{
public:
    string getNotSecureData(Client* c){
        return "not secure - REAL";
    }

    string getSomeSecureData(Client* c){
        return "little secure - REAL";
    }

    string getMostSecureData(Client* c){
        return "most secure - REAL";
    }
};

class ProxySecure: public SecureData{
    RealData realData;
public:
    string getNotSecureData(Client* c){
        return realData.getNotSecureData(c);
    }

    string getSomeSecureData(Client* c){
        if (c->getId() < 2) {
            return realData.getSomeSecureData(c);
        }
        return "No Access!";
    }

    string getMostSecureData(Client* c){
        if(c->getId() == 0) {
            return realData.getMostSecureData(c);
        }
        return "No Access!";
    }
};

int main(){
    Client* c1 = new ClientA();
    Client* c2 = new ClientB();
    Client* c3 = new ClientC();
    Client* c4 = new ClientD();

    SecureData* s = new ProxySecure();
    cout << "D + not secure: " << s->getNotSecureData(c4) << endl;
    cout << "D + most secure: " << s->getMostSecureData(c4) << endl;
    cout << "A + most secure: " << s->getMostSecureData(c1) << endl;
    cout << "B + some secure: " << s->getSomeSecureData(c2) << endl;
    cout << "C + some secure: " << s->getSomeSecureData(c3) << endl;
    return 0;
}


