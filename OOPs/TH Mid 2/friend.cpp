#include "iostream"
using namespace std;

// It's NOT a member of the class — it's an outsider with special access
// It's declared inside the class but defined outside
// Not inherited — friendship is not passed down to derived classes
// Not mutual — if A is a friend of B, B is NOT automatically a friend of A

class Area{
    int l,b;
    
    public:
    Area(int l, int b):l(l),b(b){}

    friend double calcArea(Area a);
    friend void show(Area a);
};

double calcArea(Area a){
    return a.l*a.b;
};

void show(Area a){
    cout<<"L: "<<a.l<<endl;
    cout<<"B: "<<a.b<<endl;
};

int main(){
    Area rectangle(2,3);
    cout<<"Area: "<<calcArea(rectangle)<<endl;
    show(rectangle);
}
