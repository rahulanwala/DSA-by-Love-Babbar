#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxprofit=0;
        for(int i=1;i<n; i++){
            int diff = prices[i]-mini;
            maxprofit = max(maxprofit,diff);
            mini = min(mini,prices[i]);
        }
        return maxprofit;
    }
};
int main(){
    
    return 0;
}