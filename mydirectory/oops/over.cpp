#include<iostream>
using namespace std;
class complex{
 int real;
 int imag;
 public:
   complex()
   {  real=0;
   imag=0;
   }
   complex(int real,int imag)
   {
     this->real=real;
     this->imag=imag;
   }
   complex operator+(complex c);
   void display(){
  cout<<"("<<this->real<<","<<this->imag<<")";
   }
};
complex complex::operator+(complex c)
{
    complex temp;
    temp.real=this->real+c.real;
    temp.imag=this->imag+c.imag;
    return temp;
}
int main()
{
    complex c1(1,3);
    complex c2(7,3);
    complex c3;
    c3=c1+c2;
    c3.display();

}