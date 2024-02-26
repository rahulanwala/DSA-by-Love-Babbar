#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=5;
    int a = num;
    a++;
    cout<<num<<endl;
    // num will not change

    int *p = &num;
    (*p)++;
    cout<<num<<endl;
    // it will change

    // copying a pointer
    int *q = p;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;

    // important concept
    int i=3;
    int *t = &i;
    cout<<(*t)++<<endl;
    // *t = *t+1;
    cout<<t<<endl;
    t = t+1;
    cout<<t<<endl;

    return 0;
}