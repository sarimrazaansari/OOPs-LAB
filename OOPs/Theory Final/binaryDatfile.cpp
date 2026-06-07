#include "iostream"
#include "fstream"
#include "cstring" //alternate of <string.h>
using namespace std;

class UniStudent{
    public:
        char name[20];
        int id;
        double gpa;

        UniStudent(const char* n="",int i=0,double g=0.0):id(i),gpa(g){
            strcpy(name,n);
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"id: "<<id<<endl;
            cout<<"gpa: "<<gpa<<endl;

        }
};

int main(){
    UniStudent s1("sarim",1,3.89);

    ofstream fileg("UniStudent.dat",ios::binary);

    if (!fileg)
    {
        cout<<"ERror in opneing!..."<<endl;
    }

    fileg.write((char*)&s1,sizeof(s1));
    fileg.close();
    cout<<"Saved..."<<endl;

    ifstream filep("UniStudent.dat",ios::binary);
    UniStudent temp;
    filep.read((char*)&temp,sizeof(temp));
    filep.close();

    temp.display();

}
