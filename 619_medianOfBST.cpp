#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
float inorder_morris(Node* root){
    int n = 0;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            n++;
            curr = curr->right;
        }else{
            Node* pred = curr->left;
            
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            
            if(!pred->right){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = nullptr;
                n++;
                curr = curr->right;
            }
        }
    }
    
    int cnt = 0;
    float median = 0;
    Node* current = root;
    while(current){
        if(!current->left){
            cnt++;
            
            if(n%2 != 0 && cnt == (n+1)/2){
                return current->data;
            }
            
            if(n%2 == 0 && (cnt == n/2 || cnt == (n/2+1))){
                if(median == 0) median = current->data;
                else return (median + current->data)/2.0;
            }
            current = current->right;
        }else{
            Node* pre = current->left;
            
            while(pre->right && pre->right != current){
                pre = pre->right;
            }
            
            if(!pre->right){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = nullptr;
                cnt++;
            
            if(n%2 != 0 && cnt == (n+1)/2){
                return current->data;
            }
            
            if(n%2 == 0 && (cnt == n/2 || cnt == (n/2+1))){
                if(median == 0) median = current->data;
                else return (median + current->data)/2.0;
            }
                current = current->right;
            }
        }
    }
    return -1;
}
float findMedian(struct Node *root)
{
    // vector<int> in;
    // inorder(root, in);

    // int n = in.size();

    // if (n % 2 == 0)
    // {
    //     return (in[n / 2] + in[n / 2 - 1]) / 2.0;
    // }
    // else
    // {
    //     return in[n / 2];
    // }

    return inorder_morris(root);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Median of BST: " << findMedian(root) << endl; // Output: 3
    return 0;
}
