#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    // char a[100];
    // cin.getline(a,100);
    // ofstream out("file1.txt");
    // out<<a;
    // cout<<" file created successfully"<<endl;
    // //  char c[100];
    // cout<<"'enter more text to be added' " ;
    // cin.getline(c,100);
    // ofstream out1("file1.txt",ios::app);
    // out1<<c;
    // cout <<"file updated"<<endl;
    // return 0;
   ifstream in ("file1.txt");
   char c[100];
   in.getline(c,100);
   cout<<c;


}