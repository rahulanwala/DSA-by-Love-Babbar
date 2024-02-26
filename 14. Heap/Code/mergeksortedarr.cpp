#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

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

vector<int> mergeSortedArray(vector<vector<int>> &arr, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if (j + 1 < arr[i].size())
        {
            node *next = new node(arr[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{2, 3, 4, 6}, {2, 4, 7}, {3, 5}};
    int k = 3;

    vector<int> ans = mergeSortedArray(arr, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}