//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Item
{
    int value;
    int weight;
};

class Solution
{
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {
        return a.first > b.first;
    }

public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here

        vector<pair<double, Item>> v;

        for (int i = 0; i < n; i++)
        {
            double val = ((1.0) * arr[i].value) / arr[i].weight;
            v.push_back(make_pair(val, arr[i]));
        }

        sort(v.begin(), v.end(), cmp);

        double total = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i].second.weight > W)
            {
                total += W * v[i].first;
                W = 0;
            }
            else
            {
                total += v[i].second.value;
                W -= v[i].second.weight;
            }
        }

        return total;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends