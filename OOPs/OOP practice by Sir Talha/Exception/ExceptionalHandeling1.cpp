#include "iostream"
using namespace std;

class SecuritySys{
    public:
        void authenticaton(string pass){
            if (pass.length()<8)
            {
                throw "Pass is too short";
            }
            else cout<<"Authentication Successful"<<endl;
        }
};

int main(){
    SecuritySys c;

    try{
        c.authenticaton("134dawdasdawd");
        c.authenticaton("134");
    }

    catch(const char* msg){
        cout<<msg<<endl;
    }
    

}

