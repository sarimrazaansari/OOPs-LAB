#include "iostream"
using namespace std;

class MediaFire{
    protected:
        string filepath;

    public:
        MediaFire(string f):filepath(f){}
};

class Audiotrack:virtual public MediaFire{
    public:
        Audiotrack(string f):MediaFire(f){}
        void play(){
            cout<<"Audio is playing..."<<endl;
        }
};

class Videotrack:virtual public MediaFire{
    public:
        Videotrack(string f):MediaFire(f){}
        void play(){
            cout<<"Video is playing..."<<endl;
        }
};

class Movie:public Audiotrack,public Videotrack{
    public:
        Movie(string f):MediaFire(f),Audiotrack(f),Videotrack(f){}
        void play(){
            Audiotrack::play();
            Videotrack::play();
            cout<<"Movie is playing..."<<endl;
            cout<<filepath;
        }
};

int main(){
    Movie m("OP");
    m.play();
}

