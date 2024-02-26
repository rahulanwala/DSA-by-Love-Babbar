#include <bits/stdc++.h>
using namespace std;

bool solve(int n)
{
    if (n == 0)
    {
        return false;
    }
    if (((n & (n - 1)) == 0))
    {
        return true;
    }

    return false;
}

int main()
{
    cout << solve(4) << endl;
    cout << solve(5) << endl;
    return 0;
}