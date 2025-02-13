#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0, maxLength=0;
        unordered_map<int,int>hash;
        
        for(int i=0;i<n;i++){
            
            sum += arr[i];
            if(sum == 0){
                maxLength = i+1;
            }
            
             if (hash.find(sum) != hash.end()) {
            maxLength = max(maxLength, i - hash[sum]);
            }else{
                hash[sum] = i;
            } 
        }
        return maxLength;
    }

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxLen(arr)<<endl;

return 0;
}