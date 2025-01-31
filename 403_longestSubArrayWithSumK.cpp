
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> prefixSumIndex;
        int n = arr.size();
        int maxLength = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxLength = i + 1;
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end())
            {
                maxLength = max(maxLength, i - prefixSumIndex[sum - k]);
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end())
            {
                prefixSumIndex[sum] = i;
            }
        }
        return maxLength;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--)
    {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); 
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
        {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); 
        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}
