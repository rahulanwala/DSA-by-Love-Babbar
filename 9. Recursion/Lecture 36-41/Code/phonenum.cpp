#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= digit.size())
    {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.size(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back(); // Backtracking
    }
}

int main()
{
    string digit = "23";

    vector<string> ans;
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digit, output, 0, ans, mapping);

    for (auto fa : ans)
    {
        cout << "{" << fa << "}"
             << ", ";
    }
    cout << endl;
    return 0;
}