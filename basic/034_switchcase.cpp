#include<iostream>
using namespace std;
class Solution{   
public:
    string isInRange(int N){
        // code here
        switch(N){
            case 1:
            cout<<("one");
            break;
            case 2:
            cout<<("two");
            break;
            case 3:
            cout<<("three");
            break;
            case 4:
            cout<<("four");
            break;
            case 5:
            cout<<("five");
            break;
            case 6:
            cout<<("six");
            break;
            case 7:
            cout<<("seven");
            break;
            case 8:
            cout<<("eight");
            break;
            case 9:
            cout<<("nine");
            break;
            case 10:
            cout<<("ten");
            break;
            default:
            cout<<("not in range");
            break;
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while (t--){
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.isInRange(N)<<endl;
    }
    {
        /* code */
    }
    

return 0;
}