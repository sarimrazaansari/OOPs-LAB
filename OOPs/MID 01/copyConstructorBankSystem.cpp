#include "iostream"
#include "copyConstructorBankSystem.h"

int main(){
    cout<<"SHALLOW copy constructor"<<endl;
    cout<<"=============================================="<<endl;
    sharedAccount s1(1000);
    s1.display();
    sharedAccount s2(s1);
    *s2.balance=250;
    s1.display();

    cout<<"SHALLOW copy constructor"<<endl;
    cout<<"=============================================="<<endl;
    securedAccount s3(1000);
    s3.display();
    securedAccount s4(s3);
    *s4.balance=250;
    s3.display();
    s4.display();



}