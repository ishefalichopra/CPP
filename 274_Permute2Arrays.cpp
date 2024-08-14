#include<bits/stdc++.h>
using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B) {
    int n= B.size();
    sort(A.begin(),A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0;i<A.size();i++){
        if(A[i]+B[i]>=k){
            continue;
        }
        else{
            return "NO";
        }
    }
     return "YES";
}

int main()
{
    vector<int> A = {2, 1, 3};
    vector<int> B = {7, 8, 9};
    cout<<twoArrays(10,A,B)<<endl;

return 0;
}
