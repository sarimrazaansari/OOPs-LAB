#include "iostream"
using namespace std;

class Author{
    string name;
    int id;

    public:
    Author(string n, int id):name(n),id(id){}

    void display(){
        cout<<"ID: "<<id<<" | Name: "<<name<<endl;
    }
};

class Book{
    string title;
    Author *author[3];
    int count=0;
    public:
    Book(string title):title(title){}

    void addAuthor(Author *obj){
        author[count++]=obj;
    }
    void display(){
        cout<<"Title "<<title<<endl;
        for (int i = 0; i < count; i++)
        {
            cout<<i+1;author[i]->display();
        }
        
    }

};

int main(){
    Author sarim("Sarim",1);
    Author ali("Ali",2);

    Book b("OP");
    b.addAuthor(&sarim);
    b.addAuthor(&ali);
    b.display();
    
}