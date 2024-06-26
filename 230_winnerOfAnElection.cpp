#include<bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[],int n)
    {
            //using map to store count of votes for each name.
            unordered_map<string,int>mp;
            
            //storing the frequency of names in the map.
            for(int j=0;j<n;j++)
            {
                mp[arr[j]]++;
            }
            
            int maxx=-1;
            string answer="";
            
            //iterating through the map to find the name with highest frequency.
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                //updating answer whenever we get any name with frequency 
                //greater than frequency of name stored previously.
                if(it->second>maxx)
                {
                    maxx=it->second;
                    answer=it->first;
                }
                //if frequency of current name is same as the previously 
                //stored name then we compare both names and store 
                //lexicographically smaller name.
                else if(it->second == maxx && answer.compare(it->first) > 0)
                    answer = it->first;
            }
            //storing name with highest votes and the number of votes in a list.
            vector<string> vec = {answer,to_string(maxx)};
            
            //returning the list.
            return vec;
    }


int main()
{

    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<string> result=winner(arr,n);
    cout<<result[0]<<" "<<result[1]<<endl;

return 0;
}