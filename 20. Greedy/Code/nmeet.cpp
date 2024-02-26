#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(start[i], end[i]));
        }

        sort(v.begin(), v.end(), cmp);

        int cnt = 1;
        int st = v[0].first;
        int ed = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first > ed)
            {
                cnt++;
                ed = v[i].second;
            }
        }

        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
