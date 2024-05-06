#include<bits/stdc++.h>
using namespace std;

bool isRotated(string a, string b)
    { string temp = a+a;
        int l1=temp.length();
        int l2=b.length();
        if(temp.find(b)==2 || temp.find(b)==abs(l1-l2-2)) return 1; 
        return 0;
        
    }

int main()
{
    string a,b;
    cin >> a >> b;
    cout << isRotated(a,b) << endl;


return 0;
}