#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

string lcpIte(vector<string> &arr, int n)
{
    string ans = "";

    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for (int j = 1; j < n; j++)
        {
            if (ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }

    return ans;
}

// Approach 2********

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{ 
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';

                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

int main()
{
    vector<string> arr = {"coding", "codezen", "codingninga", "coders"};
    int n = 4;

    cout << "Longest common prefix = " << lcpIte(arr, n) << endl;

    Trie *t = new Trie('\0');

    for (int i = 0; i < n; i++)
    {
        t->insert(arr[i]);
    }

    string ans = "";
    string str = arr[0];
    t->lcp(str, ans);
    cout << "Longest common prefix = " << ans << endl;
    return 0;
}