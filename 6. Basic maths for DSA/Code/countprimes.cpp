#include <bits/stdc++.h>
using namespace std;
// //leetcode.com/problems/count-primes/ 

int countprime(int n)
{
    int ct = 0;
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            ct++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return ct;
}

int main()
{
    int n = 10;

    cout << countprime(n) << endl;

    return 0;
}