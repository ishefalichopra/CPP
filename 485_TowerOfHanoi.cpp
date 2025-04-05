#include<bits/stdc++.h>
using namespace std;


void towerOfHanoi(int disks, char source, char dest, char aux){
    if(disks == 1){
        cout<<"Move disk 1 drom "<<source<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(disks-1, source, aux, dest);
    cout<<"Move disk "<<disks<<" from "<<source<<" to "<<dest<<endl;
    towerOfHanoi(disks-1, aux, dest, source);
}

int main()
{
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

return 0;
}