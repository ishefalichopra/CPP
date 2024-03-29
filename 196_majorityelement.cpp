#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
    {
       unordered_map<int,int>map;
       for(int i=0;i<size;i++){
           map[a[i]]++;
       }
       for(int i=0;i<size;i++){
           if(map[a[i]]>size/2){
               return a[i];
           }
          
       }
       
       return -1; 
    }

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    cout << majorityElement(a,n) << endl;

return 0;
}