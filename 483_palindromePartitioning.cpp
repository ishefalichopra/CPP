#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void checkPalindrome(string s, int index, vector<string>&temp, vector<vector<string>>& ans){
    if(index == s.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = index; i < s.size(); i++){
        if(isPalindrome(s, index, i)){
            temp.push_back(s.substr(index, i-index+1));
            checkPalindrome(s, i+1, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<string>temp;
    vector<vector<string>> ans;
    checkPalindrome(s, 0, temp, ans);
    return ans;
}
int main()
{
    string s;
    cin>>s;
    vector<vector<string>> ans = partition(s);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total Palindrome Partitions: "<<ans.size()<<endl;

return 0;
}