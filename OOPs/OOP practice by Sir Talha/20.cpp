#include "iostream"
using namespace std;

class Node{
    public:
        virtual double getCPU()=0;
};

class DatabaseNode: public Node{
    public:
        double getCPU() override{ return 85.5;}
};

template <typename T>
class Storage{
    T items[5];
    int count=0;

    public:
        void add(T item){
            if (count<5){
                items[count++]=item;
            }
            else cout<<"storage full..."<<endl;
        }

        int getCount(){ return count;}
};

int main(){

    Storage<Node*> cloudStorage;

    Node *d1 =new DatabaseNode ;
    Node *d2 =new DatabaseNode ;

    cloudStorage.add(d1);
    cloudStorage.add(d2);

    cout<<"count: "<<cloudStorage.getCount();

    delete d1; delete d2;
}