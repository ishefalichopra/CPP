#include<bits/stdc++.h>
using namespace std;
int firstRepeated(int arr[], int n) {
        
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++) {
            hash[arr[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            if(hash[arr[i]] > 1) {
                return (i+1);
            }
        }
        return -1;
    }
int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    std::cout << firstRepeated(arr,n);

return 0;
}