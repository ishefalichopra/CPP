#include<bits/stdc++.h>
using namespace std;
bool isSort1(int n, vector<int> a){
     for(int i=0;i<n-1;i++){
        if(a[i]<=a[i+1]){
            continue;
        }
        else{
            return 0;
            
        }
    }
    return 1;
}
bool isSort2(int n, vector<int> a){
     for(int i=0;i<n-1;i++){
        if(a[i]>=a[i+1]){
            continue;
        }
        else{
            return 0;
            
        }
    }
    return 1;
}


int isSorted(int n, vector<int> a) {
    // Write your code here.
   
    if(isSort1(n,a)||isSort2(n,a)){
        return 1;
    }
    else{
        return 0;
    }

}

int main()
{
int n;
cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++)
cin >> a[i];
cout << isSorted(n, a);

return 0;
}