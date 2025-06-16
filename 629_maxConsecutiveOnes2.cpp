#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes2(vector<int>& arr, int k){
    int zeroes = 0, maxCnt = 0;
    int left = 0;
    for(int right=0;right<arr.size();right++){
        if(arr[right] == 0) zeroes++;
        while(zeroes > k){
            if(arr[left] == 0) zeroes--;
            left++;
        }
        maxCnt = max(maxCnt, right-left+1);
    }
    return maxCnt;
}


int main()
{

    vector<int>arr = {1, 0, 1, 0, 1, 1, 0};
    int k = 2;

    cout<<maxConsecutiveOnes2(arr, k);

return 0;
}