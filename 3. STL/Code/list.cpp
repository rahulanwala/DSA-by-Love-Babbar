#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);

    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> m = l;
    return 0;
}