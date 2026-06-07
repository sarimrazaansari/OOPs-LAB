#include <iostream>
using namespace std;

class employee{
    string name;
    const int id;

    public:
    //no need in function to make const int
    employee(string name, int id): name(name),id(id){};

    void displayInfo() const{
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
    }

    void updName(string newname){
        name=newname;
    }
    // this will show error cont of const
    // void updid(string newid){
    //     id=newid;
    // }
};

int main(){
    employee e1("Sarim",5555);
    e1.displayInfo();
    e1.updName("Ahmed");
    e1.displayInfo();
}