#include<bits/stdc++.h>
using namespace std;
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--)
        if(book[i]+book[j]==target){
            return "YES";
        }

    }
    return "NO";
}
int main()
{
int n;
cin>>n;
vector<int> book(n);
for(int i=0;i<n;i++)
cin>>book[i];
int target;
cin>>target;
cout<<read(n,book,target);

return 0;
}