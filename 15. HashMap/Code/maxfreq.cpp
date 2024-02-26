#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=1

int maximumFrequency(int arr[], int n)
{
    //Write your code here
    unordered_map<int,int>m;

    int maxfre=0;
    int ans=0;

    for(int i=0;i<n; i++){
        m[arr[i]]++;
        maxfre = max(maxfre,m[arr[i]]);
    }

    for(int i=0;i<n; i++){
        if(maxfre==m[arr[i]]){
            ans = arr[i];
            break;
        }
    }

    return ans;
}

int main(){
    int arr[5] = {1,2,2,1,1};
    int n=5;

    cout<<maximumFrequency(arr,n)<<endl;
    return 0;
}