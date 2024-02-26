#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

queue<int> modify(queue<int>q,int k){
    // fetch k element from q and put into stack
    stack<int>st;

    for(int i=0; i<k; i++){
        int val=q.front();
        q.pop();
        st.push(val);
    }

    // fetch element from stack and put into q
    while(!st.empty()){
        int val = st.top();
        st.pop();
        q.push(val);
    }

    int n = q.size()-k;

    while (n--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    q = modify(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}