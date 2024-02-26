#include <bits/stdc++.h>
using namespace std;

bool getbit(int n, int i)
{
    return (n & (1 << i)) != 0;
}

void setbit(int &n, int i)
{
    n = n | (1 << i);
}

void clearbit(int &n, int i)
{
    int num = ~(1 << i);
    n = n & num;
}

void updatebit(int &n, int i, int val)
{
    int num = ~(1 << i);
    n = n & num;

    n = n | (val << i);
}

int main()
{
    cout << getbit(5, 2) << endl;

    int n = 5;
    setbit(n, 1);
    cout << n << endl;

    n = 5;
    clearbit(n, 2);
    cout << n << endl;

    n = 5;
    updatebit(n, 1, 1);
    cout << n << endl;

    return 0;
}