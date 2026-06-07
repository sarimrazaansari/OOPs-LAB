#include "iostream"
using namespace std;

class Server{
    int ping;
    public:
        Server(int p):ping(p){}
        int getPing(){return ping;}
};

class NetworkManagement{
public:
    bool isNetworkStable(Server *nodes,int count){
        if(count<=0) return false;

        for (int i = 0; i < count; i++){
            if (nodes[i].getPing()<500) return false;
        }
        return true;
        
    }
};

int main(){
    Server arr[3]={Server(600),Server(500),Server(1500)};
    NetworkManagement n;
    cout<< (n.isNetworkStable(arr,3)? "Yes":"No")<<endl;
}