#include "iostream"
using namespace std;

class Gadget{
    public:
        virtual int getBattery()=0;
};

class Phone:public Gadget{
    int battery;

    public:
        Phone(int b):battery(b){};

        int getBattery() override{
            return battery;
        }
};

class Tablet:public Gadget{
    int battery;

    public:
        Tablet(int b):battery(b){};

        int getBattery() override{
            return battery;
        }
};

template <typename T>
T compare(T a, T b){
    if (a.getBattery()>b.getBattery()){
        return a;
    }
    else return b;
}

int main(){
    Phone p1(100),p2(200);
    Phone comparePhone=compare(p1,p2);

    cout<<"Compare Phone: "<<comparePhone.getBattery()<<endl;

    Tablet t1(20),t2(10);
    Tablet compareTablet=compare(t1,t2);
    cout<<"Compare Tablet: "<<compareTablet.getBattery();
}

