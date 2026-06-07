#include "iostream"
#include "stdexcept"
using namespace std;

class InsufficientFund:public exception{
    public:
        const char* what() const noexcept override{
            return "Insifficient Balance";
        }
};

class Account{
    int balance=1000;

    public:
        void withDraw(int b){
            if (b<balance){
                balance-=b;
                cout<<"Balance With Draw| Current Balance: "<<balance<<endl;
            }
            else throw InsufficientFund();
        }
};

int main(){
    Account a;
     try{
        a.withDraw(500);
        a.withDraw(700);
     }

     catch(exception& msg){
        cout<<msg.what()<<endl;
     }
}