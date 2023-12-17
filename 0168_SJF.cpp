#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int bt;
    int at;
};

bool CompareBurstTime(const Process &p1, const Process &p2)
{
 
        return p1.bt < p2.bt;
}

void CalCompletionTime(vector<Process> &processes, int n, vector<int> &ct)
{
    ct[0] = processes[0].bt;
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + processes[i].bt;
    }
}

void CalTAT(vector<Process> &processes, int n, vector<int> &ct, vector<int> &tat)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - processes[i].at;
    }
}

void CalWT(vector<Process> &processes, int n, vector<int> &tat, vector<int> &wt)
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - processes[i].bt;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes:" << endl;
    cin >> n;

    vector<Process> processes(n);
    vector<int> ct(n);
    vector<int> wt(n);
    vector<int> tat(n);

    cout << "Enter the burst time of each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].bt;
        processes[i].id = i + 1;
    }
    cout << "Enter the arrival time of each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].at;
    }

    sort(processes.begin(), processes.end(), CompareBurstTime);
    CalCompletionTime(processes, n, ct);
    CalTAT(processes, n, ct, tat);
    CalWT(processes, n, tat, wt);

    double avgTAT = accumulate(tat.begin(), tat.end(), 0.0) / n;
    double avgWT = accumulate(wt.begin(), wt.end(), 0.0) / n;

    cout << "Average turnaround time: " << avgTAT << endl;
    cout << "Average waiting time: " << avgWT << endl;

    return 0;
}
