#include <bits/stdc++.h>
using namespace std;

void pushDistance(priority_queue<pair<double, int>, vector<pair<double, int>>,
                                 greater<pair<double, int>>> &pq,
                  vector<vector<int>> &points)
{
    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i][0];
        int y = points[i][1];
        double distance = (double)sqrt((x * x) + (y * y));
        pq.push({distance, i});
    }
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;

    pushDistance(pq, points);

    while (k-- && !pq.empty())
    {
        int idx = pq.top().second;
        pq.pop();
        ans.push_back(points[idx]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {2, 2}, {3, 1}};
    int k = 2;
    vector<vector<int>> result = kClosest(points, k);
    for (const auto &point : result)
    {

        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    return 0;
}