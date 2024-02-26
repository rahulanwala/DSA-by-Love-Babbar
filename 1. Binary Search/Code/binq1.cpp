#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1

int FirstOcc(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int LastOcc(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int a[5] = {0, 2, 3, 3, 5};

    int firstind = FirstOcc(a, 5, 3);
    cout << "Index of First Occurance is : " << firstind << endl;

    int lastind = LastOcc(a, 5, 3);
    cout << "Index of last Occurance is : " << lastind << endl;
    return 0;
}