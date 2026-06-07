#include "iostream"
using namespace std;

class GrandParent{
    public:
    int x;
    GrandParent(){x=10;}
};
class Parent1:virtual public GrandParent{
};

class Parent2:virtual public GrandParent{
};

class Child:public Parent1,public Parent2{
};

int main(){
    Child d;
    cout<<d.x<<endl;
}
