#include<iostream>
#include<fstream>
using namespace std;
class student{
    char name[20];
    int id;
    public:
    void getinfo()
    {
       cout<<"enter the id and name ";
       cin>>id>>name;
    }
};
int main()
{
    student s1;
    ofstream file("student.txt");
    char op;
    do{
        s1.getinfo();
        file.write((char *)&s1,sizeof(s1));
        cout<<"do you want to add more :";
        cin>>op;
        }
        while(op=='y');
    file.close();
    
}