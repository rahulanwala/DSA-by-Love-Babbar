//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back(make_pair(start[i],end[i]));
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int cnt=1;
        int st = v[0].first;
        int ed = v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>ed){
                cnt++;
                ed = v[i].second;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends