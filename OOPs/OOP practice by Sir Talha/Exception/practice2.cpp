#include "iostream"
#include "stdexcept"
using namespace std;

class Array{
    int arr[10];

    public:
        Array(int *a,int size){
            if (size<10){
                for (int i = 0; i < size; i++){
                    arr[i]=a[i];
                }
            }
            else throw out_of_range("Out of range");
        }
};

int main(){
    int arr[12]={1,1,1,1,1,1};

    try{
        Array a(arr,12);
    }

    catch(out_of_range& msg){
        cout<<"Error! "<<msg.what()<<endl;
    }


}