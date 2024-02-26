#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> pair1 = make_pair("rahul", 3);
    m.insert(pair1);

    // 2
    pair<string, int> pair2("name", 1);

    // 3
    m["mera"] = 1;
    m["mera"] = 2; // update ho jayega

    // search
    cout << m["mera"] << endl;
    cout << m.at("rahul") << endl;

    // cout<<m.at("unknown")<<endl;   // --give error
    cout << m["unknown"] << endl;
    cout << m.at("unknown") << endl;

    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("rahul")<<endl;

    m.erase("name");
    cout<<m.size()<<endl;

    // iterate
    unordered_map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}