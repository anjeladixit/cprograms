#include<iostream>
#include<string.h>
using namespace std;
class library{
private:
   int id;
   string name;
  static int c;
  int userid;
 string bookname;

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

  cout<<"enter your id";
  cin>>userid;
  cout<<"enter the name of book you want"<<endl;
  cin>>bookname;
  if(bookname==name)
  {
    c--;
    cout<<"book isssued successfully by user id "<<userid<<endl;
  }
  else
  {
    cout<<" no such book found"<<endl;
  }
}


int main()
{
    library b1;
   
    library b2;  
    library b3;
    b2.issue();
    b2.count();
  //  int bid;
  //   library b1;
  //   library b2;
  //   library b3;
  //   cout<<"book anme";
  //   cin>>bid;
  //   for(int i=1;i<4;i++)
  //   {
  //     if(bid==library b[i].id)
  //     {  
  //        cout<<"yes";
  //     }
  //   }
}
