#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr){}
};

Node* newNode(int value){
    Node* temp = new Node(value);
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
};

Node* insert(Node* root, int val, int &suc){
    if(!root) return newNode(val);

    if(val >= root->data){
        root->right = insert(root->right, val, suc);
    }else{
        suc = root->data;
        root->left = insert(root->left, val, suc);
    }
    return root;
}

void replace(vector<int>& arr, int n){
    Node* root = nullptr;

    for(int i=n-1;i>=0;i--){
        int suc = -1;
        root = insert(root, arr[i], suc);
        arr[i] = suc;
    }
}

vector<int> replaceWithLGE(vector<int>&arr, int n){
    replace(arr, n);
    return arr;
}

int main(){
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = arr.size();
    vector<int> ans = replaceWithLGE(arr, n);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}