#include<bits/stdc++.h>
using namespace std;

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

bool ispalindrome(string s, int left, int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0;
    int right = s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return ispalindrome(s, left+1, right) || ispalindrome(s, left, right-1);
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    cout<<validPalindrome(s)<<endl;

return 0;
}