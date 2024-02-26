#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/queue-reversal/1

queue<int> reverse(queue<int>q){
    stack<int> st;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        st.push(element);
    }

    while(!st.empty()){
        int element = st.top();
        st.pop();
        q.push(element);
    }
    return q;
}

int main(){
    queue<int>q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    
    q = reverse(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}