#include<bits/stdc++.h>
using namespace std;
int getMax(int num[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(num[i]>max){
            max = num[i];
        }
    }
    return max;
}
int getMin(int num[], int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(num[i]<min){
            min = num[i];
        }
    }
    return min;
}
int main()
{
int n;
cin>>n;
int num[n];
for(int i=0;i<n;i++){
    cin>>num[i];
}
cout<<getMax(num, n)<<endl;
cout<<getMin(num, n)<<endl;
return 0;
}