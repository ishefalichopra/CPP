#include<bits/stdc++.h>
using namespace std;
/*
    Time Complexity: O((N + M) * log(N + M))
    Space Complexity: O(N + M)

    N and M are the sizes of array 'a' and 'b' respectively.
*/
#include <set>
vector < int > sortedArray(vector < int > a, vector < int > b) {

    int n = a.size(), m = b.size();
    // Using a min-heap to 
    // store all distinct elements
    set < int > st;

    // Iterating over 'a'
    for (int i = 0; i < n; ++i) {
        st.insert(a[i]);
    }

    // Iterating over 'b'
    for (int i = 0; i < m; ++i) {
        st.insert(b[i]);
    }

    vector < int > unionArray;

    // Copying all elements 
    // from the set to the vector
    for (const int & value: st) {
        unionArray.push_back(value);
    }

    return unionArray;
}
int main()
{
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
int m;
cin >> m;
vector<int> brr(m);
for(int i = 0; i < m; i++)
cin >> brr[i];
vector<int> ans = sortedArray(arr, brr);
for(int i = 0; i < ans.size(); i++)
cout << ans[i] << " ";

return 0;
}