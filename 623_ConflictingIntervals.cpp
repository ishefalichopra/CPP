#include <bits/stdc++.h>
using namespace std;

struct Node
{
    vector<int> interval;
    int maxEnd;
    Node *left, *right;

    Node(vector<int> i)
    {
        interval = i;
        maxEnd = i[1];
        left = right = nullptr;
    }
};

bool isOverlap(vector<int> &a, vector<int> &b)
{
    return a[0] < b[1] && b[0] < a[1];
}

void searchForOverlap(Node *root, vector<int> &interval)
{
    if (!root)
        return;

    if (isOverlap(root->interval, interval))
    {
        cout << "[" << interval[0] << "," << interval[1] << "] Conflicts with ["
             << root->interval[0] << "," << root->interval[1] << "]\n";
    }

    if (root->left && root->left->maxEnd > interval[0])
        searchForOverlap(root->left, interval);

    searchForOverlap(root->right, interval);
}

Node *insert(Node *root, vector<int> &interval)
{
    if (!root)
        return new Node(interval);

    if (interval[0] < root->interval[0])
        root->left = insert(root->left, interval);
    else
        root->right = insert(root->right, interval);

    root->maxEnd = max(root->maxEnd, interval[1]);

    return root;
}

void findAllConflicts(vector<vector<int>>& appointments){
    Node* root = nullptr;

    root = insert(root, appointments[0]);

    for(int i=1;i<appointments.size();i++){
        searchForOverlap(root, appointments[i]);
        root = insert(root, appointments[i]);
    }
}

int main()
{
    vector<vector<int>> appointments = {
        {1, 3},
        {2, 4},
        {5, 7},
        {6, 8},
        {9, 10}
    };

    cout << "Conflicting intervals:\n";
    findAllConflicts(appointments);
    return 0;
}