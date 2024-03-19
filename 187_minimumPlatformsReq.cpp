#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	vector<pair<int,char>>order;
    	
    	for(int i=0;i<n;i++){
    	    order.push_back(make_pair(arr[i],'a'));
    	    order.push_back(make_pair(dep[i],'d'));
    	}
    	
    	sort(order.begin(),order.end());
    	
    	int result=1;
    	int cnt=0;
    	
    	vector<pair<int,char>>::iterator it = order.begin();
    	
    	for(;it!=order.end();it++){
    	    if((*it).second=='a'){
    	        cnt++;
    	    }
    	    else
    	    cnt--;
    	    
    	    if(cnt>result){
    	        result=cnt;
    	    }
    	}
    	
    	return result;
    }

int main()
{
    int n;
    cin >> n;
    int arr[n],dep[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    cout << findPlatform(arr,dep,n);

return 0;
}