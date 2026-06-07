#include "iostream"
#include "fstream"
using namespace std;

int main(){

    int no,table;
    
    cout<<"Enter no.: ";
    cin>>no;
    
    fstream myfile("table.txt",ios::app | ios::out);
    myfile<<"The table of "<<no<<" :"<<endl;
    for (int i = 1; i < 11; i++)
    {
        myfile<<no<<" x "<<i<<" = "<<no*i<<endl;
    }

    myfile.close();

    //read

    string read;

    myfile.open("table.txt",ios::in);

    cout<<"=========FILE CONTENT========="<<endl;

    while (getline(myfile,read))
    {
        cout<<read<<endl;
    }

}