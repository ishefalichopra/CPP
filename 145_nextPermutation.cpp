#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int ind=-1;
    int n= A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind =i;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>ind;i--){
      if(A[i]>A[ind]){
          swap(A[i],A[ind]);
          break;
      }
    }
    reverse(A.begin()+ind+1, A.end());
    return A;
}
int main()
{
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int>ans=nextGreaterPermutation(A);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

return 0;
}