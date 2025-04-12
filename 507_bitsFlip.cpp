#include<bits/stdc++.h>
using namespace std;


int countBits(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return countBits(n>>1) + (n&1);
}

int minBitsFlip(int start, int goal){
    int temp = start ^ goal;
    int result = countBits(temp);
    return result;
}

int main()
{
    int start, goal;
    cin >> start >> goal;
    cout << minBitsFlip(start, goal) << endl; // Output the minimum number of bits to flip

return 0;
}