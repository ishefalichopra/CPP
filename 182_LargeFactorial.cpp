#include<bits/stdc++.h>
using namespace std;

vector<int>factorial(int N){
    vector<int>result;
    result.push_back(1);

    for(int i=2;i<=N;i++){
        int carry=0;
        for(int j=0;j<result.size();j++){
            int product= result[j]*i+carry;
            result[j]=product%10;
            carry=product/10;
        }
        while(carry){
            result.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    int N;
    std::cin >> N;
    vector<int>result=factorial(N);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }



return 0;
}