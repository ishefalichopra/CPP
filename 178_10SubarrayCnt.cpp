#include<bits/stdc++.h>
using namespace std;

 long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long int count=0;
        unordered_map<int,int> m;
        int pre_sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            arr[i]=-1;
        }
        for(int i=0;i<n;i++){
            pre_sum+=arr[i];
            
            if(pre_sum==0)
            count++;
            m[pre_sum]++;
            
        }
        for(auto it:m){
            count+=(it.second)*(it.second-1)/2;
        }
        return count;
    }

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    std::cout << countSubarrWithEqualZeroAndOne(arr,n);

return 0;
}