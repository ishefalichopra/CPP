#include<bits/stdc++.h>
using namespace std;

int max_sumPath(int a[],int b[], int l1, int l2){
    int sum=0,sum1=0,sum2=0;
    int i=0,j=0;


    while(i<l1&&j<l2){
        if(a[i]<b[j]){
            sum1+=a[i++];
        }
        else if(a[i]>b[j]){
            sum2+=b[j++];
        }
        else{
            sum+=max(sum1,sum2);
            sum+=a[i];
            sum1=0;
            sum2=0;
            i++;
            j++;
        }
    }

    while(i<l1){
        sum1+=a[i++];
    }


    while(j<l2){
        sum2+=b[j++];
    }

    sum+=max(sum1,sum2);

    return sum;
}

int main()
{

    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=0;i<m;++i){
        cin >> b[i];
    }
    cout << max_sumPath(a,b,n,m) << endl;

return 0;
}