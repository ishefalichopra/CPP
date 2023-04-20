#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long reversDigits(long long num) 
{ 
    long long rev_num = 0; 
    while (num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 
  
/* Function to check whether he number is palindrome or not */
bool isPalindrome(long long num) 
{ 
    return (reversDigits(num) == num); 
} 
long long isSumPalindrome(long long n){
    int count=0;
 while(!isPalindrome(n) && count<5)
 {
     int k=reversDigits(n);
     n+=k;
     count++;
 }
 if(isPalindrome(n)) return n;
 return -1;
}
};
int main()
{
int t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    Solution ob;
    cout<<ob.isSumPalindrome(n)<<endl;
}
return 0;
}