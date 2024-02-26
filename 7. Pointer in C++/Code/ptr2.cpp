#include<bits/stdc++.h>
using namespace std;

int main(){
    // pointer to int is created and pointing to some garbage address
    // Not define like --> int *p;
    // define --> int *p = 0;

    int i=5;
    int *q = &i;

    cout<<q<<endl<<*q<<endl;

    int *p = 0;
    p = &i;

    cout<<p<<endl<<*p<<endl;

    // Both will give same output

    return 0;
}