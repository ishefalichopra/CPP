#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidsCollision(vector<int> &asteroids)
{
    stack<int> s;
    for (int a : asteroids)
    {
        bool destroyed = false;
        while (!s.empty() && a < 0 && s.top() > 0)
        {
            if (s.top() < -a)
            {
                s.pop();
                continue;
            }
            else if (s.top() == -a)
            {
                s.pop();
            }
            destroyed = true;
            break;
        }
        if (!destroyed)
        {
            s.push(a);
        }
    }

    vector<int> ans(s.size());
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> asteroids(n);
    for (int i = 0; i < n; i++)
    {
        cin >> asteroids[i];
    }

    vector<int> ans = asteroidsCollision(asteroids);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}