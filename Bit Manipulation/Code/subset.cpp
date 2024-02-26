#include<bits/stdc++.h>
using namespace std;

void subset(string s){
    int n = s.size();
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j))
            cout<<s[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    subset("abc");
    return 0;
}