#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

int removeDuplicates(vector<int> &arr, int n) {
    if (n == 0) {
        return 0;
    }

    std::sort(arr.begin(), arr.end());  // Sort the array

    int uniqueCount = std::unique(arr.begin(), arr.end()) - arr.begin();
    // uniqueCount will give the number of unique elements

    return uniqueCount;
}
int main()
{
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
cout << removeDuplicates(arr, n);

return 0;
}