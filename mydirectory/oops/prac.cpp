#include <iostream>

using namespace std;
class teacher
{
  public: 
   string name;
   double *cgpaptr;

   teacher(string name,double cgpa)
   {
     this->name=name;
     cgpaptr =new double;
     *cgpaptr=cgpa;
   }
   teacher(teacher &obj)
   {
     this->name=obj.name;
     cgpaptr=new double;
     *cgpaptr=*obj.cgpaptr;
   }
   void info()
   {
     cout<<"name : "<<name<<endl;
     cout<<" cgpa : "<<*cgpaptr<<endl;
   }
};

   
int main()
{
  teacher t1("rahil",9.8);
  t1.info();
  teacher t2(t1);
  t2.info();
  *(t2.cgpaptr)=9;
  t2.name="meena";
  t2.info();
  t1.info();








}

