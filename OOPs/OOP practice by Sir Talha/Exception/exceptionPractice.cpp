#include "iostream"
using namespace std;

class InvalidAgeError{
    public:
        int age;
};

class AgeDetector{
    public:
        void add(int a){
            if (a<0){
                throw InvalidAgeError{a};
            }
            cout<<"age: "<<a<<endl;
        }
        

};

int main(){
    AgeDetector a;

    try{
        a.add(-1);
    }

    catch(InvalidAgeError &msg){
        cout<<"Error! Age"<<msg.age<<endl;
    }
}