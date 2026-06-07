#include "iostream"
using namespace std;

//note single class can have multiple construtor but should be diff parametrized is called constructor overloading

class teacher{
    double salary;
    string name;
    string department;

    public:
    // //constructor = automatic calls upon creating object 
    // //three types :1.non parametrized 2. parametrized 3.Copy constructor
    // teacher(){  //non paramaterized
    //     department="Computer science";
    // }

    //paramertizrd
    teacher(string n, double s,string d){
        name=n;
        salary=s;
        department=d;
    }


    //setter
    void setSalary(double salary){
        this->salary=salary;
    }
    void setName(string name){
        this->name=name;
    }
    void setDepartment(string department){
        this->department=department;
    }


    //getter
    double getSalary(){
        return salary;
    }
    string getName(){
        return name;
    }
    string getDepartment(){
        return department;
    }

    void display(){
        cout<<"Name is "<<name<<endl;
        cout<<"salary is "<<salary<<endl;
        cout<<"department is "<<department<<endl;
    }
    
};

int main(){

    

    // t1.setName("Sarim");
    // t1.setSalary(9999999.99);
    
    // cout<<t1.getName()<<endl;
    // cout<<t1.getSalary()<<endl;
    // cout<<t1.getDepartment()<<endl;

    //Parametrized  
    teacher t1("Sarim" , 900000, "AI");
    teacher t2=t1; // or  teacher t2(t1)
    t1.display();

    t2.display();
}