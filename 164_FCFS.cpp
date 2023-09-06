#include<bits/stdc++.h>
using namespace std;

void CalWaitingTime(int bt[],int wt[], int n){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]= bt[i-1]+wt[i-1];
    }
    
}
void CalTurnAroundTime(int n, int wt[],int bt[], int ta[]){
    for(int i=0;i<n;i++){
        ta[i]=wt[i]+bt[i];
    }
    
}
int avg(int n, int ta[]){
    int x=0;
    for(int i=0;i<n;i++){
       x= x+ta[i];
    }
    return (x/n);
}
int main()
{
    int n;
    cout<<"Enter the number of processes you want to operate on:"<<endl;
    cin>>n;
    int bt[n],at[n],wt[n],ta[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the burst time for process "<<i+1<<endl;
        cin>>bt[i];
    }
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time for process "<<i+1<<endl;
        cin>>at[i];
    }
    CalWaitingTime(bt,wt,n);
    CalTurnAroundTime(n,wt,bt,ta);
    for(int i=0;i<n;i++){
        cout<<"The turnaround time for process "<<i+1<<" "<<ta[i]<<endl;
    }
    int ans=avg(n,ta);
    cout<<"The average turnaround time is: "<<ans;

return 0;
}