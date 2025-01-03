#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
     for (int i = n; i >= 1; i--) {
        int cnt = 4;
        for(int j=i;j<=n;j++){
            cout<<cnt;
            cnt--;
        }
        for (int j = 1; j < 2*i-1; j++) {
            cout << i;
        }
        cnt = i+1;
        for(int j=i+1;j<=n;j++){
            cout<<cnt;
            cnt++;
        }
        cout << endl;
    }
    for (int i = 2; i <= n; i++) {
        int cnt = 4;
        for(int j=i;j<=n;j++){
            cout<<cnt;
            cnt--;
        }
        for (int j = 1; j < 2*i-1; j++) {
            cout << i;
        }
        cnt = i+1;
        for(int j=i+1;j<=n;j++){
            cout<<cnt;
            cnt++;
        }
        cout << endl;
    }
return 0;
}