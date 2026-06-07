#include "iostream"
using namespace std;

class Fighter{
    double shield;

    public:
        Fighter(double s):shield(s){}
        double getShield(){
            return shield;
        }
};

class Mothership{
    public:
        bool checkFleet(Fighter *arr,int size){
            if(size<0) return false;
            
                for (int i = 0; i < size; i++)
                {
                    if (arr[i].getShield()<20.0)
                    {
                        return false;
                    }
                }
            return 1;
            
        }
};

int main(){
    Fighter arr[3]={Fighter(50), Fighter(80),Fighter(25)};

    Mothership m;
    cout<<"Check: "<< (m.checkFleet(arr,3)? "Yes":"No")<<endl;
}