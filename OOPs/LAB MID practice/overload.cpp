#include "iostream"
using namespace std;

class Employee{
    protected:
    double amount;
    
    public:
    Employee(){
        amount=0;
    }
    Employee(double amount){
        this->amount=amount;
    }

    void virtual display(){
        cout<<"Amount: "<<amount<<endl;
    }
};

class Manager:public Employee{
    double amount;

    public:
    Manager(int a):amount(a){};

    void display(){
        cout<<"Amount: "<<amount*1.5<<endl;
    }
};

class Developer:public Employee{
    double amount;

    public:
    Developer(double a):amount(a){}

    void display(){
        cout<<"Amount: "<<amount*2<<endl;
    }
};

int main(){

    Employee *a;
    Manager m(5);
    Developer d(2);

    a=&m;
    a->display();
    a=&d;
    a->display();
    

}