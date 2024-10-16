#include <bits/stdc++.h>
using namespace std;

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        // while the top of the stack is smaller than the current element
        while (!s.empty() && s.top() <= arr[i])
        {
            int mid = s.top();
            s.pop();
            int left = s.empty() ? INT_MAX : s.top();
            sum += mid * min(left, arr[i]);
        }
        s.push(arr[i]);
    }
    while (s.size() > 1)
    {
        int mid = s.top();
        s.pop();
        sum += mid * s.top();
    }
    return sum;
}

int main()
{
    vector<int> arr = {6, 2, 4};
    cout << mctFromLeafValues(arr) << endl;
    

    return 0;
}