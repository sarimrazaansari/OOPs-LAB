#include "iostream"
using namespace std;

class Transaction{
    int transID;
    
    public:
        Transaction(int id):transID(id){}
        virtual double calcFee()=0;
};

class Deposit:public Transaction{
    public:
        Deposit(int id):Transaction(id){}

        double calcFee(){
            return 1.5;
        }
};

class Withdraw:public Transaction{
    public:
        Withdraw(int id):Transaction(id){}

        double calcFee(){
            return 3.0;
        }
};

int main(){
    Deposit d(1);
    Withdraw w(2);
    cout<<"Deposit: "<<d.calcFee()<<endl;
    cout<<"Withdraw: "<<w.calcFee()<<endl;
}
