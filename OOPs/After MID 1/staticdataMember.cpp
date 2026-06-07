#include "iostream"
using namespace std;

class bankAccount{
    int acno;
    string name;
    static float rateOfInterest;
    static int totalUser;

    public:
    bankAccount(int acno,string name):acno(acno),name(name){
        totalUser++;
    };
    void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Account no: "<<acno<<endl;
        cout<<"Rate of Interest"<<rateOfInterest<<endl; //will be same for all member 
    }
    //to get static member using function:

    static int getTotalUser(){
        return totalUser;
    }

};
//syntax of intitialize static member = datatype class :: static_datatype = n;
float bankAccount::rateOfInterest=2.5;

int bankAccount::totalUser=0;

int main(){

    bankAccount Sarim(1234,"sarim");
    bankAccount Ali(4000,"Ali");

    Sarim.displayInfo();
    Ali.displayInfo();

    cout<<"Total user "<< bankAccount::getTotalUser();
    
}