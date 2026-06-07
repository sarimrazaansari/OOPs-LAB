#include "iostream"
using namespace std;

/*
//single inheritance
//Parent->Child

class Parent{
    int x;

    public:
    Parent(int x):x(x){}

    void showP(){
        cout<<"x: "<<x<<endl;
    }

};

class Child:public Parent{
    int y;

    public:
    Child(int x, int y):Parent(x),y(y){}

    void showC(){
        showP();
        cout<<"y: "<<y<<endl;
    }


};

int main(){
    Child c(1,2);
    c.showC();
}
*/

//Multilevel:
//Grand Parent->Parent->Child

/*
class GrandParent{
    int x;

    public:
    GrandParent(int x):x(x){}

    void showG(){
        cout<<"x: "<<x<<endl;
    }
};

class Parent: public GrandParent{
    int y;

    public:
    Parent(int x,int y):GrandParent(x),y(y){}

    void showP(){
        showG();
        cout<<"y: "<<y<<endl;
    }
};

class Child: public Parent{
    int z;

    public:
    Child(int x, int y, int z):Parent(x,y),z(z){}

    void ShowC(){
        showP();
        cout<<"z: "<<z<<endl;
    }
};

int main(){
    Child c(1,2,3);
    c.ShowC();
}
*/

/*
//Multiple:
//Parent 1, parent 2 (Multiple Parent)->Child
class Parent1{
    int x;

    public:
    Parent1(int x):x(x){}
    void showP1(){
        cout<<"x: "<<x<<endl;
    }
};

class Parent2{
    int y;

    public:
    Parent2(int y):y(y){}

    void showP2(){
        cout<<"y: "<<y<<endl;
    }
};

class child:public Parent1,public Parent2{
    int z;

    public:
    child(int x,  int y, int z):Parent1(x),Parent2(y),z(z){}

    void showC(){
        showP1();
        showP2();
        cout<<"z: "<<z<<endl;
    }
};

int main(){
    child c(1,2,3);
    c.showC();
}
*/

