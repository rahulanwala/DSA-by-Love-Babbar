#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> firstNegative(vector<long long> v, long long n, long long k)
{
    deque<long long> dq;
    vector<long long> ans;

    // process first window of k size
    for (int i = 0; i < k; i++)
    {
        if (v[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(v[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process the remaining window
    for (int i = k; i < n; i++)
    {
        // removal
        if (!dq.empty() && (i - dq.front() >= k))
        {
            dq.pop_front();
        }

        // addition
        if (v[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(v[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    vector<long long> v = {-8, 2, 3, -6, 10};

    int n = 5;
    int k = 2;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<long long> ans = firstNegative(v, n, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}