#include "iostream"
#include "fstream"
using namespace std;

int main(){

    fstream myfile("sorry.txt",ios::out);

    for (int i = 0; i < 100; i++)
    {
        myfile<<"sorry"<<endl;
    }
    
    myfile.clear();
}