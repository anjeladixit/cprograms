#include <iostream>

using namespace std;

class student {
    int stdid;
    char name[100];
    string courses[6];
    int marks[6];
    int cg;

    public:
    void getdata();
    void cumulativegrade();
    void putdata();
    
};
void student::getdata()
{
    cout<<"enter std id"<<endl;
    cin>>stdid;
    cout<<"enter name :";
    cin>>name;
    for(int i=0;i<5;i++)
    {
        cout<<"enter the courses";
        cin>>courses[i];
    }
    for(int i=0;i<5;i++)
    {
        cout<<"enter the marks";
        cin>>marks[i];
    }
}
void student::cumulativegrade()
{
   int t=0;
   for(int i=0;i<5;i++)
   {
      t+=marks[i];
   }
   cg=t/50;
}
void student :: putdata()
{
    cout<<stdid<<" ";
    cout<<name<<endl;
    for(int i=0;i<5;i++)
   {
     cout <<courses[i]<<" : "<<marks[i]<<"  "<<endl;

   } 
   cout<<"cg is "<<cg<<endl;
}

int main() {
    student s[70];
    for(int i=0;i<70;i++)
   { s[i].getdata();
    s[i].cumulativegrade();
    s[i].putdata();
   }
    return 0;
}
