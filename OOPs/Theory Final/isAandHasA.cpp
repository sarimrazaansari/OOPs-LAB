#include "iostream"
using namespace std;

class Address{
    string street;
    string city;

    public:
        Address(string s,string c):street(s),city(c){}

        void displayAddress(){
            cout<<"Street: "<<street<<endl;
            cout<<"city: "<<city<<endl;
        }
};

class Person{
    string name;
    const int age;

    Address *address;
    
    public: 
        Person(string n, int a,string s, string c):name(n),age(a){
            //composition-> constructor inside constructor
            address=new Address(s,c);
        }
    
        // //compostion
        // void addAdress(string s, string c){
        //     address=new Address(s,c);
        // }

        virtual void DisplayDetail(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            address->displayAddress();
        }
};

class Student:public Person{
    static int count;
    int rollNo;

    public:
        Student(string n, int a,string s, string c):Person(n,a,s,c){
            rollNo=count;
            count++;
        }
        

        void DisplayDetail(){
            Person::DisplayDetail();
            cout<<"RollNo: "<<rollNo<<endl;
            cout<<"Total Student: "<<count<<endl;
        }
};

int Student::count=1;

class Department{
    string deptName;

    public:
        Department(string d):deptName(d){}
        string getName(){
            return deptName;
        }

};

class Teacher:public Person{
    Department *dep;

    public:
        Teacher(string n, int a,string s, string c, Department *d):Person(n,a,s,c){
            //aggresgation inside constructor
            dep=d;
        };

        void DisplayDetail(){
            Person::DisplayDetail();
            cout<<"Department: "<<dep->getName()<<endl;
        }


};

class Course{
    string courseName;
    Teacher *teacher;

    public:
        Course(string cN, Teacher *t):courseName(cN){
            teacher=t;
        }

        void displayCourse(){
            cout<<"Cource: "<<courseName<<endl;
            teacher->DisplayDetail();
        }
};

int main(){
    Department dep("AI");
    Teacher Talha("Talha",25,"Nazimabad","8/L",&dep);

    Student s("Ali",18,"orangi","karachi");
    Course course("MVC",&Talha);

    s.DisplayDetail();
    cout<<"\n";
    Talha.DisplayDetail();
    cout<<"\n";
    course.displayCourse();
}
