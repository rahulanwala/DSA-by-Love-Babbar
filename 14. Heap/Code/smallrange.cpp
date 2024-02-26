#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=1

class node
{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int column)
    {
        this->data = data;
        i = row;
        j = column;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    } 
};
int kSorted(vector<vector<int>> &arr, int k, int n)
{
    // Write your code here.
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        int ele = arr[i][0];
        mini = min(mini, ele);
        maxi = max(maxi, ele);

        minHeap.push(new node(ele, i, 0));
    }

    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if ((maxi - mini) < (end - start))
        {
            start = mini;
            end = maxi;
        }

        int i = temp->i;
        int j = temp->j;

        if (j + 1 < n)
        {
            maxi = max(maxi, arr[i][j + 1]);

            minHeap.push(new node(arr[i][j + 1], i, j + 1));
        }
        else
        {
            break;
        }
    }

    return (end - start + 1);
}

int main()
{
    vector<vector<int>>arr = {{1,10,11},{2,3,20},{5,6,12}};
    int k=3;
    int n=3;

    cout<<"Smallest range in k list = "<<kSorted(arr,k,n)<<endl;
    return 0;
}