#include <bits/stdc++.h>
using namespace std;

vector<long long> prime;

void sieve(long long n)
{
    int ct = 0;
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (long long j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void segsieve(int l, int h)
{ 
    long long sq = sqrt(h);
    sieve(sq);

    vector<bool> isPrime(h - l + 1, true);

    for (long long p : prime)
    {
        long long sm = (l / p) * p;
        if (sm < l)
        {
            sm += p;
        }
        for (long long m = sm; m <= h; m += p)
        {
            isPrime[m - l] = false;
        }
    }
    for (long long i = l; i <= h; i++)
    {
        if (isPrime[i - l] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int l = 5;
    int h = 9;

    segsieve(3, 9);

    return 0;
}