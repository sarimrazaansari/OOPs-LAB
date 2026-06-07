#pragma once

#include "iostream"
using namespace std;

class sharedAccount{
    public:
    double *balance;

    sharedAccount(double b){
        balance= new double (b);
        cout<<"[SHALLOW] Account created"<<endl;
    }

    void withdraw(double amount){
        if(amount>0 && amount <=*balance){
            *balance-=amount;
            cout<<"[SHALLOW] amount withdraw."<<endl;
        }
        else {
            cout <<"Invalid amount"<<endl;
        }
    }

    void display(){
        cout<<"[SHALLOW] Balance ="<<*balance<<endl;
        cout<<"[SHALLOW] Address ="<<balance<<endl;
    }
};

class securedAccount{
    public:
    double *balance;

    securedAccount(double b){
        balance= new double (b);
        cout<<"[DEEP] Account created"<<endl;
    }

    securedAccount(securedAccount &obj){
        balance=new double (*obj.balance);
    }

    void withdraw(double amount){
        if(amount>0 && amount <=*balance){
            *balance-=amount;
            cout<<"[DEEP] amount withdraw."<<endl;
        }
        else {
            cout <<"Invalid amount"<<endl;
        }
    }

    void display(){
        cout<<"[DEEP] Balance ="<<*balance<<endl;
        cout<<"[DEEP] Address ="<<balance<<endl;
    }
};