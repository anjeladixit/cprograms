#include<iostream>
using namespace std;
class sample2;
class sample1{
   int a;
   friend void print (sample1,sample2);
};
class sample2{
   int b;
   friend void print (sample1,sample2);
};

void print (sample1 s,sample2 s2)
{
    s.a=10;
    s2.b=20;
    if(s.a>s2.b)
    {
        cout<<"a is greater";

    }
    else
    {
        cout<<"b is greater";
        
    }
   
    
}
int main()
{
    sample1 s;
    sample2 s2;

    print(s,s2);

}