#include <iostream>
using namespace std;

class student{
    public:
    string *name;
    double *gpa;

    public:
    student(string n, double g){
        name= new string;
        *name=n;
        gpa=new double;
        *gpa=g;
    }

    void displayDetail(){
        cout<<"Name :"<<*name<<endl;
        cout<<"GPA : "<<*gpa<<endl;
    };

    //our own default constructor:
    student(student &obj){
        name=new string;
        *name=*(obj.name);
        gpa=new double;
        *gpa=*(obj.gpa);
    }

};

int main(){
    student s1("Sarim",3.59);
    student s2(s1);     
    s1.displayDetail();
    *(s2.gpa)=8;      //change in s2 didnt change s1 ---> DEEP   
    s1.displayDetail();
    s2.displayDetail();
}