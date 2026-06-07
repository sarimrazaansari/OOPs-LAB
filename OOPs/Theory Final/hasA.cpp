#include "iostream"
using namespace std;

class Ram{
    int size;

    public:
        Ram(int s){
            if (s>0){
                size=s;
            }
            else cout<<"Error!.."<<endl;
            
        }

        int getSize(){return size;}
};

class USB{
    int storage;

    public:
        USB(int s){
            if (s>0){
                storage=s;
            }
            else cout<<"Error!.."<<endl;
            
        }

        int getSto(){return storage;}
    
};

class CPU{
    Ram *ram;
    USB *usb;
    string name;

    public:
        CPU(string n, int size,USB *ptr):name(n){
            ram= new Ram(size);
            usb=ptr;
        }

        void display(){
            cout<<"RAM: "<<ram->getSize()<<endl;
            cout<<"USB: "<<usb->getSto()<<endl;
            cout<<"name: "<<name<<endl;
        }
};

int main(){
    USB u(1000);
    CPU c("abc",4,&u);

    c.display();
}