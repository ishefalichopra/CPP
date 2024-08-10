#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int colNo)
{

    string result = "";

    while (colNo > 0)
    {

        colNo--;

        char currChar = char('A' + colNo % 26);
        result = currChar + result;
        colNo = colNo / 26;
    }
    return result;
}

int main()
{
    int colNo = 701;
    cout << convertToTitle(colNo) << endl;

    return 0;
}