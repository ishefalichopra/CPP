#include<bits/stdc++.h>
using namespace std;

long long SubArrayMin(vector<int>& nums) {
    int n = nums.size();
    vector<int> prev(n), next(n);
    stack<int> s;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] < nums[s.top()]) {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] <= nums[s.top()]) {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        long long left = i - prev[i];
        long long right = next[i] - i;
        sum += (long long)nums[i] * right * left;
    }
    return sum;
}

long long SubArrayMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> prev(n), next(n);
    stack<int> s;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] >= nums[s.top()]) {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        long long left = i - prev[i];
        long long right = next[i] - i;
        sum += (long long) nums[i] * right * left;
    }
    return sum;
}
long long subArrayRanges(vector<int>& nums) {
    return (SubArrayMax(nums) - SubArrayMin(nums));
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<subArrayRanges(arr);

return 0;
}