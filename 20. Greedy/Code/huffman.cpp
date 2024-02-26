//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

class node{
    public:
    int data;
    node*left;
    node*right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class cmp{
    public:
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
};

class Solution
{
    void traverse(node*root,vector<string>&ans,string temp){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            return;
        }
        
        traverse(root->left,ans,temp+'0');
        traverse(root->right,ans,temp+'1');
    }
	public:
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    priority_queue<node*,vector<node*>,cmp>pq;
		    
		    for(int i=0;i<n;i++){
		        node* temp = new node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1){
		        node*left = pq.top();
		        pq.pop();
		        
		        node*right = pq.top();
		        pq.pop();
		        
		        node*newNode = new node(left->data+right->data);
		        
		        newNode->left = left;
		        newNode->right = right;
		        
		        pq.push(newNode);
		    }
		    
		    node*root = pq.top();
		    vector<string>ans;
		    string temp = "";
		    traverse(root,ans,temp);
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends