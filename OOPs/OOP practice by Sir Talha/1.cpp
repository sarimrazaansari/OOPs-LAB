#include "iostream"
using namespace std;

class RoomHeater{
    double targetTemp=20.0;
    double maxLimit=30.0;

    public:
        bool increaseTemp(double degree){
            if (degree>0 && degree+targetTemp<=maxLimit)
            {
                targetTemp+=degree;
                return true;
            }
            return false;
        }

        double getTemp(){
            return targetTemp;
        }
};

int main(){
    RoomHeater r;
    cout<<"Temp inc: "<<r.increaseTemp(12)<<endl;
    cout<<"Target Temp: "<<r.getTemp()<<endl;

    RoomHeater r2;
    cout<<"Temp inc: "<<r2.increaseTemp(3)<<endl;
    cout<<"Target Temp: "<<r2.getTemp()<<endl;


}