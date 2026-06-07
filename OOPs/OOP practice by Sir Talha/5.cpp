#include "iostream"
using namespace std;

class Property{
    int sqft;
    
    public:
        Property(int s):sqft(s){}
        int getSquarefootage() {return sqft;}
};

template <typename T>
T findBetter(T var1, T var2){
    if (var1.getSquarefootage()>var2.getSquarefootage())
    {
        return var1;
    }
    else return var2;
}

int main(){
    Property p1(100),p2(200);

    Property best = findBetter(p1,p2);
    cout<<"Best: "<<best.getSquarefootage()<<endl;
}
