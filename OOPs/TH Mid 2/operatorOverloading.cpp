#include "iostream"
using namespace std;

class Rupee{
    int data;

    public:
    Rupee(int data=0):data(data){}

    //These are overloading of mathematical operator means they only perform Rupee + Rupee instead of Rupee obj; obj.data +obj. data

    //Urinary 10->-10
    Rupee operator-(){
        return Rupee(-data);
    }
    //Addition : parameter to add two no
    Rupee operator+(const Rupee &obj){
        return Rupee(data+obj.data);
    }
    //Substraction
    Rupee operator-(Rupee &obj){
        return Rupee(data-obj.data);
    }
    //Addition Assignment
    Rupee operator+=(Rupee &obj){
        data+=obj.data;
        return *this; //sending value of current obj
    }
    //subs assingment operator
    Rupee operator-=(Rupee &obj){
        data-=obj.data;
        return *this;
    } 

    //increament prefix ++c
    Rupee operator++(){
        ++data;
        return *this;
    }
    //decreament prefix --c
    Rupee operator--(){
        --data;
        return *this;
    }

    //increament postfix c++
    Rupee operator++(int){
        Rupee temp=*this;
        data++;
        return temp;
    }

    //deccreament postfix c--
    Rupee operator--(int){
        Rupee temp=*this;
        data--;
        return temp;
    }


    //now for cout-> it can perform cout<<obj(of Rupee Class) instead of cout<<obj.data

    friend ostream& operator<<(ostream& os, Rupee &obj){ //friend to access Rupee 
        os<<obj.data;
        return os;
    } 
};

int main(){
    Rupee wholesale(20);
    Rupee retail;

    retail = wholesale;

    cout<<"Whole sale price: "<<wholesale<<endl;
    cout<<"Retail sale price: "<<retail<<endl;

    Rupee discount(2);
    retail-=discount;
    cout<<"Retail sale price after discount: "<<retail<<endl;

    wholesale = Rupee(34);
    cout<<"New Whole sale price: "<<wholesale<<endl;
    retail=wholesale+10;
    cout<<"Retail sale price: "<<retail<<endl;

    Rupee Profit;
    Profit= retail-wholesale;
    cout<<"Profit: "<<Profit<<endl;
    
    Profit=-Profit; //urinary
    cout<<"Profit: "<<Profit<<endl;

    Profit++;
    cout<<"Profit post inc: "<<Profit<<endl;

    ++Profit;
    cout<<"Profit pre inc: "<<Profit<<endl;

    Profit--;
    cout<<"Profit post dec: "<<Profit<<endl;

    --Profit;
    cout<<"Profit pre dec: "<<Profit<<endl;



}