#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int> &queries)
{
    int maxi = queries[0];
    for (int num : queries)
    {
        maxi = max(maxi, num);
    }
    return maxi;
}

vector<vector<int>> primeFactors(vector<int> &queries)
{
    int maxi = maximum(queries);
    vector<vector<int>> ans;
    vector<bool> is_prime(maxi + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxi; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxi; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        set<int> temp;
        int x = queries[i];

        if (is_prime[x])
        {
            temp.insert(x);
        }
        else
        {
            for (int j = 2; j * j <= x; j++)
            {
                while (x % j == 0)
                {
                    temp.insert(j);
                    x /= j;
                }
            }
        }
        if (x > 1)
        {
            temp.insert(x);
        }
        vector<int> temp1(temp.begin(), temp.end());
        ans.push_back(temp1);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the elements of the array
    }
    vector<vector<int>> result = primeFactors(arr);
    cout << "The prime factors are: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Prime factors of " << arr[i] << ": ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}