#include "iostream"
using namespace std;

class Area{
    protected:
    double x,y;
    double area;
    public:
    Area(double x,double y):x(x),y(y){}

    virtual void calculate(){
        area=0;
    }
    virtual void show(){
        cout<<"Area is: "<<area<<endl;
    }
};

class Rectangle:public Area{
    public:
    Rectangle(double x,double y):Area(x,y){}

    void calculate(){
        area=x*y;
    }     
    void show(){
        cout<<"Area of Rectangle is: "<<area<<endl;
    }
};

class Triangle:public Area{
    public:
    Triangle(int x,int y):Area(x,y){}

    void calculate(){
        area=0.5*x*y;
    };
    void show(){
        cout<<"Area of Triangle is "<<area<<endl;
    }
};

int main(){
    Area *a1=new Rectangle(2,2);

    a1->calculate();
    a1->show();

    Area *a2=new Triangle(2,3);
    a2->calculate();
    a2->show();
}