#include "iostream"
using namespace std;

class Entity{
    int hp;
    public:
        Entity(int hp):hp(hp){}
        int getHP(){return hp;}
};

class Warrior:virtual public Entity{
    public:
        Warrior(int hp):Entity(hp){}
};

class Mage:virtual public Entity{
    public:
        Mage(int hp):Entity(hp){}
};

class Paladin:public Warrior, public Mage{
    public:
        Paladin(int hp):Entity(hp),Warrior(hp),Mage(hp){}
};

int main(){
    Paladin p(100);
    p.getHP();
}

