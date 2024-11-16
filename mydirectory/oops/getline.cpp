#include <iostream>
#include <fstream>
using namespace std;
int main()
{
int i;
ofstream out("CHARS1.txt", ios::out );
if(!out) {
cout << "Cannot open output file.\n";
return 1;
}
// write all characters to disk
for(i=0; i<256; i++) out.put(i);
out.close();
return 0;
}