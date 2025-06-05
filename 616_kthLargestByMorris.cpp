#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int search(Node* root, int &k){
    if(!root) return -1;

    int val = search(root->right, k);
    if(val != -1) return val;

    k--;
    if(k == 0) return root->data;

    return search(root->left, k);
}
int morris_inorder(Node* root, int k){
        Node* curr = root;
        int cnt = 0;
        while(curr){
            if(!curr->right){
                cnt++;
                if(cnt == k) return curr->data;
                curr = curr->left;
            }else{
                Node* succ = curr->right;
                while(succ->left && succ->left != curr){
                    succ = succ->left;
                }
                
                if(!succ->left){
                    succ->left = curr;
                    curr = curr->right;
                }else{
                    succ->left = nullptr;
                    cnt++;
                    if(cnt == k) return curr->data;
                    curr = curr->left;
                }
            }
        }
        return -1;
    }

int kthLargest(Node* root, int k){
    return morris_inorder(root, k);
}

int main()
{  
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 3; // Find the 3rd largest element
    int result = kthLargest(root, k);   
    if (result != -1) {
        cout << "The " << k << "rd largest element is: " << result << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree." << endl;
    }

   
return 0;
}