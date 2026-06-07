#include "iostream"
using namespace std;



class GrandParent{
    public:
    int x=10;
    void show(){
        cout<<"Class A::x= "<<x<<endl;
    }
};

class Parent1:virtual public GrandParent{
    public:
    void functB(){
        cout<<"B"<<endl;
    }
};

class Parent2:virtual public GrandParent{
    public:
    void functC(){
        cout<<"C"<<endl;
    }
};

class Child:public Parent1,public Parent2{
};

int main(){
    Child d;
    // d.show(); ->ambigous
    d.show();

    d.x=8;
    d.show();
}