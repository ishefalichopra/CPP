#include<bits/stdc++.h>
using namespace std;

vector<int> lcmAndGcd(int a, int b){
    int gcd = a;
    int temp = b;
    while(temp != 0){
        int remainder = gcd%temp;
        gcd = temp;
        temp = remainder;
    }
    int lcm = (a*b)/gcd;
    vector<int> result;
    result.push_back(lcm);
    result.push_back(gcd);
    return result;
}

int main()
{
    int a, b;
    cin>>a>>b;
    vector<int> result = lcmAndGcd(a, b);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

return 0;
}