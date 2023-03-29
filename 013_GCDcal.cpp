#include<iostream>
using namespace std;
int gcdcal(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a==b){
        return a;
    }
    if(b>a){
        return gcdcal((b-a), a);
    }
    return gcdcal((a-b ), b);
}
int main()
{
int a,b;
cout<<"Enter a and b:"<<endl;
cin>>a>>b;
cout<<gcdcal(a,b);

return 0;
}