#include<bits/stdc++.h>
using namespace std;

void reversestr(string& s,int st,int ed){

    if(st>ed){
        return ;
    }

    swap(s[st],s[ed]);
    st++;
    ed--;
    reversestr(s,st,ed);
}

int main(){
    string s = "abcde";

    reversestr(s,0,s.size()-1);
    cout<<"Reverse string is = "<<s<<endl;
    return 0;
}