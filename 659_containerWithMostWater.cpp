#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxArea = 0, l = 0, r = n - 1;

    while (l < r)
    {
        int h = min(height[l], height[r]);
        int len = r - l;
        int currArea = len * h;
        maxArea = max(maxArea, currArea);
        if (height[l] <= height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return maxArea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << "Maximum area of water container: " << result << endl;

    return 0;
}