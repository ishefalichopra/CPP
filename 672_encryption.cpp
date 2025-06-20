#include<bits/stdc++.h>
using namespace std;

string removeEmptySpaces(string s)
{
    string ans = "";
    for (char c : s)
    {
        if (c != ' ')
        {
            ans += c;
        }
    }
    return ans;
}

string encryption(string s){
    s = removeEmptySpaces(s);
    int n = s.size();
    int row = floor(sqrt(n));
    int col = ceil(sqrt(n));

    if (row * col < n)
        row++;

    string ans = "";

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int index = j * col + i;
            if (index < n)
            {
                ans += s[index];
            }
        }
        if (i < col - 1)
        {
            ans += ' ';
        }
    }
    return ans;
}


int main()
{
    string s = "have a nice day";
    string result = encryption(s);
    cout << "Encrypted string: " << result << endl;

return 0;
}