#include<iostream>
using namespace std;
long long int max_sum_LCM(int n)
{
    long long sum =0;
    for (int i = 1; i*i <=n; i++)
    {
        if (n%i==0)
        {
            sum += i;
            if (n/i != i)
            {
                sum += (n/i);
            }
            
        }
        
    }
    return sum;
}
int main()
{
int n;
cin>>n;
int sum = max_sum_LCM(n);
cout<<"The sum is: "<<sum << endl;
return 0;
}