#include<bits/stdc++.h>
using namespace std;
//User function Template for C++
class Solution
{
public:
    string getNumber(int B, int N)
    {
        string result="";
        int digit;
        string temp;
        while(N>0){
            digit=N%B;
            temp=to_string(digit);
            switch (digit){
                case 10: temp="A";
                break;
                case 11: temp="B";
                break;
                case 12: temp="C";
                break;
                case 13: temp="D";
                break;
                case 14: temp="E";
                break;
                case 15: temp="F";
                break;
            }
            result=temp+result;
            N/=B;
        }
        return result;
    }
};
int main()
{
    int B,N;
    cin>>B>>N;
    Solution obj;
    cout<<obj.getNumber(B,N)<<endl;

return 0;
}