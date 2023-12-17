#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int circleTouch(int X1, int Y1, int R1, int X2, int Y2, int R2) {
        // code here
        
            double distance = sqrt(pow((X2-X1),2) + pow((Y2-Y1),2));
            
            if((R1 + R2) < distance)
                return 0;
            else
                return 1;
    }
};
   
int main()
{
    
    int X1, Y1, R1, X2, Y2, R2;
    cin>>X1>>Y1>>R1>>X2>>Y2>>R2;
    Solution obj;
    cout<<obj.circleTouch(X1, Y1, R1, X2, Y2, R2);

return 0;
}