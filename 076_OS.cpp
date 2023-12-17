#include<bits/stdc++.h>
using namespace std;
void CalWaitingTime(int bt[], int wt[], int n){
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i]= wt[i-1]+bt[i-1];
    }
}

void CalTurnaroundTime(int bt[], int wt[], int tat[], int n){

    for(int i=0;i<n;i++){
        tat[i] = wt[i]+bt[i];
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
    int bt[n], wt[n], tat[n];
    cout<<"Enter the burst time of each process:"<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    CalWaitingTime(bt, wt, n);
    CalTurnaroundTime(bt, wt, tat, n);
    cout<<"Average waiting time: "<<Avg(wt, n)<<endl;
    cout<<"Average turnaround time: "<<Avg(tat, n)<<endl;

return 0;
}