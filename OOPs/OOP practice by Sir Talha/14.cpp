#include "iostream"
using namespace std;

//virtuall is use w/ base class 
class Person{
    int id;
    public:
        Person(int id):id(id){}

        int getID(){return id;}
};

class Student:virtual public Person{
    public:
        Student(int id):Person(id){}
};

class Employee:virtual public Person{
    public:
        Employee(int id):Person(id){}
};

class TA:public Student,public Employee{  //now it shared same id for TA
    public:
        TA(int id):Student(id),Employee(id),Person(id){}
};

int main(){
    TA sarim(250064);

    cout<<sarim.getID();

}