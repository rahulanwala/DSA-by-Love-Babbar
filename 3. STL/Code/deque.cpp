#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout<<i<<" ";
    } // 2 1
    cout<<endl;

    cout<<"Print first index element : "<<d.at(1)<<endl; // 1

    cout<<"Front : "<<d.front()<<endl<<"Back : "<<d.back()<<endl;

    cout<<"Empty or not : "<<d.empty()<<endl;

    cout<<"Before erase : ";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    d.erase(d.begin(),d.begin()+1);
    
    cout<<"After erase : ";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}