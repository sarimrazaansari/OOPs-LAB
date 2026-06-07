#include "iostream"
using namespace std;

class Server{
    public:
        void ConnectServer(int outcome){
            if(outcome==1) throw 404;
            if(outcome==2) throw "runtime";
            if(outcome==3) throw 3.14;
        }
};

int main(){
    Server s;

    try{
        s.ConnectServer(3);

    }

    catch(int msg){
        cout<<"Error: "<<msg<<endl;
    }
    catch(const char* msg){
        cout<<"Error: "<<msg<<endl;
    }

    catch(...){
        cout<<"Invalid Error "<<endl;
    }
}