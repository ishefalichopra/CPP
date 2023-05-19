#include <bits/stdc++.h>
using namespace std;
int linearSearch(int num[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (num[i] == key)
        {
            return 1;
        }
       
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int key;
    cin >> key;
    if(linearSearch(num, n, key)){
        cout<<"Found ";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}