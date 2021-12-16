#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
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

    void insertWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
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
            if (root->isTerminal)
                return true;
            else
                return false;
        }

        int wordIndex = word[0] - 'a';
        if (root->children[wordIndex] != NULL)
        {
            return searchWordHelper(root->children[wordIndex], word.substr(1));
        }
        else
        {
            cout << "Returning Early" << endl;
            return false;
        }
    }

    void removeWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int wordIndex = word[0] - 'a';
        if (root->children[wordIndex] != NULL)
        {
            removeWordHelper(root->children[wordIndex], word.substr(1));
        }
        else
        {
            cout << "Word Trying to delete doesn't exist" << endl;
            return;
        }

        TrieNode *toRemove = root->children[wordIndex];
        if (toRemove->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (toRemove->children[i] != NULL)
                    return;
            }
            root->children[wordIndex] = NULL;
            delete toRemove;
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

    void removeWord(string word)
    {
        removeWordHelper(root, word);
    }
};