#include "iostream"
using namespace std;

template <typename T>
class ProcessQueue{
    T tasks[5];
    int count=0;

    public:
        void enqueue(T task){
            if(count<5){
                tasks[count++]=task;
            }
            else cout<<"Storage Full!"<<endl;
        }

        void show(){
            cout<<"Count: "<<count<<endl;
            for (int i = 0; i < count; i++)
            {
                cout<<i+1<<". "<<tasks[i]<<endl;
            }
            
        }
};

int main(){
    ProcessQueue <int> p;
    p.enqueue(1);
    p.enqueue(2);
    p.enqueue(3);
    p.enqueue(4);
    p.enqueue(5);
    p.enqueue(6);
    p.show();
}