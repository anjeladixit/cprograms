#include<iostream>
using namespace std;
class parent{
    public:
     string s1;
     void display()
     {
        cout<<"enter ur name"<<endl;
        getline(cin,s1);
        cout<<s1<<endl;
     }
};
class child : public parent{
    public:
      string s2;
       void display()
     {  parent :: display();
        cout<<"enter ur  sir name"<<endl;
        getline(cin,s2);
        cout<<s2<<endl;
     }
};
int main()
{
   child c1;
   c1.display();
}