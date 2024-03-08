#include<bits/stdc++.h>
using namespace std;

int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        unordered_map <int,int> hash;
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(hash[arr[i]]==1){
                return arr[i];
            }
        }
        
        return 0;
    } 

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    std::cout << firstNonRepeating(arr,n);

return 0;
}