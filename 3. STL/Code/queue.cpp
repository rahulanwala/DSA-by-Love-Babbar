#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;

    q.push("rahul");
    q.push("anwala");
    q.push("lichana");

    cout<<"First element : "<<q.front()<<endl;
    q.pop();
    cout<<"First element : "<<q.front()<<endl;
    
    cout<<"Size : "<<q.size()<<endl;
    cout<<"------------------------"<<endl;


    // max heap
    priority_queue<int> maxi;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    // min heap
    priority_queue<int,vector<int>,greater<int>> mini;

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    n = mini.size();
    for(int i=0; i<n; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    
    return 0;
}