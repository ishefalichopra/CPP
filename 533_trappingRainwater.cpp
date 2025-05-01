#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int l = 0, r = n - 1;
    int water = 0;
    int leftMax = 0, rightMax = 0;

    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] < leftMax)
            {
                water += leftMax - height[l];
            }
            else
            {
                leftMax = height[l];
            }
            l++;
        }
        else
        {
            if (height[r] < rightMax)
            {
                water += rightMax - height[r];
            }
            else
            {
                rightMax = height[r];
            }
            r--;
        }
    }
    return water;
}

int trapStack(vector<int> &height)
{
    int n = height.size();
    int water = 0;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && height[i] > height[s.top()])
        {
            int top = s.top();
            s.pop();

            if (s.empty())
            {
                break;
            }

            int l = i - s.top() - 1;
            int h = min(height[i], height[s.top()]) - height[top];
            water += l * h;
        }
        s.push(i);
    }
    return water;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << trapStack(height) << endl;

    return 0;
}