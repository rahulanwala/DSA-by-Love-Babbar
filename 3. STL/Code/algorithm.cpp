#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 5 "<<binary_search(v.begin(),v.end(),5)<<endl;

    cout<<"Upper bound of  6 "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    cout<<"Lower bound of 6 "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a=3,b=5;
    cout<<"max = "<<max(a,b)<<endl;
    cout<<"min = "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a = "<<a<<"b = "<<b<<endl;

    string s = "abcd";
    cout<<"Before reversing : "<<s<<endl;
    
    reverse(s.begin(),s.end());
    cout<<"After reversing : "<<s<<endl;
    return 0;
}