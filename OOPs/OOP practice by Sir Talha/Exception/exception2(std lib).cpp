#include "iostream"
#include "stdexcept"
using namespace std;

class Sensor{
    public:
        void readData(double data){
            if (data<0){
                throw runtime_error("Negative msg");
            }
            else cout<<"Read msg successful"<<endl;
            
        }
};

int main(){
    Sensor s,p;
    try{
        s.readData(-5);
    }

    catch(runtime_error& msg){
        cout<<msg.what()<<endl;
    }
}