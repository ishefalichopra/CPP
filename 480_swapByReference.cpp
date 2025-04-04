#include <bits/stdc++.h>
using namespace std;
void swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout<<"a: " << a << " b: " <<b<< endl;
    swap1(a, b);
    cout << "a: " << a << " b: " <<b<<endl;

    return 0;
}