#include <bits/stdc++.h>
using namespace std;

void almostSorted(vector<int> arr)
{
    int n = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    int l = -1, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != sorted[i])
        {
            if (l == -1)
                l = i;
            r = i;
        }
    }

    if (l == -1)
    {
        cout << "yes" << endl;
    }
    else
    {
        swap(arr[l], arr[r]);
        if (arr == sorted)
        {
            cout << "yes" << endl;
            cout << "swap " << l + 1 << " " << r + 1 << endl;
            return;
        }

        swap(arr[l], arr[r]); // undo swap
        reverse(arr.begin() + l, arr.begin() + r + 1);
        if (arr == sorted)
        {
            cout << "yes" << endl;
            cout << "reverse " << l + 1 << " " << r + 1 << endl;
            return;
        }

        cout << "no" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    almostSorted(arr);

    return 0;
}