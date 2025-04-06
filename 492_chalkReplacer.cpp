#include<bits/stdc++.h>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long long total = 0;

    for (int x : chalk) {
        total += x;
    }
    
    k %= total;

    for (int i = 0; i < chalk.size(); i++) {            
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
    return 0;
}

int main()
{
  int n, k;
    cin >> n;
    vector<int> chalk(n);
    for (int i = 0; i < n; i++) {
        cin >> chalk[i];
    }
    cin >> k;
    cout << chalkReplacer(chalk, k) << endl;
    
return 0;
}