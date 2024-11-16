#include<iostream>
using namespace std;

class account {
    int number;
    string name;
     public:
  void getaccount()
  {cout<<"name  is"<<endl;
    cin>>name;
    // this->name=name;
    cout<<"account number is"<<endl;
    cin>>number;
    // this->id=id;

  }
  void showinfo()
  {
    cout <<"name entered is "<<name<<" account number  is "<<number<<" entered "<<endl;
  }


};
class saving : public account{
    int balance;
    public:
    void getbalance()
    {
        cin>>balance;
        if(balance<500)
        cout<<"balance should be min of 500";
        else 
          cout<<"account is created ";
    }

};


class current  : public account{
    int balance;
    public:
    void getbalance()
    {
        cin>>balance;
        if(balance<1000)
        cout<<"balance should be min of 1000";
        else 
          cout<<"account is created ";
    }

};

int main()
{
    int op;
    cout<<"enter 1 for saving n 2 for cureent"<<endl;
    cout<<"enter option";
    cin>>op;
    if(op==1)
    {
        saving a1;
        a1.getaccount();
        a1.showinfo();
        a1.getbalance();
    }
    else if(op==2)
    {
        current a2;
        a2.getaccount();
        a2.showinfo();
        a2.getbalance();
    }

}


















// class student{
//   private:
//      string name;
//      int id;
//  public:
//   void getstudent()
//   {cout<<"name is"<<endl;
//     cin>>name;
//     // this->name=name;
//     cout<<"id is"<<endl;
//     cin>>id;
//     // this->id=id;

//   }
//   void showinfo()
//   {
//     cout <<"name entered is "<<name<<" id is "<<id<<" entered "<<endl;
//   }


// };
// class marks : public student{
//     public:
//     int m1;
//     int m2;
//     int m3;
    
//       void getmarks()
//       {
//         cout<<"enter first marks"<<endl;
//         cin>>m1;
//         cout<<"enter second marks"<<endl;
//         cin>>m2;
//         cout<<"enter third marks"<<endl;
//         cin>>m3;

//       }
//       void showmarks()
//       {
//         cout <<" the three marks are "<<m1<<" "<<m2<< " "<<m3<<endl;
//       }

// };
// class result: public marks{
//      float avg;
//     float total;
//      public:
     
//         void show()
//         {
//           avg=m1+m2+m3;
//           total=avg/3;
//           cout<<" the total is "<<total<<endl;
      
//         }
     

// };
// int main()

// {
//     result  s1;
//     s1.getstudent();
//     s1.showinfo();
//     s1.getmarks();
//     s1.showmarks();
//     s1.show();


// }