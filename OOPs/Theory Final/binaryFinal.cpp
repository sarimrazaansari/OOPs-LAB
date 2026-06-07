#include "iostream"
#include "fstream"
#include <string>
#include "cstring"
using namespace std;

class Student{
    public:
    char name[20];
    int rollno;
    double eng,urdu,math;

    public:
    Student(string n="",int r=0,double eng=0,double u=0,double m=0):rollno(r),eng(eng),urdu(u),math(m){
        strcpy_s(name,n.c_str());
    }

    double getTotal(){
        return eng+urdu+math;
    }
    double getPerc(){
        return getTotal()/300*100;
    }
    void display(){

        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Eng: "<<eng<<endl;
        cout<<"urdu: "<<urdu<<endl;
        cout<<"Math: "<<math<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Total: "<<getTotal()<<endl;
        cout<<"Percentage: "<<getPerc()<<endl;
        cout<<"--------------------------------"<<endl;

    }

};

//save file using binary file

void saveFile(string fileName, Student obj){
    ofstream file(fileName,ios::binary|ios::app);

    if (!file)
    {
        cout<<"File is not open!.."<<endl;
    }
    
    file.write((char*) &obj,sizeof(obj));  //main code

    file.close(); 
    cout<<"Object saved! "<<endl;
}

void showFile(string fileName){
    Student temp;
    ifstream file(fileName,ios::binary);
    if (!file){
        cout<<"Error in opening... "<<endl;
    }
    // file.read((char*) &temp,sizeof(temp)); //this will save file to temp object
    // temp.display();

    //or

    while (file.read((char*) &temp,sizeof(temp))){
        temp.display();
    }
    
    
    file.close();
}

void search(string fileName, int roll){
    ifstream file(fileName,ios::binary);

    if (!file){
        cout<<"File Not Found...."<<endl;
    }
    Student temp;
    while (file.read((char*)&temp,sizeof(temp)))
    {
        if (temp.rollno==roll){
            file.close();
            cout<<"File Found...."<<endl;
            temp.display();
        }
        
    }
    
    
}

void updateName(string fileName, int RollNo, string newName){
    fstream file(fileName,ios::out|ios::in|ios::binary);

    Student temp;

    while (file.read((char*)&temp,sizeof(temp))){
        if (temp.rollno == RollNo){
            strcpy_s(temp.name, sizeof(temp.name), newName.c_str()); //it will update program, not on file

            int currentPosition=file.tellg(); //it will get end postion of searched object but we need to go fisrt of
                                              //that object
            int oneBlock=sizeof(temp);

            file.seekg(currentPosition-oneBlock);

            file.write((char*)&temp,sizeof(temp));
            file.close();
            cout<<"file Updated!..."<<endl;
        }
        
    }
    

}

int main(){
    // Student s1("Ahemed",2,99,13,80);
    // s1.display();

    // saveFile("Student.bin",s1);
    // showFile("Student.bin");

    // search("Student.bin",2);

    showFile("Student.bin");

    cout<<"------------------------------------"<<endl;

    updateName("Student.bin",2,"Ali");

    cout<<"------------------------------------"<<endl;

    showFile("Student.bin");

}