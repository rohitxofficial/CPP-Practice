#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode *root;

    void insertWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return;
        }

        int wordIndex = word[0] - 'a';
        TrieNode *newNode;
        if (root->children[wordIndex] == NULL)
        {
            newNode = new TrieNode(word[0]);
            root->children[wordIndex] = newNode;
        }
        else
        {
            newNode = root->children[wordIndex];
        }

        insertWordHelper(newNode, word.substr(1));
    }

    bool searchWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        int wordIndex = word[0] - 'a';
        if (root->children[wordIndex] != NULL)
        {
            return searchWordHelper(root->children[wordIndex], word.substr(1));
        }
        else
        {
            return false;
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(string word)
    {
        insertWordHelper(root, word);
    }

    bool searchWord(string word)
    {
        return searchWordHelper(root, word);
    }
};

int main()
{
    int n;
    cin >> n;

    Trie patternMatching;

    for (int i = 0; i < n; i++)
    {
        string curr;
        cin >> curr;

        int stringLength = curr.size();
        for (int j = 0; j < stringLength; j++)
        {
            patternMatching.insertWord(curr.substr(j));
        }
    }

    string pattern;
    cin >> pattern;

    if (patternMatching.searchWord(pattern))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}