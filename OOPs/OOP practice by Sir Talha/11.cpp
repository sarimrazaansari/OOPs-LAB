#include "iostream"
using namespace std;

template <typename T>
class InventoryBag{
    T items[10];
    int count=0;

    public:
        void storeItem(T item){
            if (count<10){
                items[count++]=item;
            }
        }

        T getCount(){return  count;}

        void show(){
            for (int i = 0; i < count; i++) 
            {
                cout<<i+1<<". "<<items[i]<<endl;
            }
        }
};

int main(){
    InventoryBag <double> b;
    b.storeItem(123.20);
    b.storeItem(25.12);
    cout<<"Count: "<<b.getCount()<<endl;
    b.show();
}   