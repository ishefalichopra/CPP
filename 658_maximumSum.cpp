#include<bits/stdc++.h>
using namespace std;

long maximumSum(vector<long> a, long m){
    int n = a.size();
    long ans = 0, prefix = 0;
    set<long> s;

    for(int i = 0; i < n; i++){
        prefix = (prefix + a[i]) % m;
        ans = max(ans, prefix);
        auto it = s.lower_bound(prefix);
        if(it != s.end()){
            ans = max(ans, (prefix - *it + m) % m);
        }
        s.insert(prefix);
    }
    return ans;
}

int main()
{
    vector<long> a = {3, 3, 9, 9, 5};
    long m = 7;

    long result = maximumSum(a, m);
    cout << "Maximum sum modulo " << m << " is: " << result << endl;

return 0;
}