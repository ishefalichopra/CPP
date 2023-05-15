#include<iostream>
using namespace std;
class Solution {
  public:
    int mean(int n , int arr[]) {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        return sum/n;
    }
};
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
Solution ob;
cout<<ob.mean(n,arr)<<endl;
return 0;
}