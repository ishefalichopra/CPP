
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};


void inorder(TreeNode* root, vector<int>& in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
}

vector<int> mergeArray(vector<int>& a, vector<int>& b){
    int i = 0, j = 0;
    int k = 0;
    vector<int> ans(a.size()+b.size());
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
           ans[k++] = a[i++];
        }else{
            ans[k++] = b[j++];
        }
    }

    while(i <  a.size()){
        ans[k++] = a[i++];
    }

    while(j < b.size()){
        ans[k++] = b[j++];
    }
    return ans;
}

 TreeNode* buildBalancedTree(vector<int>& in, int start, int end){
        if(start >  end) return nullptr;
        
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(in[mid]);
        
        root->left = buildBalancedTree(in, start, mid-1);
        root->right = buildBalancedTree(in, mid+1, end);
        
        return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);

    vector<int> merged = mergeArray(in1, in2);
    return merged;
}

TreeNode* mergeTwoBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> merged = mergeBST(root1, root2);
    int start = 0, end = merged.size() - 1;
    return buildBalancedTree(merged, start, end);
}

int main() {
    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(7);
    root1->right->right = new TreeNode(20);

    TreeNode *root2 = new TreeNode(12);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(18);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(8);
    root2->right->right = new TreeNode(22);

    TreeNode *mergedRoot = mergeTwoBST(root1, root2);

    cout << "Inorder traversal of the merged BST: ";
    vector<int> in;
    inorder(mergedRoot, in);
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}