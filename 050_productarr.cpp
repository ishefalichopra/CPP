#include<iostream>
using namespace std;
class Solution{
    public:
    int product(int arr[], int n)
    {
        int ans=1;
        for(int i=0;i<n;i++){
            ans= ans * arr[i];
        }
        return ans;
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
cout<<ob.product(arr,n)<<endl;
return 0;
}