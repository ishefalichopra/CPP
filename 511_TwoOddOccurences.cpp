#include<bits/stdc++.h>
using namespace std;

vector<int> twoOddNum(vector<int> arr){
    int xor1 = 0;
    for(int num: arr){
        xor1 ^= num;
    }

    int r_set_bit = xor1 & (-xor1);

    int a = 0, b = 0;

    for(int num: arr){
        if((num & r_set_bit)){
            a ^= num;
        }else{
            b ^= num;
        }
    }
   return (a > b) ? vector<int>{a, b} : vector<int>{b, a};
}

int main()
{
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // Input the elements of the array
    }
    
    vector<int> result = twoOddNum(arr);
    cout << "The two odd occurring numbers are: " << result[0] << " and " << result[1] << endl; // Output the two odd occurring numbers

return 0;
}