#include<bits/stdc++.h>
using namespace std;

long long checkPiles(vector<int>& piles, int index) {
    long long sum = 0;

    for (int i = 0; i < piles.size(); i++) {
        sum += (long long)ceil((double)piles[i] / index);
    }

    return sum;
}
int minEatingSpeed(vector<int>& piles, int h) {
    long long ans = 0;
    long long low = 1;
    long long high = 1e9;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (checkPiles(piles, mid) <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return (int)ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int>piles(n);

    for(int i=0;i<n;i++){
        cin>>piles[i];
    }

    int h;
    cin>>h;

    cout<<minEatingSpeed(piles,h)<<endl;

return 0;
}