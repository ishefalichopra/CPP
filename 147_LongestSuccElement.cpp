#include<bits/stdc++.h>
using namespace std;
int longestSuccessiveElements(vector<int> &a) {
  // Write your code here.

  int n = a.size();
  int maxLen = 0;
  sort(a.begin(), a.end());
   int currentLen=1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] + 1) {
      // The current element is successive, increment the current length
      currentLen++;
    } else if (a[i] != a[i - 1]) {
      // The current element is not successive, reset the current length
      currentLen = 1;
    }
    // Update the maximum length encountered so far
    maxLen = max(maxLen, currentLen);
  }
  return maxLen;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
   int ans = longestSuccessiveElements(a);
    cout << ans << endl;

return 0;
}