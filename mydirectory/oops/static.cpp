#include<iostream>
using namespace std;
class sample{
public:
static int count;
 sample()
 {
    count++;
    cout<<"constructed obj "<<count;
 }
 ~sample()
 {
    
    cout<<"destructed  obj "<<count;
    count--;
 }
};
int sample::count=0;
int main()
{
  sample s1,s2,s3;
  
}



















// class test{
//        public:
//    static int a;

//    void get()
//    {
//      cout<<"a="<<a<<endl;
//    }

// };
// int test::a=10;
// int main()

// {
//    test::a=100;
//    cout<<"a="<<test::a<<endl;
//    test t;
//    t.get();
   
// }