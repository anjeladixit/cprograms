#include<iostream>
using namespace std;
class car{
   int launch;
    string name;
    string modelno;
     public:
    void displayname()
     {  
        cout<<"enter car  name"<<endl;
        getline(cin,name);
         cout<<"enter car  launch "<<endl;
         cin>>launch;
         cout<<"enter model name"<<endl;
        getline(cin,modelno);
        cout<<"model name is "<<modelno<<"name is"<<name<<"launch is"<<launch<<endl;
     }
  
};
int main()
{
    car c1 ,c2;
    c1.displayname();
    c2.displayname();

}