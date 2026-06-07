#include "iostream"
using namespace std;
# define max 100
class book{
    private:
    string title;
    string isbn;

    static int totalBookCount;


    public:
    book(string b, string i):title(b), isbn(i){
        totalBookCount++;
    }

    void displayInfoBook(){
        cout<< "[BOOK] :"<<title<<" (ISBN : "<<isbn<<")"<<endl; 
    }

    static int getTotalBookCount(){
        return totalBookCount;
    }

    ~book(){
        totalBookCount--;
        cout<<"Destructor of book is called "<<title<<endl;
    }
};

int book::totalBookCount=0;

class member{
    string name;
    int memID;

    public:
    member(string n, int id):name (n),memID(id){};

    string getName(){return name;};

};

class library{
    string libraryName;


    //compostion
    book *books[max]; //declaring pointer to connect with book class
    int bookCount=0;
    //aggregation
    member *members[max]; //declaring pointer to connect with member class
    int memberCount=0;

    public:
    library(string b):libraryName(b){};

    void addBook(string name, string isbn){
        if (bookCount<max){
            //now we are creating book here for indivisual array members
            books[bookCount]=new book(name,isbn); //books is pointer it will take address instead of object and "new" will return address
            bookCount++;
        }
        else cout<<"Error storage is filled!"<<endl;
        
    }

    void registerMember(member *m){ //connents with member class, we will send data to library from here 
        if (memberCount<max){ 
            members[memberCount]=m; 
            memberCount++;
        }    
    }

    void displayDetail(){
        cout<<"========="<<libraryName<<"==========="<<endl;

        cout<<"---Book Catalog---"<<endl;
        for (int i = 0; i < bookCount; i++)
        {
            books[i]->displayInfoBook();
        }

        cout<<"---Member catalog---"<<endl;
        for (int i = 0; i < memberCount; i++)
        {
            cout<< members[i]->getName() <<endl;
        }
        
        //access static members
        cout<<"\n===System stats===\n";
        cout<<"Total book are :"<<book::getTotalBookCount()<<endl;
    }

    ~library(){
        cout<<"Library "<<libraryName<<" is closing..."<<endl;
        for (int i = 0; i < bookCount; i++)
        {
            delete books[i];
        }
        
    }
};

int main(){

    member Sarim("Sarim",01);
    member Ali("Ali",2);

    cout<<"Program Starts:"<<endl;

    {
        library Fast("Fast");

        Fast.addBook("One piece","101");
        Fast.addBook("Chainsaw Man","102");
        Fast.addBook("Bleach","103");

        Fast.registerMember(&Sarim);
        Fast.registerMember(&Ali);

        Fast.displayDetail();

        cout<<"Exiting scope...."<<endl;
    }

    cout<<"\n---Back in main---\n";
    cout <<"Does Sarim exist ???"<<endl;

    cout<<"Sarim Detail"<<Sarim.getName()<<endl;

    cout<<"Total book in system are "<<book::getTotalBookCount()<<endl;


}