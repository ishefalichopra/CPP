#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> ans;

	if(n==0) return {};

	sort(arr.begin(),arr.end());

	for(int i=0;i<n;i++){
		
		int L1 = arr[i][0];
		int R1 = arr[i][1];
		

		if(!ans.empty() && ans.back()[1]>=L1){
			ans.back()[1] = max(ans.back()[1],R1);
			
		}else{
			ans.push_back({L1,R1});
			
		}
	}
	return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    for(auto i:ans){
    	cout<<i[0]<<" "<<i[1]<<endl;
    }

return 0;
}