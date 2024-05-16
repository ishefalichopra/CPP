#include<bits/stdc++.h>
using namespace std;

bool isRotation(const std::string& s1, const std::string& s2) {
    // Check if the lengths are different
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Concatenate s1 with itself
    std::string concatenated = s1 + s1;
    
    // Check if s2 is a substring of the concatenated string
    return concatenated.find(s2) != std::string::npos;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << isRotation(s1, s2) << endl; 

return 0;
}