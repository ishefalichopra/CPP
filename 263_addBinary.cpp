#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b){
    string resulkt="";\
    int i=a.size()-1;
    int j=b.size()-1;

    int carry=0;

    while(i>=0||j>=0||carry){
        int sum= carry;
        if(i>=0){
            sum+= a[i]-'0';
            i--;
        }
        if(j>=0){
            sum+= b[j]-'0';
            j--;
        }
        carry= sum/2;
        result+= (sum%2)-'0';
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a="11";
    string b="1";
    cout<<addBinary(a,b)<<endl;

return 0;
}