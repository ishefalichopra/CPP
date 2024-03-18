#include<bits/stdc++.h>
using namespace std;

int findLargestConsecutiveSequence(int arr[], int N){
    set<int>hash;
      for(int i=0;i<N;i++){
          hash.insert(arr[i]);
      }
      int maxCnt=INT_MIN;
      int n1=hash.size();
      for(int i=0;i<N;i++){
          int x=arr[i];
          if(hash.find(x-1)==hash.end()){
              int cnt=0;
              while(hash.find(x)!=hash.end()){
                  cnt++;
                  x++;
              }
              maxCnt=max(maxCnt,cnt);
          }
          
      }
      return maxCnt;
    }

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    cout << findLargestConsecutiveSequence(arr, n);

return 0;
}