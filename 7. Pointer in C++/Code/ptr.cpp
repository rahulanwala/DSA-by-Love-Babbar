#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 5;
    cout<<num<<endl;

    // address of Operator - &

    cout<<"address of num is "<<&num<<endl;

    int *ptr = &num;

    cout<<"Address is : "<<ptr<<endl;
    cout<<"Value is : "<<*ptr<<endl;

    double d = 4.3;
    double *p2 = &d;

    cout<<"Address is : "<<p2<<endl;
    cout<<"Value is : "<<*p2<<endl;

    cout<<"Size of integer is : "<<sizeof(num)<<endl;
    cout<<"Size of pointer(ptr) is : "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer is(p2) : "<<sizeof(p2)<<endl;


    return 0;
}