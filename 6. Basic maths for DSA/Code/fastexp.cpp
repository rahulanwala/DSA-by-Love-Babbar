#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3peOT9i 

int m = 1e5;

int exp(int x, int n)
{
    int res = 1;

    while (n > 0)
    {
        if (n & 1) // odd
        {
            res = ((res) % m *1LL* (x) % m)%m;
        }
        x = ((x % m) *1LL* (x % m))%m;
        n = n >> 1; // (n/2)
    }
    return res;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << "a power b = " << exp(a, b) << endl;

    return 0;
}