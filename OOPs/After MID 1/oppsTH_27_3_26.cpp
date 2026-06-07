#include  "iostream"
using namespace std;

class Rupee{
    private:
    int data;

    public:
    Rupee(int data):data(data){}

    // unary binary operatot
    Rupee operator-(){
        return Rupee(-data);
    }

    //addition operator
    Rupee operator+(Rupee &obj){
        return Rupee(data + obj.data);
    }
    
    //substraction operaor
    Rupee operator-(Rupee &obj){
        return Rupee(data - obj.data);
    }

    //overloading addition assignment operator
    operator+=(Rupee& obj){
        data += obj.data;
    }
};