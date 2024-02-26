#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
    long long rec(int m,int n,int x){
        if((x<0) || (n==0 && x!=0) || (n!=0 && x==0)){
            return 0;
        }
        
        if(n==0 && x==0){
            return 1;
        }
        
        long long ans=0;
        for(int i=1;i<=m;i++){
            ans += rec(m,n-1,x-i);
        }
        
        return ans;
    }
    
    long long mem(int m,int n,int x,vector<vector<long long>>&dp){
        if((x<0) || (n==0 && x!=0) || (n!=0 && x==0)){
            return 0;
        }
        
        if(n==0 && x==0){
            return 1;
        }
        
        if(dp[n][x]!=-1){
            return dp[n][x];
        }
        
        long long ans=0;
        for(int i=1;i<=m;i++){
            ans += mem(m,n-1,x-i,dp);
        }
        
        return dp[n][x] = ans;
    }
    
    long long tab(int m,int n,int x){
        vector<vector<long long>>dp(n+1,vector<long long>(x+1,0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                long long ans=0;
                for(int k=1;k<=m;k++){
                    if(j-k>=0){
                    ans += dp[i-1][j-k];
                    }
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[n][x];
    }
    
    long long space(int m,int n,int x){
        vector<long long>curr(x+1,0);
        vector<long long>prev(x+1,0);
        
        prev[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                long long ans=0;
                for(int k=1;k<=m;k++){
                    if(j-k>=0){
                    ans += prev[j-k];
                    }
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        
        return prev[x];
    }
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        
        // return rec(M,N,X);
        
        // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        
        // return mem(M,N,X,dp);
        
        // return tab(M,N,X);
        
        return space(M,N,X);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}