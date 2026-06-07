#include "iostream"
using namespace std;

int main(){
    int x,y;
    double div;
    cin>>x>>y;

    try
    {
        if (y==0)
        {
            throw "Div by 0 error";
        }
        div=x/y;
        
    }
    catch(const char* e)
    {
        cout<< e << '\n';
    }
    
    
    


}