#include "iostream"
using namespace std;

class copyCons{
    public:
    double cgpa;

    copyCons(double c): cgpa(c){};

    void display(){
        cout<<"Value is "<<cgpa<<endl;
        cout<<"Address is "<<&cgpa<<endl;
    }

};

class shallow{
    public:
    double *cgpa;

    shallow(double c){
        cgpa = new double (c);
    }

    void display(){
        cout<<"Value is "<<*cgpa<<endl;
        cout<<"Address is "<<cgpa<<endl;
    }
};

class deep{
    public:
    double *cgpa;

    deep(double c){
        cgpa = new double (c);
    };

    deep(deep &obj){
        cgpa = new double (*obj.cgpa);
    }

    void display(){
        cout<<"Value is "<<*cgpa<<endl;
        cout<<"Address is "<<cgpa<<endl;
    }

    ~deep(){
        delete cgpa;

    }

};

int main(){
    cout<<"Copy Constructor"<<endl;
    copyCons c1(4.2);
    c1.display();
    copyCons c2=c1;
    c2.display();


    cout<<"\n\n\nShallow Constructor"<<endl;
    shallow c3(4.2);
    c3.display();
    shallow c4(c3);
    c4.display();

    cout<<"\n\n\nDeep Constructor"<<endl;
    deep c5(4.2);
    c5.display();
    deep c6(c5);
    c6.display();
}