#include <iostream>
#include<string>
using namespace std;
class student {
private:
    string name;
    string id;
    string courses[5];
    int marks[5];


public:

    student(string name , string id,int marks[])
    {
        cin>>name;
         this->name=name;
        cin>>id;
        this->id=id;
    for(int i=0;i<5;i++)
    {
        cout<<"enter the marks";
        cin>>marks[i];
          this->marks[i]=marks[i];
    }
    }
   
    void display()
    {
      cout<<"name "<<name<<endl;
    cout<<"  id "<<id <<endl;
    
    for(int i=0;i<5;i++)
     {
        cout<<marks[i]<<" ";
      }
    cout<<endl;
      cout<< "average marks"<<avgmarks(marks)<<endl;
    }
      int avgmarks(int marks[])
    {
        int t=0;
        for(int i=0;i<5;i++)
        {
            t=t+marks[i];
        }
        return t/5;
    }
    
   

};


int main() {
    int marks[5];
student s1("","" ,marks);
s1.display();


    return 0;
}
