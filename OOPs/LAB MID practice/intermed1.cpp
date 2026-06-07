#include "iostream"
using namespace std;

class HeartMonitor{
    public:
    int heartRate;
    HeartMonitor(){heartRate=0;}
    HeartMonitor(int hR):heartRate(hR){};

};

class BPMonitor{
    public:
    int systolic;
    int diastolic;

    BPMonitor(){systolic=diastolic=0;}
    BPMonitor(int s,int d):systolic(s),diastolic(d){};

};

class OxygenSensor{
    public:
    int oxygenLevel;
    OxygenSensor(){oxygenLevel=0;}
    OxygenSensor(int o):oxygenLevel(o){}
};

class Pateint{
    string name;
    int patientID;
    HeartMonitor hR[2];
    BPMonitor BP[2];
    OxygenSensor Oxygen[3];

    int HeartCount=0;
    int BPcout=0;
    int oxygenCount=0;

    public:
    Pateint(string n, int id){
        name=n;
        patientID=id;
    }

    void addHeartRate(int h){
        if (HeartCount<=2)
        {
            hR[HeartCount++]=h;
        }
        else cout<<"Error max done! "<<endl;
        
    }

    void addBPMonitor(int b){
        if (BPcout<=2)
        {
            BP[BPcout++]=b;
        }
        else cout<<"Error max done! "<<endl;
        
    }

    void addOxygenSensor(int o){
        if (oxygenCount<=2)
        {
            Oxygen[oxygenCount++]=o;
        }
        else cout<<"Error max done! "<<endl;
        
    }

    void DisplayDetail(){
        cout<<"Name: "<<name<<" | Pateint ID: "<<patientID<<endl;

        for (int i = 0; i <= HeartCount; i++)
        {
            cout<<"Heart Rate: "<<hR[i].heartRate;
        }
        for (int i = 0; i <= BPcout; i++)
        {
            cout<<"Heart Rate: "<<hR[i].heartRate;
        }
        
    }
};