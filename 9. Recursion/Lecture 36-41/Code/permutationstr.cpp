#include <bits/stdc++.h>
using namespace std;
//  https://leetcode.com/problems/permutations/


void permutation(string &str, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        ans.push_back(str);  
        return;
    }

    for (int i = index; i < str.size(); i++)
    {
        swap(str[i], str[index]);
        permutation(str, index + 1, ans);
        swap(str[i], str[index]); // Backtracking
    }
}

int main()
{
    string str = "abc";

    vector<string> ans;

    permutation(str, 0, ans);

    for (auto fa : ans)
    {
        cout << "{" << fa << "}"
             << ", ";
    }
    cout << endl;
    return 0;
}