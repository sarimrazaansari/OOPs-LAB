#include "iostream"
using namespace std;

class Student{
    string name;
    int rollNo;
    double *marks;

    static int totalStudent;
    static double totalMarks;

    public:
    Student(string n,int r,double *arr){
        name=n;
        rollNo=r;
        int sum=0;
        marks=new double[3];
        for (int i = 0; i < 3; i++)
        {
            marks[i]=arr[i];
            sum+=arr[i];
        }

        totalMarks+=sum;
        totalStudent++;
        
    }

    Student(Student &obj){
        name=obj.name;
        rollNo=obj.rollNo;

        marks=new double[3];

        int sum=0;
        for (int i = 0; i < 3; i++)
        {
            marks[i]=obj.marks[i];
            sum+=marks[i];
        }
        totalStudent++;
        totalMarks+=sum;
    }

    void setMarks(double *arr){
        for (int i = 0; i < 3; i++)
        {
            totalMarks-=marks[i];
        }

        for (int i = 0; i < 3; i++)
        {
            marks[i]=arr[i];
            totalMarks+=marks[i];
        }
    }

    void displayDetail(){
        cout<<"Name: "<<name<<" | Roll No: "<<rollNo<<" | Marks: ";
        for (int i = 0; i < 3; i++)
        {
            cout<<" "<<marks[i];
        }
        cout<<endl;
        
    }

    static void displayStatic(){
        cout<<"Total Students: "<<totalStudent<<endl;
        cout<<"Total Marks: "<<totalMarks<<endl;
    }

};

int Student::totalStudent=0;
double Student::totalMarks=0.0;

int main(){
    double sarim[3]={5,5,5};
    Student s1("Sarim",64,sarim);

    double ali[3]={4,4,4};
    Student s2("Ali",1,ali);

    s1.displayDetail();
    s1.displayStatic();
    s2.displayDetail();
    s2.displayStatic();

    double ahmed[3]={1,1,1};
    Student s3(s2);
    s3.setMarks(ahmed);
    s3.displayDetail();
    s3.displayStatic();


}