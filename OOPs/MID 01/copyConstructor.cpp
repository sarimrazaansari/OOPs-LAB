#include "iostream"
using namespace std;

class student{
    public:
    string name;
    double *cgpa;

    student(string n, double c){
        name=n;
        cgpa=new double (c);
        // *cgpa=c;
    };
    //shallow
    // student(student &obj){
    //     name=obj.name;
    //     cgpa=obj.cgpa;
    // };

    //deep
    student(student &obj){
        name=obj.name;
        cgpa=new double (*obj.cgpa);
        //this time we are sending value instead of reference;
    };


    void info(){
        cout<<"Name :"<<name<<endl;
        cout<<"cgpa :"<<*cgpa<<endl;
    };

    ~student(){
        delete cgpa; // deallocte cgpa
        cout<<"Deleted evetything \n";

    }
};

int main(){
    student s1("sarim",3.9);
    s1.info();

    student s2(s1);
    s2.name="Ali";
    *s2.cgpa=5;
    s1.info();
    s2.info();
}