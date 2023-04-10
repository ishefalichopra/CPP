#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int oppositeFaceOfDice(int N){
       
        if(N==6){
            return 1;
        }
        if(N==2){
            return 5;
        }
        if(N==3){
            return 4;
        }
        if(N==1){
            return 6;
        }
        if(N==5){
            return 2;
        }
        if(N==4){
            return 3;
        }
        return 0;
}
};
int main()
{
    int N;
    cin>>N;
    solution ob;
    int ans = ob.oppositeFaceOfDice(N);
    cout<<ans<<endl;

return 0;
}