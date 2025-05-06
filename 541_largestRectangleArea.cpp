#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!s.empty() && heights[i] < heights[s.top()])
        {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i = s.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }
    return maxArea;
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int area = largestRectangleArea(heights);
    cout << area << endl;

    return 0;
}