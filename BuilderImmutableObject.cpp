#include <iostream>
using namespace std;

/////////--14. Builder Immutable object--/////////
class House{
    const int windows;
    const string familyName;
    const int rooms; // require
    const string door; // require
    House(int w, int r, string f, string d):windows(w), rooms(r), familyName(f), door(d){
    }
public:
    void printHouseInfo()const{
        cout << "This house has: " << windows << " windows, a " << door << " door, " << rooms <<
             " rooms, and the family that lives in it: " << familyName << endl;
    }
    class HouseBuilder{
        int windows = 1;
        string familyName = "Israel";
        const int rooms;
        const string door;
    public:
        HouseBuilder(int r, string d): rooms(r), door(d){}
        HouseBuilder& setWindows(int w){
            windows = w;
            return *this;
        }
        HouseBuilder& setFamilyName(string f){
            familyName = f;
            return *this;
        }
        House build(){
            return House(this->windows, this->rooms, this->familyName, this->door);
        }
    };
};

int main(){
    House h1 = House::HouseBuilder(3, "wood").build();
    House h2 = House::HouseBuilder(4, "plastic").setFamilyName("Levi").setWindows(7).build();
    h1.printHouseInfo();
    h2.printHouseInfo();
    return 0;
}