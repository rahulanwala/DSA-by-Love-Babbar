#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int lefti = 2 * i;
            int righti = 2 * i + 1;

            if (lefti < size && arr[lefti] > arr[i])
            {
                swap(arr[i], arr[lefti]);
                i = lefti;
            }
            else if (righti < size && arr[righti] > arr[i])
            {
                swap(arr[i], arr[righti]);
                i = righti;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array : ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing the sorted array : ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "***Heap using Priority Queue***" << endl;
    priority_queue<int> pq;
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(2);

    cout << "Top element " << pq.top() << endl;
    pq.pop();
    cout << "Top element " << pq.top() << endl;
    cout << "Size = " << pq.size() << endl;


    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(3);
    minheap.push(5);
    minheap.push(2);

    cout << "Top element " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element " << minheap.top() << endl;
    cout << "Size = " << minheap.size() << endl;

    return 0;
}