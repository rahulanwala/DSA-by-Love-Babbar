#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;

    vector<int> a(5,1); //--> {1,1,1,1,1}
    vector<int> b(a); //--> {1,1,1,1,1}

    cout<<"Capacity -- "<<v.capacity()<<endl;
    
    v.push_back(1);
    cout<<"Capacity -- "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity -- "<<v.capacity()<<endl;

    v.push_back(3);  
    cout<<"Capacity -- "<<v.capacity()<<endl;
    cout<<"Size -- "<<v.size()<<endl;

    cout<<"Element at 2nd Index : "<<v.at(2)<<endl;

    cout<<"Before pop : ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop : ";
    for(int i:v){
        cout<<i<<" ";
    }

    v.clear();
    return 0;
}