#include "iostream"
#include "fstream"
using namespace std;

int main(){
    //write
    fstream file("file.txt",ios::out|ios::in);

    int currentPointer=file.tellg();
    cout<<"Current Pointer/Cursor: "<<currentPointer<<endl;

    file << "This is my first File"<<endl;
    file.close();


    file.open("file.txt");

    cout<<"Moving Pointer Forward: "<<endl;
    file.seekg(8,ios::beg); //now pointer is at after *this is*

    cout<<"Reading after Moving pointer: "<<endl;

    string line;

    while (getline(file,line))
    {
        cout<<line<<endl;
    }
    
    file.clear();

    //moving pointer 12 byte
    file.seekp(11,ios::beg);
    file<<"second";

    file.clear();
    file.seekp(0);
    
    while (getline(file,line))
    {
        cout<<line<<endl;
    }
    
}