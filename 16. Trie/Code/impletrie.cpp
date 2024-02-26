#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
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

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
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
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
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
            return false;
        }

        // recursion
        return prefixUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("cde");

    return;
}