#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int result = 0;

        if (n == 1)
            return 1;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;

            for (int j = 0; j < n; j++) {
                
                if(j==i)continue;

                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];

                auto theta = atan2(dy , dx); //calculating slope
                mp[theta]++;
            }
            for (auto& it : mp) {
                result = max(result, it.second + 1);
            }
        }
        return result;
    }

int main()
{
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << maxPoints(points) << endl;  

return 0;
}