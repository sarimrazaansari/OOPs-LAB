#include "iostream"
#include "string"
#include "fstream"

using namespace std;


int main(){
    ofstream outfile("exapmle.txt");

    outfile<<"This is first line ";
    outfile.close();

    fstream file("exapmle.txt",ios::in|ios::out);
    
    cout<<"Current Get Pointer Index Before reading: "<<file.tellg()<<endl;

    cout<<"Moving get pointer forward ..."<<endl;
    file.seekg(7,ios::beg); //jump 7 char //g=read

    cout<<"Reading after get pointer....."<<endl;

    string line;
    getline(file,line);
    cout<<line<<endl;
    file.clear();
    
    cout<<"Moving put 13 bytes from the begining... "<<endl;
    file.seekp(12,ios::beg);
    file << "second";
    file.clear();

    cout<<"Reading the modified line...."<<endl;
    getline(file,line);
    cout<<line<<endl;
}