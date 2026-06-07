#include "iostream"
using namespace std;

class Ram{
    int storage;
    int slots;

    public:
        Ram(int store,int slo):storage(store),slots(slo){};

        void DisplayRam(){
            cout<<"Storage: "<<storage<<endl;
            cout<<"slots: "<<slots<<endl;
        }
};

class USB{
    string nameU;
    int USBstorage;

    public:
        USB(string n, int sto):nameU(n),USBstorage(sto){}
        void DisplayUSB(){
            cout<<"name: "<<nameU<<endl;
            cout<<"USBstorage: "<<USBstorage<<endl;
        }
};

class Computer{
    string model;
    Ram *ram;
    USB *usb;

    public:
    Computer(string m):model(m){};
    
    // composition: make constructor inside class
        void addRam(int sto,int slo){
            ram=new Ram(sto,slo);
        }
    // Aggreagation: USB will be add by main -> so will pass by reference
        void addUSB(USB *u){
            usb=u;
        }

        void display(){
            cout<<"NAME: "<<model<<endl;
            ram->DisplayRam();
            usb->DisplayUSB();
        }

};

int main(){
    USB u("abc",256);

    Computer c("i7");
    c.addRam(8,2);
    c.addUSB(&u);
    c.display();
}