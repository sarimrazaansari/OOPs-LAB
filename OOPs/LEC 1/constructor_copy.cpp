#include <iostream>
using namespace std;

class student{
    public:
    string name;
    double gpa;

    public:
    student(string name, double gpa){
        this->name=name;
        this->gpa=gpa;
    }

    void displayDetail(){
        cout<<"Name :"<<name<<endl;
        cout<<"GPA : "<<gpa<<endl;
    };

    //our own default constructor:
    student(student &obj){
        this->name=obj.name;
        this->gpa=obj.gpa;
    }

};

int main(){
    student s1("Sarim",3.59);
    student s2(s1);     //default copy constructor, this is syntax
    s1.displayDetail();
    s2.gpa=8;           //that means the default constructor is (shallow) //it will cause no prob w/o pointers
    s1.displayDetail();
    s2.displayDetail();
}