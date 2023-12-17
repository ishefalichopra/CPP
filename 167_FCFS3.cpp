#include<bits/stdc++.h>
using namespace std;

void CalulateTurnaroundTime(int bt[], int tat[],int at[], int n){
    int completionTime[n];
    int currentTime = 0;
    for(int i=0;i<n;i++){
        currentTime = max(currentTime, at[i]);
        completionTime[i] = currentTime + bt[i];
        tat[i] = completionTime[i]-at[i];
       currentTime= completionTime[i];
    }
}

int Avg(int tat[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += tat[i];
    }
    return (sum/n); 
}

int main()
{
    int n;
    cout<<"Enter the  number of processes:"<<endl;
    cin>>n;
    int bt[n], wt[n], tat[n], at[n];
    cout<<"Enter the burst time of each process:"<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    cout<<"Enter the arrival time of each process:"<<endl;
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    CalulateTurnaroundTime(bt, tat, at, n);
    
    cout<<"Average turnaround time: "<<Avg(tat, n)<<endl;

return 0;
}