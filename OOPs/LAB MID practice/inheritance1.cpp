#include "iostream"
using namespace std;

class Vehicle{
    int id;
    string brand;
    int capacity;

    public:
    Vehicle(int id, string b,int c):id(id),brand(b),capacity(c){}

    void displayVehicle(){
        cout<<"ID: "<<id<<" | Brand: "<<brand<<" | Capactity: "<<capacity<<endl;
    }
};

class Truck:public Vehicle{
    int loadCapacity;
    public:
    Truck(int id, string b,int c,int lC):Vehicle(id,b,c),loadCapacity(lC){}
    void displayTruck(){
        displayVehicle();
        cout<<"load Capacity: "<<loadCapacity<<endl;
    }
};

class Vans:public Vehicle{
    int passengerCapacity;
    public:
    Vans(int id, string b,int c,int pC):Vehicle(id,b,c),passengerCapacity(pC){}
    void displayVans(){
        displayVehicle();
        cout<<"Passenger Capacity: "<<passengerCapacity<<endl;
    }
};

class Bike:public Vehicle{
    int fuelEff;
    public:
    Bike(int id, string b,int c,int fE):Vehicle(id,b,c),fuelEff(fE){}
    void displayBike(){
        displayVehicle();
        cout<<"Fuel Eff: "<<fuelEff<<endl;
    }
};

class RefrigeratedTruck:public Truck{
    int temprature;
    public:
    RefrigeratedTruck(int id, string b,int c,int fE,int t):Truck(id,b,c,fE),temprature(t){}
    void displayRefrigeratedTruck(){
        displayTruck();
        cout<<"Temprature: "<<temprature<<endl;
    }
};

class Driver{
    string name;
    string licenseType;

    public:
    Driver(string n,string l):name(n),licenseType(l){}
    void displayDriver(){
        cout<<"Name: "<<name<<" | License Type: "<<licenseType<<endl;
    }
};

class DeliveryAgent:public Driver,public Vehicle{
    public:
    DeliveryAgent(string n,string l,int id, string b,int c):Driver(n,l),Vehicle(id,b,c){}

    void displayDeliveryAgent(){
        displayVehicle(); 
        displayDriver();
    }

};

int main(){
    Truck T(1,"Truck",10,9);
    T.displayTruck();

    Vans V(2,"Suzuki",5,4);
    V.displayVans();

    Bike B(3,"Honda",2,250);
    B.displayBike();

    RefrigeratedTruck RF(4,"abc",99,4,98);
    RF.displayRefrigeratedTruck();

    DeliveryAgent D("Ali","Newbie",5,"Honda",5);
    D.displayDeliveryAgent();

}
 