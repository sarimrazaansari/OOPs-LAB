#include "iostream"
using namespace std;

class OverheatError{
    public:
        int currentTemp;
};

class Engine{
    public:
        void run(int temp){
            if (temp>120)
            {
                throw OverheatError{temp};
            }
            cout<<"Engine run Successful, temp: "<<temp<<endl;
        }
};

int main(){
    Engine a;

    try{
        a.run(122);
    }

    catch(OverheatError &msg){
        cout<<"Error! Heat= "<<msg.currentTemp<<endl;
    }
}