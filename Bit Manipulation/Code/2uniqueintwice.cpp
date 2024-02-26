#include<bits/stdc++.h>
using namespace std;

bool getbit(int n, int i)
{
    return (n & (1 << i)) != 0;
}

void unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum ^= arr[i];
    }

    int temp = xorsum; 
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit = xorsum&1;
        pos++;
        xorsum = xorsum>>1;
    }

    int newxor=0;
    for(int i=0;i<n;i++){
        if(getbit(arr[i],pos-1)){
            newxor ^= arr[i];
        }
    }

    cout<<newxor<<endl;
    cout<<(temp^newxor)<<endl;
}

int main(){
    int arr[] = {2,4,6,7,4,5,6,2};
    unique(arr,8);
    return 0;
}