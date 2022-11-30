#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void PrintNos(int n)
{
   if(n>0){ PrintNos(n - 1);
    cout << n << " " << endl;}
    return;
}
int main()
{
    int n;
    cin >> n;
    PrintNos(n);
   
    return 0;
}