#include "iostream"
using namespace std;

class Employee{
    int kpi;

    public:
    Employee(int k):kpi(k){}

    int getKPI(){return kpi;}
};

template <typename T>
T topPerfomer(T a, T b){
    if (a.getKPI()<b.getKPI()) return b;
    else return a;
}

int main(){
    Employee e1(100),e2(200);
    Employee compare= topPerfomer(e1,e2);

    cout<<"compare: "<<compare.getKPI();
}