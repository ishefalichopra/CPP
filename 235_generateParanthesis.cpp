#include<bits/stdc++.h>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
void backtrack(vector<string>&result, string current, int open, int close, int max){
    if(current.length()==max*2){
        result.push_back(current);
        return;
    }
    if(open<max){
        backtrack(result, current+"(", open+1, close, max);
    }
    if(close<open){
        backtrack(result, current+")", open, close+1, max);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<string> result = generateParenthesis(n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }

return 0;
}