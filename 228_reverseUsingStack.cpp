#include<bits/stdc++.h>
using namespace std;

char* reverse(char* S, int len){
    stack<char>stack;
    for(int i=0;i<len;i++){
        stack.push(S[i]);
    }
    char* reversedString = new char[len+1];
    int index=0;
    while(!stack.empty()){
        reversedString[index++]=stack.top();
        stack.pop();
    }
    reversedString[len]='\0';
    return reversedString;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char S[10000];
        cin>>S;
        int len = strlen(S);
        char* ans = reverse(S,len);
        cout<<ans<<endl;
    }


return 0;
}