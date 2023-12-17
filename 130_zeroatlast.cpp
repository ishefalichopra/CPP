#include<bits/stdc++.h>
using namespace std;
/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the input array 'A'.
*/

vector<int> moveZeros(int n, vector<int> a) {
    int j = 0;
    // Move all the nonzero elements advance.
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            a[j++] = a[i];
        }
    }

    // Setting up the rest elements as a zero.
    for (; j < a.size(); j++) {
        a[j] = 0;
    }

    return a;
}

int main()
{int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
vector<int> ans = moveZeros(n, arr);
for(int i = 0; i < n; i++)
cout << ans[i] << " ";

return 0;
}