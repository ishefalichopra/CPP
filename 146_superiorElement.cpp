#include<bits/stdc++.h>
using namespace std;
vector<int> superiorElements(vector<int> &a) {
  // Write your code here.
  int n = a.size();
  vector<int> ans;
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > maxi) {
      ans.push_back(a[i]);
    }
    maxi = max(maxi, a[i]);
  }
  sort(ans.begin(), ans.end());
  return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans = superiorElements(a);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

return 0;
}