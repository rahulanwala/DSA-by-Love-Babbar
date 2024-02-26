#include <bits/stdc++.h>
using namespace std;

bool checkpali(string s, int i, int j)
{
    if (i > j)
        return 1;

    if (s[i] != s[j])
        return 0;
    else
        return checkpali(s, i + 1, j - 1);
}

int main()
{
    string s = "racecar";

    if (checkpali(s, 0, s.size() - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}