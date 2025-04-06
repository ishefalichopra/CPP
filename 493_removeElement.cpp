#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] != val) {
           nums[i] = nums[j];
           i++;
        }
    }
    
    return i;
}

int main()
{

    int n, val;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> val;
    
    int newLength = removeElement(nums, val);
    
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
return 0;
}