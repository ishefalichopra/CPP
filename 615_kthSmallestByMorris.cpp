
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int morris_inorder(Node* root, int k){
        int cnt = 0;
        Node* curr = root;
        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt == k) return curr->data;
                curr = curr->right;
            }else{
                Node* pred = curr->left;
                while(pred->right && pred->right != curr)
                pred = pred->right;
                
                if(!pred->right){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    cnt++;
                    if(cnt == k) return curr->data;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }

    int kthSmallest(Node* root, int k){
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

    int k = 3; // Find the 3rd smallest element
    int result = kthSmallest(root, k);
    if (result != -1) {
        cout << "The " << k << "rd smallest element is: " << result << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree." << endl;
    }
   
return 0;
}