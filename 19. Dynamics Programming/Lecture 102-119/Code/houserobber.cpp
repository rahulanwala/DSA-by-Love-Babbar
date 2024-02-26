#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=1

long long rec(vector<int>&nums,int n){
    if(n<0){
        return 0;
    }

    if(n==0){
        return nums[0];
    }

    long long inc = rec(nums,n-2) + nums[n];
    long long exc = rec(nums,n-1);

    return max(inc,exc);
}

long long recmem(vector<int>&nums,int n,vector<long long>&dp){
    if(n<0){
        return 0;
    }

    if(n==0){
        return nums[0];
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    long long inc = recmem(nums,n-2,dp) + nums[n];
    long long exc = recmem(nums,n-1,dp);
    dp[n] = max(inc,exc);

    return dp[n];
}

long long tab(vector<int>&nums,int n){
    vector<long long>dp(n+1,-1);
    dp[0] = nums[0];

    for(int i=1;i<=n;i++){
        long long inc = dp[i-2] + nums[i];
        long long exc = dp[i-1];
        dp[i] = max(inc,exc);
    }

    return dp[n];
}

long long spaceOpti(vector<int>&nums,int n){
    long long prev2 = 0;
    long long prev1 = nums[0];

    for(int i=1;i<=n;i++){
        long long inc = prev2 + nums[i];
        long long exc = prev1;
        prev2 = prev1;
        prev1 = max(inc,exc);
    }

    return prev1;
}

long long maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();

    // return rec(nums,n-1);

    // vector<int>dp(n,-1);

    // return recmem(nums,n-1,dp);

    // return tab(nums,n-1);

    return spaceOpti(nums,n-1);
}
long long int houseRobber(vector<int>& house)
{
    // Write your code here.
    int n = house.size();

    if(n==1){
        return house[0];
    }

    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=0){
            second.push_back(house[i]);
        }
        if(i!=n-1){
            first.push_back(house[i]);
        }
    }

    return max(maximumNonAdjacentSum(first),maximumNonAdjacentSum(second));
}

int main(){
    
    return 0;
}