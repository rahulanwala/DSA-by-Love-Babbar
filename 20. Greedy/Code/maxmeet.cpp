#include <bits/stdc++.h>
using namespace std;


// https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class meet{
    public:
    int st;
    int ed;
    int ind;
};

class Solution{
public:
static bool cmp(meet a,meet b){
        return a.ed<b.ed;
    }
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        meet v[n];
        
        for(int i=0;i<n;i++){
            v[i].st = start[i];
            v[i].ed = end[i];
            v[i].ind = i;
        }
        
        sort(v,v + n,cmp);
        
        vector<int>ans;
        int st = v[0].st;
        int ed = v[0].ed;
        ans.push_back(v[0].ind+1);
        for(int i=1;i<n;i++){
            if(v[i].st>ed){
                ans.push_back(v[i].ind+1);
                ed = v[i].ed;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends