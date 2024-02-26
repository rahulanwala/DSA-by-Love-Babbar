#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string> m;

    m[1] = "rahul";
    m[2] = "anwala";
    m[3] = "lichana";
    m.insert({5,"kuchaman"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding 13 : "<<m.count(13)<<endl;
    
    return 0;
}