#include<bits/stdc++.h>
using namespace std;

int distinctPrimeFactors(vector<int>& nums){
    unordered_set<int> temp;
    for(int num: nums){
        int i = 2;
        while(i*i <= num){
            if(num%i == 0){
                temp.insert(i);
                while(num%i == 0){
                    num /= i;
                }
            }
            i++;
        }
        if(num > 1){
            temp.insert(num);
        }
    }
    return temp.size();
}


int main()
{
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // Input the elements of the array
    }
    
    int result = distinctPrimeFactors(arr);
    cout << "The number of distinct prime factors is: " << result << endl; // Output the number of distinct prime factors

return 0;
}
