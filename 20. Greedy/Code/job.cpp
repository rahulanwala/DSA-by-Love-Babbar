#include<bits/stdc++.h>
using namespace std; 

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr,arr+n,cmp);
        
        int maxDead = INT_MIN;
        for(int i=0;i<n;i++){
            maxDead = max(maxDead,arr[i].dead);
        }
        
        // 1 based indexing
        
        vector<int>Dead(maxDead+1,-1);
        
        int cnt=0;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            int currid = arr[i].id;
            int currdead = arr[i].dead;
            int currprofit = arr[i].profit;
            
            for(int k=currdead;k>=1;k--){
                if(Dead[k]==-1){
                    cnt++;
                    maxprofit += currprofit;
                    Dead[k] = currid;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(maxprofit);
        
        return ans;
    } 
};

int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

