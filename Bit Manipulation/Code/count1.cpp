#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int cnt=0;
    while(n){
        cnt++;
        n = n&(n-1);
    }

    return cnt;
}

int main(){
    cout<<count(19)<<endl;
    return 0;
}