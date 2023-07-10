#include<bits/stdc++.h>
using namespace std;


int partitionArray(int input[], int start, int end) {
	// Write your code here
	int pivot= input[start];
	int i= start;
	int j= end;
	while(i<j){
		while(input[i]<=pivot && i<=end-1){
			i++;
		}
		while(input[j]>pivot && j>=start+1){
			j--;
		}
		if(i<j){
			swap(input[i],input[j]);
		}
		
	}
	swap(input[start],input[j]);
	return j;
}
void qs(int input[], int start, int end){
	if(start<end){
		int pI= partitionArray(input, start,  end);
		qs(input,start, pI-1);
		qs(input,pI+1,end);
	}
}

void quickSort(int input[], int start, int end) {
	qs(input,start,end);
}


int main()
{
int n;
cin >> n;
int *input = new int[n];
for(int i = 0; i < n; i++)
cin >> input[i];
quickSort(input, 0, n - 1);
for(int i = 0; i < n; i++)
cout << input[i] << " ";
delete[] input;
return 0;
}