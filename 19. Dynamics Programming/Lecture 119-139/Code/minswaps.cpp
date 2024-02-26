#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/submissions/

class Solution
{
    int rec(vector<int> &nums1, vector<int> &nums2, int ind, int swapped)
    {
        if (ind >= nums1.size())
        {
            return 0;
        }

        int prev1 = nums1[ind - 1];
        int prev2 = nums2[ind - 1];

        if (swapped == 1)
        {
            swap(prev1, prev2);
        }

        int ans = INT_MAX;
        // no swap
        if (nums1[ind] > prev1 && nums2[ind] > prev2)
        {
            ans = rec(nums1, nums2, ind + 1, 0);
        }

        // swap
        if (nums1[ind] > prev2 && nums2[ind] > prev1)
        {
            ans = min(ans, 1 + rec(nums1, nums2, ind + 1, 1));
        }

        return ans;
    }

    int mem(vector<int> &nums1, vector<int> &nums2, int ind, bool swapped, vector<vector<int>> &dp)
    {
        if (ind >= nums1.size())
        {
            return 0;
        }

        if (dp[ind][swapped] != -1)
        {
            return dp[ind][swapped];
        }

        int prev1 = nums1[ind - 1];
        int prev2 = nums2[ind - 1];

        if (swapped == 1)
        {
            swap(prev1, prev2);
        }

        int ans = INT_MAX;
        // no swap
        if (nums1[ind] > prev1 && nums2[ind] > prev2)
        {
            ans = mem(nums1, nums2, ind + 1, 0, dp);
        }

        // swap
        if (nums1[ind] > prev2 && nums2[ind] > prev1)
        {
            ans = min(ans, 1 + mem(nums1, nums2, ind + 1, 1, dp));
        }

        return dp[ind][swapped] = ans;
    }

    int tab(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

        for (int ind = nums1.size() - 1; ind >= 1; ind--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {

                int prev1 = nums1[ind - 1];
                int prev2 = nums2[ind - 1];

                if (swapped == 1)
                {
                    swap(prev1, prev2);
                }

                int ans = INT_MAX;
                // no swap
                if (nums1[ind] > prev1 && nums2[ind] > prev2)
                {
                    ans = dp[ind + 1][0];
                }

                // swap
                if (nums1[ind] > prev2 && nums2[ind] > prev1)
                {
                    ans = min(ans, 1 + dp[ind + 1][1]);
                }

                dp[ind][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int space(vector<int> &nums1, vector<int> &nums2)
    {
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for (int ind = nums1.size() - 1; ind >= 1; ind--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {

                int prev1 = nums1[ind - 1];
                int prev2 = nums2[ind - 1];

                if (swapped == 1)
                {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                int ans = INT_MAX;
                // no swap
                if (nums1[ind] > prev1 && nums2[ind] > prev2)
                {
                    ans = noswap;
                }

                // swap
                if (nums1[ind] > prev2 && nums2[ind] > prev1)
                {
                    ans = min(ans, 1 + swap);
                }

                if (swapped == 1)
                {
                    currswap = ans;
                }
                else
                {
                    currnoswap = ans;
                }
            }
            swap = currswap;
            noswap = currnoswap;
        }

        return min(swap, noswap);
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int swapped = 0;

        // return rec(nums1,nums2,1,swapped);

        // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));

        // return mem(nums1,nums2,1,swapped,dp);

        // return tab(nums1,nums2);

        return space(nums1, nums2);
    }
};

int main()
{

    return 0;
}