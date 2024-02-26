#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

int solverec(int n,int x,int y,int z){
    if(n==0){
        return 0;
    }

    if(n<0){
        return INT_MIN;
    }

    int a = solverec(n-x,x,y,z)+1;
    int b = solverec(n-y,x,y,z)+1;
    int c = solverec(n-z,x,y,z)+1;

    int ans = max(max(a,b),c);

    return ans;
}

int solverecmem(int n,int x,int y,int z,vector<int>&dp){
    if(n==0){
        return 0;
    }

    if(n<0){
        return INT_MIN;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int a = solverecmem(n-x,x,y,z,dp)+1;
    int b = solverecmem(n-y,x,y,z,dp)+1;
    int c = solverecmem(n-z,x,y,z,dp)+1;

    dp[n] = max(max(a,b),c);

    return dp[n];
}

int solvetab(int n,int x,int y,int z,vector<int>&dp){
    vector<int>dp(n+1,INT_MIN);
    dp[0] = 0;

    int a = solverecmem(n-x,x,y,z,dp)+1;
    int b = solverecmem(n-y,x,y,z,dp)+1;
    int c = solverecmem(n-z,x,y,z,dp)+1;

    for(int i=1;i<=n;i++){
        if(i-x>=0)
        dp[i] = max(dp[i],dp[i-x]+1);

        if(i-y>=0)
        dp[i] = max(dp[i],dp[i-y]+1);

        if(i-z>=0)
        dp[i] = max(dp[i],dp[i-z]+1);
    }
    
    if(dp[n]<0){
        return 0;
    }

    return dp[n];
}

// minimum number of coins find krne wale method se bhi kar skte hai bs INT_MAX ke place pr INT_MIN likhna hai

int tab(vector<int> &num, int x)
{
    int n = num.size();

    // Create a vector "dp" of size 'X'.
    vector<int> dp(x + 1, INT_MIN);

    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        // Try out for each possible element and take the minimum.
        for (int j = 0; j < n; j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MIN)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    // Return 0 as it is not possible to make desired sum 'X'.
    if (dp[x] == INT_MIN)
    {
        return 0;
    }

    // Return the maximum number of parts.
    return dp[x];
}

int solve(int n,int x,int y,int z){
    vector<int>dp(n+1,-1);

    int ans = solverecmem(n,x,y,z,dp);
}

int main(){
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    return 0;
}