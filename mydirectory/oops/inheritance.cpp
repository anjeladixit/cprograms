#include<iostream>
#include<string>
using namespace std;
class person{
public:
    string name;
    int age;

    person()
    {
        cout<<"parent..\n";
    }

};
class student : public person{
 public:
       int roll;
       student(){
        cout<<"student..\n";
       }

       void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"age "<<age<<endl;
        cout<<"roll no "<<roll<<endl;
       }
};
int main()
{
    student s1 ;
    s1.name="ram";
    s1.age= 22;
    s1.roll= 111;

    s1.getinfo();
    return 0;


}