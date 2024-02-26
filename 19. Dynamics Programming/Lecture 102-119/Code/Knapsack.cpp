#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

int rec(vector<int> weight, vector<int> value, int i,int maxw){
	if(i==0){
		if(weight[0]<=maxw){
			return value[0];
		}else{
			return 0;
		}
	}

	int inc=0;
	if(weight[i]<=maxw){
		inc = value[i] + rec(weight,value,i-1,maxw-weight[i]);
	}

	int exc = rec(weight,value,i-1,maxw);

	int ans = max(inc,exc);

	return ans;
}

int mem(vector<int> weight, vector<int> value, int i,int maxw,vector<vector<int>>&dp){
	if(i==0){
		if(weight[0]<=maxw){
			return value[0];
		}else{
			return 0;
		}
	}

	if(dp[i][maxw]!=-1){
		return dp[i][maxw];
	}

	int inc=0;
	if(weight[i]<=maxw){
		inc = value[i] + mem(weight,value,i-1,maxw-weight[i],dp);
	}

	int exc = mem(weight,value,i-1,maxw,dp);

	dp[i][maxw] = max(inc,exc);

	return dp[i][maxw];
}

int tab(vector<int> weight, vector<int> value, int n, int maxw){
	vector<vector<int>>dp(n,vector<int>(maxw+1,0));
	
	for(int w=weight[0];w<=maxw;w++){
		if(weight[0]<=maxw){
			dp[0][w] = value[0];
		}else{
			dp[0][w] = 0;
		}
	}

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxw;w++){
			int inc = 0;
			if(weight[i]<=w){
				inc = value[i] + dp[i-1][w-weight[i]];
			}

			int exc = dp[i-1][w];

			dp[i][w] = max(inc,exc);
		}
	}

	return dp[n-1][maxw];

}

int space(vector<int> weight, vector<int> value, int n, int maxw){
	vector<int>prev(maxw+1,0);
	vector<int>curr(maxw+1,0);
	
	for(int w=weight[0];w<=maxw;w++){
		if(weight[0]<=maxw){
			prev[w] = value[0];
		}else{
			prev[w] = 0;
		}
	}

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxw;w++){
			int inc = 0;
			if(weight[i]<=w){
				inc = value[i] + prev[w-weight[i]];
			}

			int exc = prev[w];

			curr[w] = max(inc,exc);
		}
		prev = curr;
	}

	return prev[maxw];

}

int opti(vector<int> weight, vector<int> value, int n, int maxw){
	vector<int>curr(maxw+1,0);
	
	for(int w=weight[0];w<=maxw;w++){
		if(weight[0]<=maxw){
			curr[w] = value[0];
		}else{
			curr[w] = 0;
		}
	}

	for(int i=1;i<n;i++){
		for(int w=maxw;w>=0;w--){
			int inc = 0;
			if(weight[i]<=w){
				inc = value[i] + curr[w-weight[i]];
			}

			int exc = curr[w];

			curr[w] = max(inc,exc);
		}
	}

	return curr[maxw];

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxw) 
{
	// Write your code here

	// return rec(weight,value,n-1,maxw);

	// vector<vector<int>>dp(n,vector<int>(maxw+1,-1));

	// return mem(weight,value,n-1,maxw,dp);

	// return tab(weight,value,n,maxw);

	// return space(weight,value,n,maxw);

	return opti(weight,value,n,maxw);

}

int main(){
    
    return 0;
}