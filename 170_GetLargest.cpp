#include<bits/stdc++.h>
using namespace std;

long long getmin(long long a[],int n){
  long long min = INT_MAX;
  for(int i=0;i<n;i++){
    if(a[i]<min){
        min = a[i];
    }
  }
  return min;
}

long long getmax(long long a[],int n){
    long long max= INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max= a[i];
        }
    }
    return max;
}

pair<long long, long long>getMinMax(long long a[], int n){
    long long min = getmin(a,n);
    long long max = getmax(a,n);
    return {min,max};
}

// #include <iostream>
// #include <utility> // Add this line to include the <utility> header for the pair type

// // ... existing code ...

// // Overload the << operator for pair<long long, long long>
// std::ostream& operator<<(std::ostream& os, const std::pair<long long, long long>& p) {
//     os << "(" << p.first << ", " << p.second << ")";
//     return os;
// }

int main()
{
    int n;
    std::cin >> n;
    long long a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    std::pair<long long,long long> ans = getMinMax(a,n);
    std::cout << "answer is: " << ans.first<<" "<<ans.second << std::endl;

    return 0;
}