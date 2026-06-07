#include "iostream"
using namespace std;

class Laptop{
    string brand;
    string model;
    double price;
    int ram;

    static int totalLaptop;
    static double totalPrice;

    public:
    Laptop(string b,string m,double p,int r):brand(b),model(m),price(p),ram(r){
        totalLaptop++;
        totalPrice+=price;
    }
    Laptop(Laptop &obj){
        brand=obj.brand;
        model=obj.model;
        price=obj.price;
        ram=obj.ram;

        totalLaptop++;
        totalPrice+=obj.price;
    }
        
    

    void displayDetails(){
        cout<<"Brand: "<<brand<<" | Model: "<<model<<" | price: "<<price<<" | RAM: "<<ram<<endl; 
    }
    static void displayShared(){
        cout<<"Total Laptop: "<<totalLaptop<<endl;
        cout<<"Total Price: "<<totalPrice<<endl;

    }


};

int Laptop::totalLaptop=0;
double Laptop::totalPrice=0.0;

int main(){
    Laptop l1("HP","102",5000,8);
    Laptop l2("DELL","109",1500,16);
    Laptop l3(l1);
    l1.displayDetails();
    l1.displayShared();
    l2.displayDetails();
    l2.displayShared();

    l3.displayDetails();
    l3.displayShared();

}

