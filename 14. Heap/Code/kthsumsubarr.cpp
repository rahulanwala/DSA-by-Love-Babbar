#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0

int usingMinHeap(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else if (sum > pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }

    return pq.top();
}

int main()
{
    int arr[4] = {4, 3, 2, 6};
    int n = 4;
    int k = 3;

    vector<int> sumStore;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    cout << "K-th largest sum subarray = " << sumStore[sumStore.size() - k] << endl;
    cout << "K-th largest sum subarray = " << usingMinHeap(arr, n, k) << endl;

    return 0;
}