#include <iostream>
#include <stdio.h>
using namespace std;
void multiply(int A[][100],int B[][100], int C[][100], int N);
int main()
{  int t;
cin>>t;
while(t--){
    int N;
    cin>>N;
    int A[100][100], B[100][100], C[100][100];
    int i,j;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>B[i][j];
        }
    }
    multiply(A,B,C,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<C[i][j];
        }
    }
    cout<<endl;
}

    return 0;
}
void multiply(int A[][100], int B[][100], int C[][100], int n)
{
    // add code here.

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)

                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
        }
}
