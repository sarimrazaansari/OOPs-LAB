#include "iostream"
using namespace std;

class EspressoMachine{
    int waterlevel;
    int coffeeBeansLevel;

    public:
        EspressoMachine(int wL,int cL):waterlevel(wL),coffeeBeansLevel(cL){};

        bool brew(int shots){
            if (shots*30<=waterlevel && shots*15<=coffeeBeansLevel)
            {
                waterlevel-=shots*30;
                coffeeBeansLevel-=shots*15;
                return true;
            }
            else return false;
        }

        void info(){
            cout<<"\nWater Level: "<<waterlevel<<endl; 
            cout<<"Coffee Level: "<<coffeeBeansLevel<<endl; 
        }
};

int main(){
    EspressoMachine c(31,16);

    cout<<c.brew(1)<<endl;
    c.info();

    EspressoMachine p(61,31);
    cout<<p.brew(2)<<endl;
    p.info();

    cout<<p.brew(3);
}