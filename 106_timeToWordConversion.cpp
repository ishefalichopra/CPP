#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string timeToWord(int H, int M){
        char nums[][64] = { "zero", "one", "two", "three", "four", 
                        "five", "six", "seven", "eight", "nine", 
                        "ten", "eleven", "twelve", "thirteen", 
                        "fourteen", "fifteen", "sixteen", "seventeen", 
                        "eighteen", "nineteen", "twenty", "twenty one", 
                        "twenty two", "twenty three", "twenty four", 
                        "twenty five", "twenty six", "twenty seven", 
                        "twenty eight", "twenty nine", 
                      }; 
  
        if (M == 0){
            string s=nums[H]; 
            return s+" o' clock";
        } 
        else if (M == 1){ 
            string s=nums[H];
            return "one minute past "+s; 
        }
        else if (M == 59){ 
            string s=nums[(H % 12) + 1];
            return "one minute to "+s; 
        }
        else if (M == 15){ 
            string s=nums[H];
            return "quarter past "+s; 
        }
        else if (M == 30){ 
            string s=nums[H];
            return "half past "+s; 
        }
        else if (M == 45){ 
            string s=nums[(H % 12) + 1];
            return "quarter to "+s; 
        }
        else if (M <= 30){ 
            string s=nums[M];
            string s1=nums[H];
            return s+" minutes past "+s1; 
        }
        else if (M > 30){ 
            string s=nums[60 - M];
            string s1=nums[(H % 12) + 1];
            return s+" minutes to "+s1; 
        }
    }
};
int main()
{
    int H,M;
    cin>>H>>M;
    Solution obj;
    cout<<obj.timeToWord(H,M)<<endl;

return 0;
}