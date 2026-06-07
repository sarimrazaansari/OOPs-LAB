#include "iostream"
using namespace std;

class Shallow{
    int *no;

    public:
    Shallow(int *n){
        no=new int[3];
        for (int i = 0; i < 3; i++)
        {
            no[i]=n[i];
        }
        
    }
    void display(){
        for (int i = 0; i < 3; i++)
        {
            cout<<"The value of "<<i+1<<" is: "<<no[i]<<endl;
            cout<<"The address of "<<i+1<<" is: "<<&no[i]<<endl;
        }
        
    }
    void change(int n){
        *no=n;
    }
    ~Shallow(){
        delete [] no;
    }

};

class deep{
    int *no;

    public:
    deep(int *n){
        no=new int [3];
        for (int i = 0; i < 3; i++)
        {
            no[i]=n[i];
        }
    }
    deep(deep &obj){
        no=new int [3];
        for (int i = 0; i < 3; i++)
        {
            no[i] = obj.no[i];
        }
        
    }
    void display(){
        for (int i = 0; i < 3; i++)
        {
            cout<<"The value of "<<i+1<<" is: "<<no[i]<<endl;
            cout<<"The address of "<<i+1<<" is: "<<&no[i]<<endl;
        }
        
    }
    void change(int n){
        *no=n;
    }
    ~deep(){
        delete[]no;
    }
};

int main(){
    int arr[3]={1,2,3};
    Shallow s1(arr);
    Shallow s2=s1;
    s2.change(4);
    s1.display();
    s2.display();

    cout<<"DEEP:"<<endl;
    deep d1(arr);
    deep d2=d1;
    d2.change(9);
    d1.display();
    d2.display();
}