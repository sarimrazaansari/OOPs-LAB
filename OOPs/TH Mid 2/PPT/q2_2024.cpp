#include "iostream"
using namespace std;

class Employee{
    protected:
    int id;
    string name;
    double salary;

    public:
    Employee(int id,string name, double salary):id(id),name(name),salary(salary){}

};

class SecurityAnalyst:public Employee{
    string specialization;
    bool isCertificate;

    public:
    SecurityAnalyst(int id, string name,double salary,string specialization,bool isCertificate):Employee(id,name,salary),isCertificate(isCertificate){
        setSpecialization(specialization);
    }

    void setSpecialization(string s){
        if(s!="Network"||s!="Incident Response"||s!="Threat Intelligence"){
            cout<<"Choose correct";
            cin>>s;
            specialization=s;
        }
        else specialization=s;
    }

    void hasCertification(){
        int noOfCert;
        string certs;

        if (isCertificate)
        {
            cout<<"Enter No. Certificate: "<<endl;
            cin>>noOfCert;

            if (noOfCert==1)
            {
                cout<<"Enter Cerficate: ";
                cin>>certs;
                cout<<"Your Certificates: "<<certs<<endl;
            }
            else {
                string c[noOfCert];
                for (int i = 0; i < noOfCert; i++)
                {
                    cout<<"Enter Certificate: ";
                    cin>>c[i];
                }
                for (int i = 0; i < noOfCert; i++)
                {
                    cout<<c[i]<<endl;
                }
            }
        }
        else cout<<"Not Certified."<<endl;
        
    }
};

class SecurityEnginner:public Employee{
    bool isExpert;
    bool isAssigned;
    string *list; //list of Project

    public:
    SecurityEnginner(int id, string name,double salary,bool isExpert,bool isAssigned=false):Employee(id,name,salary),isExpert(isExpert),isAssigned(isAssigned){
        list=new string{"Project 1"};
    };

    bool AssignProject(){
        if (isExpert)
        {
            isAssigned=true;
            return isAssigned;
        }
        else{
            isAssigned=false;
            return isAssigned;
        }   
    }

    void addProject(){
        if (AssignProject())
        {
            int noOfProject;
            cout<<"Enter no. of projects: ";
            cin>>noOfProject;

            string *list1;
            list1=new string[noOfProject];

            for (int i = 0; i < noOfProject; i++)
            {
                cout<<"Enter Projects: ";
                cin>>list1[i];
            }
            for (int i = 0; i < noOfProject; i++)
            {
                cout<<list1[i]<<endl;
            }

        }
        else cout<<"No Project "<<endl;
        
    }
};

class Lead:public SecurityAnalyst,public SecurityEnginner{
    public:
    Lead(int id, string name,double salary,string specialization,bool isCertificate,bool isExpert,bool isAssigned):SecurityAnalyst(id,name,salary,specialization,isCertificate),SecurityEnginner(id,name,salary,isExpert,isAssigned){}

    void show(){
        hasCertification();
        AssignProject();
        addProject();
    }
};

int main(){
    Lead l(1,"Sarim",5000,"abc",true,true,true);
    l.show();
}