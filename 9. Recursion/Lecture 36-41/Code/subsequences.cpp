#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/33hi3MB


void subsequences(string input, string output, int index, vector<string> &ans)
{
    if (index >= input.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subsequences(input, output, index + 1, ans);

    // include
    char element = input[index];
    output.push_back(element);
    subsequences(input, output, index + 1, ans);
}

int main()
{
    string s = "abc";

    vector<string> ans;
    string output = "";

    subsequences(s, output, 0, ans);

    for (auto st : ans)
    {
        cout <<"{"<< st <<"}"<< ", ";
    }
    cout<<endl;
    return 0;
}