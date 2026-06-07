#include "iostream"
using namespace std;
#include "fstream"
#include "string"

int main(){
    ofstream writefile("final.txt"); //write
    if (!writefile)
    {
        cout<<"Error in opening file "<<endl;
    }


    //write
    writefile<<"MY file";

    writefile.close();
    //read
    
    ifstream readfile("final.txt");

    string line;

    while(readfile >> line){
        cout<< line <<endl;
    }
    
    //cursor back to 0
    readfile.clear();
    readfile.seekg(0,ios::beg);

    while (getline(readfile,line))
    {
        cout<< line <<endl;
    }
    
    

    // cout<<line<<endl;

    readfile.close();
    
}