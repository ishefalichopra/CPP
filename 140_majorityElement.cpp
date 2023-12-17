#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v)
{
    // Write your code here
    int n = v.size();
    int count = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[i + 1])
        {
            count++;

            if (count == (n / 2))
            {
                return v[i];
            }
        }
        if (n == 1)
        {
            return v[i];
        }
    }

    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << majorityElement(v);
    

    return 0;
}