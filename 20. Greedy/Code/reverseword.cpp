//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        
        string ans="";
        string temp="";
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='.'){
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans.push_back('.');
                temp = "";
            }else{
                temp.push_back(s[i]);
            }
        }
        
        reverse(temp.begin(),temp.end());
        ans += temp;
    return ans;
    } 
    
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends