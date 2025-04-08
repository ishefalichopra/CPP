#include<bits/stdc++.h>
using namespace std;

bool isEven(int n) {
    return n&1? false:true;
}

int main()
{
    int n;
    cin >> n;
    if (isEven(n)) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }

return 0;
}