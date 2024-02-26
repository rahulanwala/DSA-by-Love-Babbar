#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

string firstNonRepeating(string s)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;

        q.push(s[i]);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string s = "aabc";

    cout << s << endl;
    cout << firstNonRepeating(s) << endl;
    return 0;
}