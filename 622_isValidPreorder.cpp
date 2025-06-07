
#include <bits/stdc++.h>
using namespace std;


bool verifyPreorderUtil(vector<int>& preorder, int &index, int bound){
    if(index >= preorder.size() || preorder[index] > bound) return true;
    int root = preorder[index++];
    if(!verifyPreorderUtil(preorder, index, root)) return false;
    if(!verifyPreorderUtil(preorder, index, bound)) return false;
    return true;
}
bool verifyPreorder(vector<int>& preorder) {
    int index = 0;
    return verifyPreorderUtil(preorder, index, INT_MAX);
}

int main() {
    vector<int> preorder = {5, 2, 1, 3, 6};
    if (verifyPreorder(preorder)) {
        cout << "The given preorder sequence is valid." << endl;
    } else {
        cout << "The given preorder sequence is not valid." << endl;
    }
    return 0;
}