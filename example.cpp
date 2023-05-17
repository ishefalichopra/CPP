#include<iostream>
int sumofdiagnolmatrices(int n, int matrixA[][n], int matrixB[][n]){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=matrixA[i][j]+matrixB[i][j];
            }
        }
    }
    return sum;
}
//please explain above code working
int sliceString(int n, std::string s){
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            count++;
        }
    }
    return count;
}
main(){
    std::cout<<"hello";
}