#include<bits/stdc++.h>
using namespace std;

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

int strStr(string haystack, string needle){
    if(needle.length()==0){
        return 0;
    }

    int haystackSize = haystack.size();
    int needleSize = needle.size();

    for(int i=0;i< haystackSize - needleSize + 1;i++){
        if(haystack.substr(i, needleSize)==needle){
            return i;
        }
    }
    return -1;
}


int main()
{
    string haystack, needle;
    cin>>haystack>>needle;
    cout<<strStr(haystack, needle)<<endl;

return 0;
}