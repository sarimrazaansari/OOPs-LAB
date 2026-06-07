#include "iostream"
using namespace std;

class Account{
    protected:
        double balance;
        string name;
        int accNo;
    private:
        int pin;

    public:
        Account(string n,int a,int p, double b):name(n),accNo(a){
            if (b>0){
                balance=b;
            }
            else{
                cout<<"Negative Balance Error!...."<<endl;
                balance=0;
            }
            
            if(p<1000||p>9999){
                cout<<"4 digit pin error!..."<<endl;
                pin=1234;
            }
            else pin=p;
        }

        bool verifyPin(int p){
            return pin==p;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Balance: "<<balance<<endl;
            cout<<"Account no. : "<<accNo<<endl;
        }
};

class SavingAccount:public Account{
    int interestRate;
    int monthlyLimit;

    public:
        SavingAccount(string n,int a,int p, double b,int iR,int mL):Account(n,a,p,b){
            interestRate=(iR<25)?iR:25;
            monthlyLimit=mL;
        }
        void deposit(double b,int pin){
            if (verifyPin(pin)){
                balance+=b;
                cout<<"Deposit Successful!..."<<endl;

            }
            else cout<<"Wrong Pin..."<<endl;
        }

        void withdraw(double b,int pin){
            if (verifyPin(pin)&&b<monthlyLimit&&b<=balance){
                balance-=b;
                monthlyLimit-=b;
                cout<<"Wthdraw Successful!..."<<endl;
            }
            else cout<<"Wrong Pin OR Monthly Limit achieve OR balnce is not more..."<<endl;
        }

        void applyInterest(){
            balance=balance*(1+interestRate/100);
        }
        void display(){
            Account::display();
            cout<<"Interest Rate: "<<interestRate<<endl;
            cout<<"Remainng WithDraw: "<<monthlyLimit<<endl;
        }
};

class CurrentAccount:public Account{
    int overDraft;

    public:
        CurrentAccount(string n,int a,int p, double b, int oD):Account(n,a,p,b){
            overDraft=(oD<50000)?oD:50000;
        }

        void withdraw(double b,int pin){
            if (verifyPin(pin)){
                if(b<=balance){
                    balance-=b; 
                    cout<<"Wthdraw Successful!..."<<endl;
                }
                else if(b<=balance+overDraft){balance-=b;
                    cout<<"Wthdraw Successful!..."<<endl;}
                else cout<<"OverDraft Error!..."<<endl;
            }            
        }

        void display(){
            Account::display();
        }
}; 

int main(){
    SavingAccount saving("John",1,5555,1000,20,500);
    CurrentAccount current("Sarim",2,6767,500,100);

    saving.deposit(1,5555);
    saving.withdraw(500,5555);

    saving.display();

    current.withdraw(550,6767);
    current.display();
}