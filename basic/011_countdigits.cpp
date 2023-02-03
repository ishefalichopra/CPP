#include<iostream>
using namespace std;
class solution{
    public:
int evenlydivides(int n)
{
int x=n;
int r;
int count = 0;
while(x!=0)
{
    r = x%10;
    if(r==0){
        x=x/10;
        continue;
    }
    if(x%r==0){
    count += 1;
    x=x/10;
    }
    }
    return count;
}
};
int main()
{
int n;
cin>>n;
solution obj;
cout<<obj.evenlydivides(n);
return 0;
}