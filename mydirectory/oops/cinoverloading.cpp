#include<iostream>
#include<string>
using namespace std;
class person{
     private:
       string name;
       int age;
    public:
      person()
      {
          name="no name";
          age=0;
      }
      friend ostream &operator<<(ostream &output,person & p);
      friend istream &operator>>(istream &input,person &p);
};
ostream &operator<<(ostream &output,person & p)
{
    output<<"cout is overloaded"<<endl;
    output<<"the name entered is : "<<p.name<<" age is "<<p.age<<endl;
    return output;

}
istream &operator>>(istream &input,person & p)
{  
    input>>p.name>>p.age ;
    return input;
}
int main(){
     cout<<"the program starts"<<endl;
     person p;
     cin>> p;
     cout<< p;
     
}