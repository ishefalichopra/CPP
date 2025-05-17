#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(int index, vector<int> &arr, vector<int> &inorder)
{
    if (index >= arr.size())
        return;
    inorderTraversal(2 * index + 1, arr, inorder);
    inorder.push_back(arr[index]);
    inorderTraversal(2 * index + 2, arr, inorder);
}
int minSwapsToSort(vector<int> &inorder)
{
    vector<pair<int, int>> arrPos;

    for (int i = 0; i < inorder.size(); i++)
    {
        arrPos.push_back({inorder[i], i});
    }

    sort(arrPos.begin(), arrPos.end());

    vector<bool> visited(inorder.size(), false);

    int swaps = 0;

    for (int i = 0; i < inorder.size(); i++)
    {
        if (visited[i] || arrPos[i].second == i)
        {
            continue;
        }

        int cycleSize = 0, j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = arrPos[j].second;
            cycleSize++;
        }
        if (cycleSize > 1)
        {
            swaps += cycleSize - 1;
        }
    }
    return swaps;
}

int minSwaps(vector<int> &arr)
{
    vector<int> inorder;
    inorderTraversal(0, arr, inorder);
    return minSwapsToSort(inorder);
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int swaps = minSwaps(arr);
    cout << "Minimum swaps required to convert the array into a BST: " << swaps << endl;
    return 0;
}