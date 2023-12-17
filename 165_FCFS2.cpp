#include<bits/stdc++.h>
using namespace std;

void calculateTurnaroundTime(int bt[], int at[], int n, int ta[]) {
    int completionTime[n];
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        currentTime = max(currentTime, at[i]); // Ensure we wait for the process to arrive
        completionTime[i] = currentTime + bt[i];
        ta[i] = completionTime[i] - at[i];
        currentTime = completionTime[i];
    }
}

int avg(int n, int ta[]){
    int x=0;
    for(int i=0;i<n;i++){
       x= x+ta[i];
    }
    return (x/n);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int bt[n], at[n], ta[n];

    // Input burst times and arrival times for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> at[i];
    }

    // Calculate turnaround times
    calculateTurnaroundTime(bt, at, n, ta);

    // Display turnaround times
    cout << "Turnaround times for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": " << ta[i] << endl;
    }
     int ans=avg(n,ta);
    
    cout<<"The average turnaround time is: "<<ans;



    return 0;
}
