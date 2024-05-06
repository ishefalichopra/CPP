#include<bits/stdc++.h>
using namespace std;

int isValid(string s) {
            //  the length of string should lie between the given range
            if(s.length() < 7 || s.length() > 15 ){
                return 0;
            }
            string A = "";
            int cnt = 0;
            // if the start of a sting contain two zeros 
            if(s[0] == '0' && s[1] == '0'){
                return 0;
            }
            for(int i = 0; i<s.length(); i++){
                if(s[i] == '.' ){ // if . ancounter check 
                // stoi convert the string into integer
                    if(std::stoi(A) >= 0 && std::stoi(A) <= 255){ // string lie b/w the range
                    A = "";
                    cnt = cnt + 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    //  sting is empty and string encounter zero and next not zero or dot
                    if(A.empty() && s[i] == '0'&& s[i+1] != 0 && s[i+1] != '.'){
                        return 0;
                    }
                    //  A contain only digit if character encounter return 0
                    if(isdigit(s[i]))
                    A.push_back(s[i]);
                    else
                    return 0;
                    }
            }
            if(cnt == 3) {
                //  check for last part
                if(std::stoi(A) >= 0 && std::stoi(A) <= 255) {
                    return 1;
                    } 
                else {
                    return 0;
                    }
            }
            else{
                // if not contain 3 dot(decimal)
            return 0;
            }
        }

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;

return 0;
}