#include "iostream"
using namespace std;

class Number{
    public:
    int value;
    string name;

    public:
        Number(int v,string n):value(v),name(n){}

        //operator Overload

        //asssignment
        Number& operator=(const Number& obj){
            value=obj.value;
            name=obj.name;
            return *this;
        } 
        //urinary
        Number operator-(){
            return Number(-value,name);
        }

        
        Number operator+(const Number& obj){
            return Number(value+obj.value,name);
        }
        Number operator-(const Number& obj){
            return Number(value-obj.value,name);
        }
        
        bool operator==(const Number& obj){
            return value==obj.value;
        }
        bool operator<(const Number& obj){
            return value<obj.value;
        }
        bool operator>(const Number& obj){
            return value>obj.value;
        }

        Number& operator++(){
            ++value;
            return *this;
        }
        Number& operator--(){
            --value;
            return *this;
        }

        Number operator++(int){
            Number temp=*this;
            value++;
            return temp;
        }
        Number operator--(int){
            Number temp=*this;
            value--;
            return temp;
        }

        friend ostream& operator<<(ostream& os,const Number& obj){
            os<<obj.value<<endl;
            return os;
        }

        friend istream& operator>>(istream& os, Number& obj){
            os>>obj.value;
            return os;
        }

};

int main(){
    Number a(10,"Ali"),b(20,"Sarim");

    Number c=a+b;
    cout<<c;

    Number D=a-b;
    cout<<D;

    cout<<a++;
    cout<<++a;
    cout<<-b;
}   