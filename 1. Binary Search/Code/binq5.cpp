#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

long long int findsqrt(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {

        long long int square = mid * mid;

        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {  
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morepre(int n, int pre, int t){
    double ans = t;
    double factor = 1;

    for(int i=0; i<pre; i++){
        factor = factor/10;
        for(double j=ans; j*j<n; j+=factor){
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int a;
    cout << "Enter a : ";
    cin >> a;
    int t = findsqrt(a);
    cout << "Square root of " << a << " is : " << morepre(a,3,t) << endl;
    return 0;
}