#include<iostream>
#include<string.h>
using namespace std;
class library{
private:
   int id;
   string name;
  static int c;
public:
   library()
   {
    
     cout<<"book id";
     cin>>id;
     
     cout<<"name";
     cin>>name;
     c++;
   }
   void count();
   ~library()
   {
    // c--;
    // cout<<"now total count of books is"<<c;
  

   }
   void issue();

   
};
int library :: c;

void library::count()
{
    cout<<"number of books :"<<c<<endl;
}
void library::issue()
{
  c--;
  cout<<"book issued id id is "<<id<<endl;
}


int main()
{
    library b1;
   
    library b2;  
    library b3;

 //   b2.count();
    b2.issue();
    b2.count();
}
