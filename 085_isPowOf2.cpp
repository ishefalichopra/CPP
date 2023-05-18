#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(int key)
    {
        for (int i = 0; i <= 30; i++)
        {
            if (key == pow(2, i))
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    if(obj.search(n))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

    return 0;
}