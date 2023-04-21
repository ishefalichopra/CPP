#include<iostream>
using namespace std;
void updateVar( int *a);
int main()
{int a;
 cin>>a;
 updateVar(&a);
 cout<<a<<"\n";

return 0;
}
void updateVar(int *a)
{
      // write your code here
      *a+=10;
}