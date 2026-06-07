#include "iostream"
using namespace std;

class Shape{
    protected:
    string color;
    
    public:
    Shape(string c):color(c){};
    
    virtual double area()=0; //pure virtual
    virtual double perimeter()=0; //pure virtual
    //(OR)
    // virtual double area(){
    //     return 0;
    // }
    // virtual double perimeter(){
    //     return 0;
    // }

    virtual void show(){
        cout<<"Color: "<<color<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }

    virtual ~Shape(){};
};

class Circle:public Shape{
    protected:
    double radius;

    public:
    Circle(string s,double r):Shape(s),radius(r){};

    double area(){
        return 3.14*radius*radius;
    };

    double perimeter(){
        return 2*3.14*radius;
    }
};

class Rectangle:public Shape{
    protected:
    double l,b;

    public:
    Rectangle(string c,double l, double b):Shape(c),l(l),b(b){};

    double area(){
        return l*b;
    }
    double perimeter(){
        return l+b;
    }

};

int main(){
    Shape *s1=new Circle("Pink",2);
    s1->show();

    Shape *s2=new Rectangle("Yellow",3,4);
    s2->show();

    delete s1; delete s2;
}

