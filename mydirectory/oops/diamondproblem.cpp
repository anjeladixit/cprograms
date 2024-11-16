#include<iostream>
using namespace std;
class a{
    public:
     void func1()
      {
        cout<<"this is function 1"<<endl;
      }
};
class b: public virtual  a{
    public:
     void  func2()
      {
        cout<<"this is function 2"<<endl;
      }
};
class c: public virtual  a{
    public:
     void  func3()
      {
        cout<<"this is function 3"<<endl;
      }
};
class d: public b,public c{
    public:
     void  func4()
      {
        cout<<"this is function 4"<<endl;
      }

};
int main()
{
    d d1;
    b b1;
    b1.func1();
   d1.func2();
   d1.func3();
   d1.func4();
   d1.func1();
}
