#include<bits/stdc++.h>
using namespace std;
#include<vector>

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n= mat.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
	
}
int main()
{
int n;
cin>>n;
vector<vector<int>> matrix(n,vector<int>(n,0)); 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>matrix[i][j];
    }
}
rotateMatrix(matrix);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}