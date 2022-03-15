#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/////////--12.1. Builder--/////////
class Level{
protected:
    vector<string> enemies;
    vector<string> characters;
public:
    virtual void setEnemy(string s) = 0;
    virtual void setCharacters(string s) = 0;
    void printLevel(){
        for_each(enemies.begin(), enemies.end(), [](string s){
            cout << s << endl;
        });
    }
};

class AladinLevel: public Level{
public:
    virtual void setEnemy(string s){
        enemies.push_back(s + " Aladin");
    }
    virtual void setCharacters(string s){
        enemies.push_back(s + " Aladin");
    }
};

class MarioLevel: public Level{
public:
    virtual void setEnemy(string s){
        enemies.push_back(s + " Mario");
    }
    virtual void setCharacters(string s){
        enemies.push_back(s + " Mario");
    }
};

class LevelBuilder{
protected:
    Level* l;
public:
    LevelBuilder(){}
    virtual void BuildEnemy() = 0;
    virtual void BuildCharacter() = 0;
    virtual void resetLevel() = 0;
    virtual Level* getLevel(){
        return l;
    }
};

class MarioLevelBuilder: public LevelBuilder{
public:
    virtual void BuildEnemy(){
        l->setEnemy("Mashrooms");
    }
    virtual void BuildCharacter(){
        l->setCharacters("Mario");
        l->setCharacters("");
    }
    virtual void resetLevel(){
        l = new MarioLevel();
    }
};
class AladinLevelBuilder: public LevelBuilder{

    virtual void BuildEnemy(){
        l->setEnemy("Jafar");
    }
    virtual void BuildCharacters(){
        l->setCharacters("Aladin");
        l->setCharacters("Abu");
        l->setCharacters("Jasmin");
    }
    virtual void resetLevel(){
        l = new AladinLevel();
    }
};

class LevelDirector{
protected:
    LevelBuilder* levelBuilder;
public:
    LevelDirector(LevelBuilder* ld): levelBuilder(ld){}
    void setLevelBuilder(LevelBuilder* lb){
        levelBuilder = lb;
    }
    virtual Level* create() = 0;
};

class BossLevelDirector: public LevelDirector{
public:
    BossLevelDirector(LevelBuilder* ld): LevelDirector(ld){}
    Level* create(){
        levelBuilder->resetLevel();
        levelBuilder->BuildEnemy();
        levelBuilder->BuildEnemy();
        levelBuilder->BuildEnemy();
        levelBuilder->BuildEnemy();
        levelBuilder->BuildCharacter();
        return levelBuilder->getLevel();
    }
};

class SimpleLevelDirector: public LevelDirector{
public:
    SimpleLevelDirector(LevelBuilder* ld): LevelDirector(ld){}
    Level* create(){
        levelBuilder->resetLevel();
        levelBuilder->BuildEnemy();
        levelBuilder->BuildCharacter();
        levelBuilder->BuildCharacter();
        return levelBuilder->getLevel();
    }
};

int main(){
    LevelBuilder* lb = new MarioLevelBuilder();
    LevelDirector* ld1= new BossLevelDirector(lb);
    Level* l = ld1->create();
    l->printLevel();

    return 0;
}