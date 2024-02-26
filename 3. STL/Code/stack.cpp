#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> s;

    s.push("rahul");
    s.push("anwala");
    s.push("lichana");

    cout<<"Top element : "<<s.top()<<endl;
    s.pop();
    cout<<"Top element : "<<s.top()<<endl;

    cout<<"Size of stack : "<<s.size()<<endl;

    return 0;
}