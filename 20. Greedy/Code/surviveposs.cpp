//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

class Solution{
public:
    int minimumDays(int s, int n, int m){
        // code here
        int sunday = s/7;
        
        int buy = s-sunday;
        int total = s*m;
        int ans=0;
        
        if(total%n==0){
            ans = total/n;
        }else{
            ans = total/n + 1;
        }
        
        if(ans<=buy){
            return ans;
        }else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends