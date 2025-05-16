
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *treeFromString(string s)
{
    if (s.empty())
        return nullptr;

    stack<pair<Node *, bool>> st;
    Node *root = nullptr;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ')')
        {
            st.pop();
            i++;
        }
        else if (s[i] == '(')
        {
            i++;
            if (s[i] == ')' && i < s.size())
            {
                if (!st.empty())
                {
                    st.top().second = true;
                }
                i++;
            }
        }
        else
        {
            int sign = 1;
            if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            int num = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            num *= sign;
            Node *node = new Node(num);
            if (!root)
            {
                root = node;
            }
            else if (!st.empty())
            {
                Node *parent = st.top().first;
                bool isLeft = st.top().second;
                if (!isLeft)
                {
                    parent->left = node;
                    st.top().second = true;
                }
                else
                {
                    parent->right = node;
                }
            }
            st.push({node, false});
        }
    }
    return root;
}

int main()
{
    string s = "1(2(4)(5))(3(6)(7))";
    Node *root = treeFromString(s);
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        ans.push_back(curr->data);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}