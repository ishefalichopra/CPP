#include<bits/stdc++.h>
using namespace std; 
#include<math.h>
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n= a.size();
    long long S=0;
    long long Sn= (n*(n+1))/2;
    long long S2= 0;
    long long S2n= (n*(n+1)*((2*n)+1))/6;
    for(int i=0;i<n;i++){
        S += a[i];
        S2 += (long long)a[i]*(long long)a[i];
    } 
    long long one=  S-Sn;
    long long two = S2-S2n;
    two = two/one;
    long long x= (two+one)/2;
    long long y= two -x;
    return {(int)x,(int)y};

}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans= findMissingRepeatingNumbers(a);
    cout<<ans[0]<<" "<<ans[1]<<endl;

return 0;
}