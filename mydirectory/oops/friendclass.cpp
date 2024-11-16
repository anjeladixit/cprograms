#include<iostream>
using namespace std;
class author{
   string name;
    public:
    friend class book;
    void getab(){
        cout<<"enter author name ";
        getline(cin,name);

    }
};
class book{
    int price;
    string bname;

    public:
    void getbook()
    {
        cout<<"enter book name";
        getline(cin,bname);
        cout<<"enter the price of the book";
        cin>>price;
    }
    
    void putauthor(author a1)
    {
        // cout<<"enter book name"<<endl;
        // cin>>bname;
        // cout<<"enter the price of the book"<<endl;
        // cin>>price;
   
       cout<<"book name is  "<<bname;
        cout<<" author name is "<<a1.name;
        cout<<" price  is "<<price;
        
    }

};
int main()
{
  author a1;
  book b1;
  a1.getab();
  b1.getbook();
  b1.putauthor(a1);
}