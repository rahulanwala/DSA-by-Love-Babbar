#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subsets/


void subsets(vector<int> input, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= input.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subsets(input, output, index + 1, ans);

    // include
    int element = input[index];
    output.push_back(element);
    subsets(input, output, index + 1, ans);
}

int main()
{
    vector<int> v = {1, 2, 3};

    vector<vector<int>> ans;
    vector<int> output={0};

    subsets(v, output, 0, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (auto fa : ans[i])
        {
            cout << fa << " ";
        }
        cout << endl;
    }
    return 0;
}