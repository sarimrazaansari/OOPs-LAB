#include "iostream"
#include "string"
using namespace std;
//Access Modifier = PUBLIC, PRIVATE, PROTECTED
//Encapsulation = is wrapping up data & member function in a single unit. like name, balance, account no = data, and funtions are member function combine in one single unit ie: Class

    // It helps in hiding data (private) to maintain securty and sensitive information

class BankAccount{
    string name;
    double balance;
    int accountNo;
    
    public:

    void setDetails(string n, double bal, int acc){
        name=n;
        balance = bal;
        accountNo=acc;
    };

    void deposit(double amount){
        if (amount<0)
        {
            cout<<"Invalid ammount !";
        }
        else balance +=amount;        
    }

    void withdraw(double amount){
        if (amount<0)
        {
            cout<<"Invalid ammount !";
        }

        else if (amount>0 && amount<balance)
        {
            balance-=amount;
        }

        else cout<<"Insufficient balance";
    }

    void display(){
        cout<<"The name is "<<name<<endl;
        cout<<"The account no is "<<accountNo<<endl;
        cout<<"The balance is "<<balance<<endl;

    }

};


int main(){

    BankAccount Sarim;

    Sarim.setDetails("Sarim",50000,12345);
    Sarim.display();
    Sarim.deposit(10000);
    Sarim.withdraw(5000);
    Sarim.display();
    Sarim.withdraw(999999);

    return 0;
    
}