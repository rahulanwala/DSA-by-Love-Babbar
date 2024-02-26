#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1

bool isPossible(int a[], int n, int mid, int k)
{ 
    int cowct = 0;  
    int lastct = a[0];
    for (int i = 0; i < n; i++)
    {
        if ((a[i] - lastct) >= mid)
        {
            cowct++;
            if (cowct == k)
            {
                return true;
            }
            lastct = a[i];
        } 
    }
    return false;
}

int aggressiveCows(int a[], int n, int k)
{ 
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(a, n, mid, k))
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

int main()
{
    int a[5] = {4, 2, 1, 3, 6};
    sort(a, a + 5);
    cout << "Answer is : " << aggressiveCows(a, 5, 2) << endl;
    return 0;
}